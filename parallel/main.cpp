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
