/*
* created by: Bryce Jackson
* insertion sort algorithm using doubly linked list structure (previous and next links)
*
*/
#include <stdio.h>
#include <stdlib.h>

/*
	Insertion sort algorithm- sorts the array which is provided as the second parameter. 
	The first paramether is the size of the array to be sorted. 
*/
void insertion_sort(int size, int array[])
{
	int value = 0;
	int j = 0;
	for(int i = 1; i < size; i++)
	{
		value = array[i];
		j = i-1;
		while(j>=0 && array[j] > value)
		{
			array[j+1] = array[j];
			j = j - 1; 
		}
		array[j + 1] = value;
	}
}

int main(int argc, char *argv[])
{	

	printf("starting sorting program. ");
	/*
		Create file pointer, also check for null file. (exit on file does not exist)
	*/
	FILE *fptr = fopen(argv[1], "r");
	if(fptr == NULL) 
    {
        printf("File \"%s\" Does Not Exist\n", argv[1]);
        return -1;
    }


	/*
		Get array size from first integer stored in fptr  with format "%d "
	*/
	int size = 0; 
	fscanf(fptr, "%d ", &size);
	int array[size]; // create array of specified size.

	printf("reading array of size %d from %s.\n",size, argv[1]);
	for(int i = 0; i < size; i++)
	{
		fscanf(fptr, "%d ", &array[i]);
	}

	// print the unsorted array
	for(int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	printf("\n");

	/*
		Perform the insertion sort algorithm on the array
	*/
	insertion_sort(size, array);


	printf("sorted array as computed by insertion_sort algorithm.\n");
	// print the aorted array
	for(int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

printf("program exit normal.\n");
return 0; 
}


