/*
    Bryce Jackson
    Quick sort algorithm
*/
#include <stdlib.h> 
#include <stdio.h>

/*
    A function to swap two elements in an array.
*/
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

/* sourced from geeksforgeeks.com
This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot 
*/
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

/*
    Quicksort algorithm inspired by geeksforgeeks.com
*/
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


/*
    A method to print an array.
*/
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//main method
int main(int argc, char *argv[])
{
    FILE *fptr = fopen(argv[1],"r");
    if(fptr == NULL){ printf("file not found ERROR.\n"); return -1; }
    int size = 0; 
    fscanf(fptr, "%d ", &size);

    //create array for input
    int arr[size];

    for(int i = 0; i < size; i++)
    {
        fscanf(fptr, "%d ", &arr[i]);
    }


    printf("Before sorting:\n");
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printf("After sorting:\n");
    printArray(arr, size);
    return 1; // return 1 when end has been reached. 
}