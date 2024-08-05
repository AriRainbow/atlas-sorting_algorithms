#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using Selection sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t current_index, search_index, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (current_index = 0; current_index < size - 1; current_index++)
	{
		min_index = current_index;
		for (search_index = current_index + 1; search_index < size; search_index++)
		{
			if (array[search_index] < array[min_index])
				min_index = search_index;
		}

		if (min_index != current_index)
		{
			/* swap the elements */
			temp = array[current_index];
			array[current_index] = array[min_index];
			array[min_index] = temp;

			print_array(array, size); /* after each swap */
		}
	}
}
