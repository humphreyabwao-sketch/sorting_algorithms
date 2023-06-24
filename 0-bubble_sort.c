#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order using the
*               Bubble sort algorithm.
* @array: The array to be sorted.
* @size: The size of the array.
*/
void bubble_sort(int *array, size_t size)
{
size_t i, j;
int temp;

/* Check for valid input */
if (array == NULL || size < 2)
return;

/* Perform Bubble sort */
for (i = 0; i < size - 1; i++)
{
for (j = 0; j < size - i - 1; j++)
{
/* Swap adjacent elements if they are in the wrong order */
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;

/* Print the array after each swap */
print_array(array, size);
}
}
}
}
