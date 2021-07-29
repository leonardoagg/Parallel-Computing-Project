#include <iostream>
#include <mpi.h>
#include<math.h>
#include <fstream>
#include <vector>

/*
 * Method used to read the input data
 */
void readArray(std::string file, int size, std::vector<int>* arr)
{
    std::ifstream inFile;
    inFile.open(file);

    if (!inFile) {
        std::cout << "Unable to open file";
        MPI_Finalize();
        exit(1); // terminate with error
    }
    int i = 0;
    int x;
    // Fill the array with data
    while (inFile >> x) {
        arr->push_back(x);
        i++;
    }
    inFile.close();
}

// Swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// partition the array using last element as pivot
int partition (std::vector<int>* arr, int low, int high)
{
    int pivot = arr->at(high); // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr->at(j) < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr->at(i), &arr->at(j));
        }
    }
    swap(&arr->at(i + 1), &arr->at(high));
    return (i + 1);
}


//quicksort algorithm
void quickSort(std::vector<int>* arr, int low, int high)
{
    if (low < high)
    {
        //partition the array
        int pivot = partition(arr, low, high);

        //sort the sub arrays independently
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(int argc, char** argv) {

    int array_size, local_array_size, logp, median, pivot;
    std::vector<int> arr;

    double start,end;
    MPI_Status status;

 //   int taskId = 0;
    int rank, size; //rank = world_rank     size =  comm_sz

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

//    printf("Hello world from process %d of %d\n", rank, size);

    // Computing the log(P) for the  tasks' partition
    // Use round function in order to consider power of 2 processors
    logp = round(log(size)/ log(2));

   // printf("Number of steps of %d in process %d\n", logp,rank);

   // Master reads the file and saves the sequence
    if(rank == 0)
    {
         std::string file = argv[1];
         array_size = atoi(argv[2]);
         readArray(file, array_size, &arr);

         //std::cout << arr[10] << std::endl;
    }

    // Broadcast with the size of the array
    MPI_Bcast(&array_size, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // Size of the single process elements
    std::vector<int> local_arr(array_size), recv_buf(array_size), merge_buf(array_size);

    //Divide the sequence
    local_array_size = array_size/size;
    MPI_Scatter(arr.data(),local_array_size,MPI_INT,local_arr.data(),local_array_size,MPI_INT,0,MPI_COMM_WORLD);

    //Start time counting
    start= MPI_Wtime();

    // sort each local array
    quickSort(&local_arr,0,local_array_size);

    /* Create pairs of communicator in order to follow the algorithm
     * if P = 4 :
     * First iteration P0 P1 P2 P3
     *
     * Second iteration P0 - P2  / P1 - P3
     *
     */
    for(int iter = 0; iter < logp; iter++){
        // Processors with the same color work together
        int color = pow(2,iter)*rank/size;

        MPI_Comm new_comm;
        MPI_Comm_split(MPI_COMM_WORLD, color, size, &new_comm);
        int split_rank,sz;
        MPI_Comm_rank(new_comm,&split_rank);
        MPI_Comm_size(new_comm,&sz);

        // Process 0 broadcast its median
        median = local_arr[local_array_size/2];
        MPI_Bcast(&median, 1, MPI_INT, 0, new_comm);

        // Each process in upper half will swap its low list with high list of corresponding lower half
        // Search the pivot into the sub-sequence
        pivot = 0;
        while(pivot < local_array_size && local_arr[pivot] < median)
        {
            pivot++;
        }

        int pair_process = (split_rank+(sz>>1))%sz;
        printf("process %d color %d\n", rank, pair_process);

    }


    /*
    if(rank == 3)
    {
        for(int i = 0 ; i< local_array_size;i++)
              std::cout << local_arr[i] << std::endl;
    }
*/



    MPI_Finalize();
    return 0;
}
