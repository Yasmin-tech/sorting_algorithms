#include "sort.h"
#include <stddef.h>

/**
 * bubble_sort - sort an array of integers in ascending
 * order using the bubble sort algorithm
 * @array: array of integers
 * @size: size of the integer
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, swap = 0;
	int temp;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		swap = 0;
		for (j = 0; j < size - i && !(j + 1 >= size - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
