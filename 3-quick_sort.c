#include "sort.h"

/**
 * swap - swaps integers
 * @a: pointer to first int
 * @b: pointer to second int
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - partition an array
 * @array: array to partition
 * @size: size of array
 * Return: nothing
 */
int partition(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[j], &array[i]);
			i++;
		}
	}
	swap(&array[i], &array[size - 1]);
	return (i);
}

/**
 * quick_sort - sort an array of ints using quick_sort
 * @array: the array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	int pivot_indx;

	if (array == NULL || size <= 0)
		return;
	if (size < 2)
		return;
	pivot_indx = partition(array, size);
	quick_sort(array, pivot_indx);
	quick_sort(array + pivot_indx + 1, size - pivot_indx - 1);
}
