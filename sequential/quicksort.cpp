#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <chrono>

using namespace std;

// Swap two elements
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
// partition the array using last element as pivot
int partition (vector<int>* arr, int low, int high)
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
void quickSort(vector<int>* arr, int low, int high)
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


void printArray(vector<int>* arr, int size)
{
    // output file creation
    ofstream outfile("orderedOutput.txt");

    // generation of txt with 1 number for each row
    for(int i = 0 ; i < size ; i++)
    {
        outfile << arr->at(i) << endl;
    }
    //close file
    outfile.close();
}

void readArray(string file, int size, vector<int>* arr)
{
    ifstream inFile;
    inFile.open(file);

    if (!inFile) {
        cout << "Unable to open file" << endl;
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

   
int main(int argc, char *argv[]) 
{ 
    string file = argv[1];

    cout << "Input path:" << file << endl;

    const int size = atoi(argv[2]);

    vector<int> arr;

    readArray(file, size, &arr);

    //clock_t tStart = clock();
    auto start = chrono::high_resolution_clock::now();

    quickSort(&arr, 0, size-1);

    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Time for quicksort execution: " << duration.count() / 1000000.0 << "s" << endl;

    printArray(&arr,size);
    
    return 0; 
}
