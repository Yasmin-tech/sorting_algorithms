#include "sort.h"
#include <stdlib.h>
#include <stdio.h>


void merge_sort_recursive(int *array, int *new_arr, size_t size,
		int left_index, int right_index);
void merge(int *array, int *new_arr, size_t size, int left_index,
		int mid_index, int right_index);

void merge_and_print(int len_left, int len_right, int *leftArr,
		int *rightArr, int left_index, int right_index, int *array);

/**
 * merge_sort - a function that sorts an array of integers
 *	in ascending order using the Merge sort algorithm
 *@array: the array to be sorted
 *@size: the size of the array
 *
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int left_index = 0;
	int right_index = size - 1;
	int *new_arr;

	if (array == NULL || size == 0 || size == 1)
		return;
	new_arr = malloc(sizeof(int) * size);

	merge_sort_recursive(array, new_arr, size, left_index, right_index);
	free(new_arr);
}

/**
 * merge_sort_recursive - a function that sorts an array of integers recursivly
 *	in ascending order using the Merge sort algorithm
 *@array: the array to be sorted
 *@new_arr: the array that will be used to hold the left and right subarrays
 *@size: the size of the array
 *@left_index: the index of the first element in the subarray
 *@right_index: the index of the last element of the subarray
 *
 * Return: void
 */
void merge_sort_recursive(int *array, int *new_arr, size_t size,
		int left_index, int right_index)
{
	int mid_index;

	if (left_index < right_index)
	{
		mid_index = left_index + (right_index - left_index + 1) / 2;

		merge_sort_recursive(array, new_arr, size, left_index, mid_index - 1);
		merge_sort_recursive(array, new_arr, size,  mid_index, right_index);

		merge(array, new_arr, size, left_index, mid_index, right_index);
	}
}


/**
 * merge - merge two sorted arrays
 *@array: the original array to be sorted
 *@new_arr: the array that will be used to hold the left and right subarrays
 *@size: the size of the array
 *@left_index: the index of the first element in the subarray
 *@mid_index: the index of the middle element in the subarray
 *@right_index: the index of the last element of the subarray
 *
 * Return: void
 */
void merge(int *array, int *new_arr, size_t size, int left_index,
		int mid_index, int right_index)
{
	int i, j, len_left, len_right, *leftArr, *rightArr;

	len_left = mid_index - left_index;
	len_right = right_index - mid_index + 1;
	leftArr = new_arr;
	rightArr = new_arr + (size / 2);
	/* copy left subarray elements */
	for (i = 0; i < len_left; i++)
		leftArr[i] = array[i + left_index];

	for (j = 0; j < len_right; j++)
		rightArr[j] = array[mid_index + j];
	/* print the element */
	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < len_left; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", leftArr[i]);
	}
	printf("\n");
	printf("[right]: ");
	for (i = 0; i < len_right; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", rightArr[i]);
	}
	printf("\n");
	merge_and_print(len_left, len_right, leftArr, rightArr,
			left_index, right_index, array);

}

/**
 * merge_and_sort - merge two sorted arrays
 *@len_left: the length of the left subarray
 *@len_right: the length of the right subarray
 *@leftArr: the left subarray
 *@rightArr: the right subarray
 *@left_index: the first element of the subarray
 *@right_index: the last element of the subarray
 *@array: the original array to be sorted
 *
 * Return: void
 */

void merge_and_print(int len_left, int len_right, int *leftArr,
		int *rightArr, int left_index, int right_index, int *array)
{

	int i = 0, j = 0, k = left_index, flag = 0;

	/* sorting the elements */
	while (i < len_left && j < len_right)
	{
		if (leftArr[i] < rightArr[j])
		{
			array[k] = leftArr[i];
			i++;
		}
		else
		{
			array[k] = rightArr[j];
			j++;
		}
		k++;
	}
	while (i < len_left)
	{
		array[k] = leftArr[i];
		i++;
		k++;
	}
	while (j < len_right)
	{
		array[k] = rightArr[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	for (i = left_index; i <= right_index; i++)
	{
		if (flag)
			printf(", ");
		printf("%d", array[i]);
		flag = 1;
	}
	printf("\n");
}

