/*
    Bucket Sorting Algorithm. 

        Reads from a file in the same directory as the program, which is read from std input parameter argv[1]. The file contains 
        numbers of the format "%d ", where the first is the count of how many numbers are in the unsorted list, 
        followed by the numbers in the unsorted list. 

*/
#include <stdio.h>
#include <stdlib.h>


/*
    Bucket Sort: returns an integer pointer array
    @param size the integer size of the array of unsorted numbers. 
    @param array the unsorted pointer array

*/
int* bucket_sort(int size, int* array)
{

    int* buckets = calloc(size, sizeof(int));
    int* sorted = calloc(size, sizeof(int));

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        if(*(array+j) == i)
        {
            (*(buckets+i)) += 1;
        }
    }

    int index = 0;
    for(int i = 0; i < size; i++)
    {
        printf("|%d|\t", *(buckets+i)); // print the buckets 
        int count = *(buckets+i);
        index+=count;
        for(int j = count; j > 0; j--)
        {
            *(sorted+index-j) = i;
        }
    }

    printf("\n");
    return(sorted);

}


/* driver entry poinr/ main method */
int main(int argc, char* argv[])
{

    /*
        The program reads in numbers from the argv[1] file placed in its directory.
    */  
    FILE *fptr = fopen(argv[1],"r");

    /*
        Program will exit on file DNE.
    */
    if(fptr == NULL) 
    {
        printf("File \"%s\" Does Not Exist\n", argv[1]);
        return -1;
    }


    /*
        Size ( the number of numbers in the list ) is read in as the first number in the list.
    */
    int SIZE = 0;
    fscanf(fptr, "%d ", &SIZE); 

    /*
        Integer array to hold the number list.
    */
    int array[SIZE];

    printf("starting sorting program.\nreading unsorted array of size %d from %s.\n", SIZE, argv[1]);

    for(int i = 0 ; i < SIZE; i++)
    {
        fscanf(fptr, "%d ", &array[i]);
        printf("%d\t",array[i]);
    }

    // formatting for terminal output
    printf("\n");


    /*
        Creating a sorted array using bucket_sort
    */
    int *sorted = bucket_sort(SIZE, array);

    printf("sorted array as computed by bucket_sort algorithm.\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d\t", *(sorted+i));
    }

    // formatting for terminal output
    printf("\n");

    printf("program exit normal.\n");

    return 1;
}