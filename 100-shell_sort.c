#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending,
 * order using the Shell sort algorithm, using the Knuth sequence.
 *
 * Use the sequence n+1 = n * 3 + 1
 * 1, 4, 13, 40, 121, ...
 *
 * @array: pointer to array to sort.
 * @size: size of array.
 *
 * Return: No return.
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t inner, outer;
	int temp_val;
	size_t gap = 1;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;

	/* calculate gap interval */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (outer = gap; outer < size; outer++)
		{
			/* select the value to be inserted */
			temp_val = array[outer];
			inner = outer;

			/* shift value to right */
			while (inner > gap - 1 && array[inner - gap] >= temp_val)
			{
				array[inner] = array[inner - gap];
				inner -= gap;
			}
			/* insert element at this position */
			array[inner] = temp_val;
		}
		print_array(array, size);
		/* calculate interval */
		gap = (gap - 1) / 3;
		i++;
	}
}
