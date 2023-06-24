#include <stdio.h>
#include "sort.h"

/**
* swap - Swaps two integers
* @a: First integer
* @b: Second integer
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* hoare_partition - Performs the Hoare partition scheme
* @array: Array to be sorted
* @low: Starting index of the partition
* @high: Ending index of the partition
*
* Return: Index of the pivot element
*/
int hoare_partition(int *array, int low, int high)
{
int pivot = array[high];
int i = low - 1;
int j = high + 1;

while (1)
{
do {
i++;
} while (array[i] < pivot);

do {
j--;
} while (array[j] > pivot);

if (i >= j)
return (j);

swap(&array[i], &array[j]);
print_array(array, high - low + 1);
}
}

/**
* quicksort_hoare - Recursive function to sort an array using Quick Sort
* @array: Array to be sorted
* @low: Starting index of the partition
* @high: Ending index of the partition
*/
void quicksort_hoare(int *array, int low, int high)
{
int pivot;

if (low < high)
{
pivot = hoare_partition(array, low, high);
quicksort_hoare(array, low, pivot);
quicksort_hoare(array, pivot + 1, high);
}
}

/**
* quick_sort_hoare - Sorts an array of integers in ascending order using
*                    the Quick sort algorithm (Hoare partition scheme)
* @array: Array to be sorted
* @size: Size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quicksort_hoare(array, 0, size - 1);
}
