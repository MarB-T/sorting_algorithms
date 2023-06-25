#include "sort.h"

/**
 * bubble_sort - bubble sort
 * @array: pointer to array
 * @size: the size of array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}
