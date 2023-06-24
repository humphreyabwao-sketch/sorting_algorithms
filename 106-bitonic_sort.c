#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stdbool.h>

/**
* swap - Swaps two elements in the array
* @a: First element
* @b: Second element
*/
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
* compare_and_swap - Compares and swaps two elements
* @array: The array to be sorted
* @i: Index of the first element
* @j: Index of the second element
* @dir: Direction of comparison (true for ascending, false for descending)
*/
void compare_and_swap(int *array, int i, int j, bool dir)
{
if ((array[i] > array[j] && dir) || (array[i] < array[j] && !dir))
{
swap(&array[i], &array[j]);
printf("Result [%d/%d] (%s):\n", j + 1, i + 1, dir ? "UP" : "DOWN");
print_array(array, i + 1);
}
}

/**
* bitonic_merge - Performs a bitonic merge on the given array
* @array: The array to be sorted
* @low: Starting index of the sequence
* @count: Number of elements in the sequence
* @dir: Direction of comparison (true for ascending, false for descending)
*/
void bitonic_merge(int *array, int low, int count, bool dir)
{
if (count > 1)
{
int k = count / 2;
for (int i = low; i < low + k; i++)
compare_and_swap(array, i, i + k, dir);

bitonic_merge(array, low, k, dir);
bitonic_merge(array, low + k, k, dir);
}
}

/**
* bitonic_sort_recursive - Performs a bitonic sort
* @array: The array to be sorted
* @low: Starting index of the sequence
* @count: Number of elements in the sequence
* @dir: Direction of comparison (true for ascending, false for descending)
*/
void bitonic_sort_recursive(int *array, int low, int count, bool dir)
{
if (count > 1)
{
int k = count / 2;

printf("Merging [%d/%d] (%s):\n", count, count, dir ? "UP" : "DOWN");
print_array(array, count);

bitonic_sort_recursive(array, low, k, true);
bitonic_sort_recursive(array, low + k, k, false);

bitonic_merge(array, low, count, dir);
}
}

/**
* bitonic_sort - Sorts an array of integers in ascending order
* @array: The array to be sorted
* @size: The size of the array
*/
void bitonic_sort(int *array, size_t size)
{
bitonic_sort_recursive(array, 0, size, true);
}

