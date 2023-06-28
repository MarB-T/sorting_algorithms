#include "sort.h"

/**
 * heapit - puts array in a heap
 * @array: array of ints
 * @min: min in array
 * @max: max int in array
 * @size: size of array
 */
void heapit(int *array, int min, int max, size_t size)
{
	int tmp, root = min;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < max && array[left] > array[root])
		root = left;

	if (right < max && array[right] > array[root])
		root = right;

	if (min != root)
	{
		tmp = array[root];
		array[root] = array[min];
		array[min] = tmp;
		print_array(array, size);
		heapit(array, root, max, size);
	}
}

/**
 * heap_sort - heap sort algorithm
 * @array: array of ints
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = size / 2 - 1; i >= 0; i--)
		heapit(array, i, size, size);

	i = size - 1;
	while (i > 0)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		print_array(array, size);
		heapit(array, 0, i, size);
		i--;
	}
}
