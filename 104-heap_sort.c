#include "sort.h"
#include <stdlib.h>


void swap_element_in_array(int *n1, int *n2);
void heapify(int *array, size_t size, size_t parent, size_t size_array);

/**
 * heap_sort - a function that sorts an array of integers
 *	in ascending order using the the Heap sort algorithm
 *	implement the sift-down heap sort algorithm
 *@array: the array to be sorted
 *@size: the size of the array
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size <  2)
		return;
	/* Build the Max Heap */

	for (i = size / 2; i < size; i--)
	{
		heapify(array, size, i, size);
	}

	/* sort the heap, by swap array[0] and array[size--] */
	/* after each swap we have to heapify and make it a max heap again*/

	for (i = size - 1; i < size; i--)
	{
		swap_element_in_array(&array[0], &array[i]);
		print_array(array, size);

		heapify(array, i, 0, size);
	}
}

/**
 * heapify - build a max heap for heap sort
 *@array: the array to be sorted
 *@size: the size of the subtree
 *@parent: the current parent of the subtree
 *@size_array: the aize of the actual array
 *
 * Return: void
 */

void heapify(int *array, size_t size, size_t parent, size_t size_array)
{
	size_t left_child, right_child, max_index;

	max_index = parent;
	left_child = parent * 2 + 1;
	right_child = parent * 2 + 2;

	if (left_child < size && array[left_child] > array[max_index])
		max_index = left_child;

	if (right_child < size && array[right_child] > array[max_index])
		max_index = right_child;

	if (parent != max_index)
	{
		swap_element_in_array(&array[parent], &array[max_index]);
		print_array(array, size_array);
		heapify(array, size, max_index, size_array);
	}
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
