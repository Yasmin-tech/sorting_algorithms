#include "sort.h"

/**
 * selection_sort - sort an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int i, j, pos;
	int min, temp, flag;

	if (size < 2)
		return;
	for (i = 0; (size_t)i < size; i++)
	{
		flag = 0;
		min = array[i];
		if ((size_t)i == size - 1)
			break;
		for (j = i; (size_t)j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				pos = j;
				flag = 1;
			}
		}
		if (flag)
		{
			temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
			print_array(array, size);
		}
	}
}

