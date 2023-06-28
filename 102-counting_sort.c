#include "sort.h"

/**
 * counting_sort - sorts an array of integers using Counting sort
 * @array: pointer to the array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int *copy, *counting;
	unsigned int max = 0, i = 0, tmp;

	if (array == NULL || size <= 1)
		return;

	while (i < size)
	{
		if (array[i] > (int)max)
			max = array[i];
		i++;
	}
	max++;
	counting = malloc(max * sizeof(int));
	if (counting == NULL)
		return;
	copy = malloc(size * sizeof(int));
	if (copy == NULL)
	{
		free(counting);
		return;
	}

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	for (i = 0; i < max; i++)
		counting[i] = 0;

	for (i = 0; i < size; i++)
		counting[array[i]]++;

	for (i = 1; i < max; i++)
		counting[i] += counting[i - 1];

	print_array(counting, max);
	for (i = 0; i < size; i++)
	{
		tmp = copy[i];
		array[counting[tmp] - 1] = tmp;
		counting[tmp]--;
	}
	free(counting);
	free(copy);
}
