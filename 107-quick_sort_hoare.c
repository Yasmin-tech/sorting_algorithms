#include "sort.h"
#include <stdlib.h>


void quick_sort_recursive(int *array, int low_index, int high_index,
		size_t size);
size_t hoarePartition(int *array, int low_index, int high_index, size_t size);
void swap_element_in_array(int *n1, int *n2);

/**
 * quick_sort_hoare - a function that sorts an array of integers
 *	in ascending order using the Quick sort algorithm hoare scheme
 *@array: the array to be sorted
 *@size: the size of the array
 *
 * Return: void
 */


void quick_sort_hoare(int *array, size_t size)
{
	int low_index = 0;
	int high_index = size - 1;

	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, low_index, high_index, size);
}

/**
 * quick_sort_recursive - a function that recursivly devide the array
 *	into partitions in order to sort the array
 *@array: the array to be sorted
 *@low_index: the first index of the unsorted subarray
 *@high_index: the last index of the unsorted aubarray
 *@size: the size of the array
 *
 * Return: void
 */

void quick_sort_recursive(int *array, int low_index, int high_index,
		size_t size)
{
	size_t pivot_index;

	if (low_index < high_index)
	{
		pivot_index = hoarePartition(array, low_index, high_index, size);
		quick_sort_recursive(array, low_index, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index, high_index, size);
	}
}

/**
 * hoarePartition - a function that decides the pivot
 *	the function will finds the correct index of the pivot and returns it
 *@array: the array
 *@low_index: the first index of the unsorted subarray
 *@high_index: the last index of the unsorted aubarray
 *@size: the size of the array
 *
 * Return: the pivot index
 */

size_t hoarePartition(int *array, int low_index, int high_index, size_t size)
{
	int i, j, pivot_value;

	j = high_index + 1;
	i = low_index - 1;
	pivot_value = array[high_index];

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot_value);

		do {
			j--;
		} while (array[j] > pivot_value);

		if (i >= j)
			return (i);
		swap_element_in_array(&array[i], &array[j]);
		print_array(array, size);

	}
	return (i);

}

/**
 * swap_element_in_array - swap two elements in an array
 *@n1: the first number
 *@n2: the second number
 *
 * Return: void
 */

void swap_element_in_array(int *n1, int *n2)
{
	int temp = *n2;

	*n2 = *n1;
	*n1 = temp;
}
