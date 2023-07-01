#include "sort.h"

/**
 * get_max - gets the largest element in an array
 * @array: the array in question
 * @size: size of the array
 * Return: largest integer
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_ - count sort function
 * @array: the array to be sorted
 * @size: size of the array
 * @pos: digit position
 * Return: nothing
 */
void counting_sort_(int *array, size_t size, int pos)
{
	int count[10] = {0};
	int *temp;
	size_t i;

	temp = malloc(sizeof(array));
	if (!temp)
		return;
	for (i = 0; i < size; i++)
		++count[(array[i] / pos) % 10];
	for (i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
		temp[--count[(array[i] / pos) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(temp);
}

/**
 * radix_sort - sorts an array of integers using radix sort
 * @array: the array to be sorted
 * @size: size of array
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int pos, max;

	if (array == NULL || size <= 1)
		return;
	max = get_max(array, size);
	for (pos = 1; (max / pos) > 0; pos *= 10)
	{
		counting_sort_(array, size, pos);
		print_array(array, size);
	}
}
