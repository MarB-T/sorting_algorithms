#include "sort.h"

/**
 * shell_sort - sorts an array of integers using shell sort
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	if (array == NULL || size <= 1)
		return;
	while (interval < size)
		interval = interval * 3 + 1;
	interval = (interval - 1) / 3;
	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
