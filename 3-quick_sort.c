#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * partition - Lomuto partition scheme for Quick sort
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element after partition
 */
static size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t start_index = low;
	size_t current_index = low;

	for (current_index = low; current_index < high; current_index++)
	{
		if (array[current_index] < pivot)
		{
			if (start_index != current_index)
			{
				/* swap array[start_index] & array[current_index] */
				int temp = array[start_index];
				array[start_index] = array[current_index];
				array[current_index] = temp;
			}
			start_index++;
		}
	}

	/* swap array[start_index] and array[high] (or pivot) */
	if (start_index != high)
	{
		int temp = array[start_index];
		array[start_index] = array[high];
		array[high] = temp;
	}

	print_array(array, size);

	return (start_index);
}

/**
 * quick_sort_recursive - Recursively applies Quick sort
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @hign: Ending index of the partition
 * @size: Size of the array
 */
static void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t pi = partition(array, low, high, size);

		if (pi > 0) /* avoid recursive with out of bound index */
			quick_sort_recursive(array, low, pi - 1, size);

		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
