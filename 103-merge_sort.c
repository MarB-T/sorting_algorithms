#include "sort.h"

/**
 * print_parts - prints part of the list
 * @array: input array
 * @first_idx: start of array
 * @last_idx: end of array
 */
void print_parts(int *array, size_t first_idx, size_t last_idx)
{
	size_t i;

	i = first_idx;
	while (i < last_idx)
	{
		if (i > first_idx)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * top_down - merge using top down method
 * @A: input left array
 * @B: input right array
 * @first_idx: start of array
 * @mid: mid of the array
 * @last_idx: end of array
 */
void top_down(int *A, int *B, size_t first_idx, size_t mid, size_t last_idx)
{
	size_t i = first_idx, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_parts(A, first_idx, mid);
	printf("[right]: ");
	print_parts(A, mid, last_idx);
	for (k = first_idx; k < last_idx; k++)
	{
		if (i < mid && (j >= last_idx || A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_parts(B, first_idx, last_idx);
	for (k = first_idx; k < last_idx; k++)
		A[k] = B[k];
}

/**
 * top_down_split - split into 2
 * @A: input left array
 * @B: input right array
 * @first_idx: start of array
 * @last_idx: end of array
 */
void top_down_split(int *A, int *B, size_t first_idx, size_t last_idx)
{
	size_t mid;

	if (last_idx - first_idx < 2)
		return;
	mid = (first_idx + last_idx) / 2;
	top_down_split(A, B, first_idx, mid);
	top_down_split(A, B, mid, last_idx);
	top_down(A, B, first_idx, mid, last_idx);
}

/**
 * merge_sort - sort array using merge method
 * @array: input array
 * @size: input size of array
 */
void merge_sort(int *array, size_t size)
{
	int *newlist;

	if (array == NULL || size <= 1)
		return;
	newlist = malloc(sizeof(int) * size);
	if (newlist == NULL)
		return;
	top_down_split(array, newlist, 0, size);
	free(newlist);
}
