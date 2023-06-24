#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * prints the array after each time you swap two elements
 *
 * @array: array of integers to be sorted
 * @size: number of integers in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, j_min;
	int temp;

	/* An array does not need to be sorted if its size is less than 2 */
	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		j_min = i;

		for (j = i + 1; j < size; j++)
		{
			/* find the smallest integer in the rest of the array */
			if (array[j] < array[j_min])
				j_min = j;
		}

		/* put the smallest value in the beginning of the unsorted part */
		if (j_min != i)
		{
			temp = array[i];
			array[i] = array[j_min];
			array[j_min] = temp;

			/* print the array */
			print_array(array, size);
		}
	}
}
