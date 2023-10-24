#include "sort.h"
#include <stdlib.h>


void counting_sort_for_radix(int *array, size_t size, int place);
/**
 * radix_sort - a function that sorts an array of integers in ascending order
 *	using the Radix sort algorithm, implement the LSD radix sort algorithm
 *@array: the array to be sorted
 *@size: the size of the array
 *
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int max, place;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size - 1; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	place = 1;
	while (max / place > 0)
	{
		counting_sort_for_radix(array, size, place);
		print_array(array, size);

		place *= 10;
	}


}

/**
 * counting_sort_for_radix  - a function that sorts an array of integers
 *	in ascending order using the Counting sort algorithm
 *@array: the array to be sorted
 *@size: the size of the array
 *@place: the current digit sorting place
 *
 * Return: void
 */

void counting_sort_for_radix(int *array, size_t size, int place)
{
	int counting_arr[10] = {0}, *sorted_arr = NULL, value;
	size_t i;


	sorted_arr = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
		counting_arr[(array[i] / place) % 10] += 1;

	for (i = 1; i < 10; i++)
		counting_arr[i] += counting_arr[i - 1];

	for (i = size - 1; i < size; i--)
	{
		value = counting_arr[(array[i] / place) % 10];
		counting_arr[(array[i] / place) % 10] = value - 1;

		sorted_arr[counting_arr[(array[i] / place) % 10]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_arr[i];
	free(sorted_arr);
}
