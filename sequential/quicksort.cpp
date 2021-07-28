#include <iostream>
#include <fstream>

using namespace std;


// Swap two elements
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
// partition the array using first element as pivot
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

   
//quicksort algorithm
void quickSort(int arr[], int low, int high) 
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
   
void printArray(int arr[], int size) 
{ 

  // output file creation
  ofstream outfile("orderedOutput.txt");

  // generation of txt with 1 number for each row
  for(int i = 0 ; i < size ; i++)
  {
    outfile << arr[i] << endl;
  }

  //close file
  outfile.close();
      
} 

void readArray(string file, int size, int *arr) 
{ 

    ifstream inFile;
    inFile.open(file);

    if (!inFile) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }

    int i = 0;

    int x;

    while (inFile >> x) {
        arr[i] = x;
        i++;
    }
    
    inFile.close();
} 
   
int main(int argc, char *argv[]) 
{ 
    string file = argv[1];

    cout << file << endl;

    const int size = atoi(argv[2]);

    int arr[size];

    readArray(file, size, arr);

    quickSort(arr, 0, size-1); 
    
    printArray(arr,size);
    
    return 0; 
}