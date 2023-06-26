#include "sort.h"

/**
 * selection_sort - sort an int array in ascending order using selection sort
 * @array: array to sort
 * @size: size of array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int temp, min;
	size_t i, j, t;

	if (array == NULL || size <= 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		t = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				t = j;
			}
		}
		if (min != array[i])
		{
			temp = array[i];
			array[i] = min;
			array[t] = temp;
			print_array(array, size);
		}
	}
}
