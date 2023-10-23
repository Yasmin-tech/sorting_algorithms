#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - a function that sorts an array of integers
 *	in ascending order using the Counting sort algorithm
 *@array: the array to be sorted
 *@size: the size of the array
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *counting_arr = NULL, *sorted_arr = NULL, value;
	size_t i, max;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	counting_arr = malloc(sizeof(int) * (max + 1));
	sorted_arr = malloc(sizeof(int) * size);
	for (i = 0; i < max + 1; i++)
		counting_arr[i] = 0;

	for (i = 0; i < size; i++)
		counting_arr[array[i]] += 1;
	for (i = 1; i < max + 1; i++)
		counting_arr[i] += counting_arr[i - 1];
	print_array(counting_arr, max + 1);
	for (i = size - 1; i < size; i--)
	{
		value = counting_arr[array[i]];
		counting_arr[array[i]] = value - 1;

		sorted_arr[counting_arr[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_arr[i];
	free(counting_arr);
	free(sorted_arr);
}
