#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using Bubble sort algorithm
 * @array: Array to be sorted
 * @size: Number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t outer_index, inner_index;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (outer_index = 0; outer_index < size - 1; outer_index++)
	{
		swapped = 0;
		for (inner_index = 0; inner_index < size - outer_index - 1; inner_index++)
		{
			if (array[inner_index] > array[inner_index + 1])
			{
				/* swap array[inner_index] & array[inner_index + 1 */
				temp = array[inner_index];
				array[inner_index] = array[inner_index + 1];
				array[inner_index + 1] = temp;
				swapped = 1;

				print_array(array, size); /*print after each swap */
			}
		}

		/* if no two elements swapped by inner loop, then break */
		if (swapped == 0)
			break;
	}
}
