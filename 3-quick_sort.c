#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first int
 * @b: second int
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
 * @low: the lowest index of array
 * @high: the highest index of array
 * @size: size of array
 * Return: pivot index for quick sorting
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	i = low - 1;
	j = low;
	pivot = array[high];
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
		}
		j++;
	}
	if (pivot < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (1 + i);
}

/**
 * sort - sort an array of ints using quick_sort
 * @array: the array to be sorted
 * @low: low index of array section
 * @high: last index of array section
 * @size: size of the array
 * Return: nothing
 */
void sort(int *array, int low, int high, size_t size)
{
	int pivot_indx;

	if (low < high)
	{
		pivot_indx = partition(array, low, high, size);
		sort(array, low, pivot_indx - 1, size);
		sort(array, pivot_indx + 1, high, size);
	}
}

/**
 * quick_sort - sort an array of using qick sort algorithm
 * @array: the array to sort
 * @size: the size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t low, high;

	if (array == NULL || size <= 1)
		return;
	low = 0;
	high = size - 1;
	sort(array, low, high, size);
}
