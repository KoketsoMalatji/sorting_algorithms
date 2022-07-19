#include "sort.h"

/**
 * merge_compare - compares merges
 * @array: the integer array to sort
 * @start: the start index
 * @stop: the stop index
 * @new: the output array
 *
 * Return: void.
 */
void merge_compare(int *array, size_t start, size_t stop, int *newArray)
{
	size_t i = start, j, x, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);
	for (x = start; x < stop; x++)
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{

			newArray[x] = array[i++];
		}
		else
		{
			newArray[x] = array[j++];
		}
	printf("[Done]: ");
	print_array(newArray + start, stop - start);
}

/**
 * merge_sort_top_down - sorts top-down recursively
 * @array: the integer array to sort
 * @start: the start index
 * @stop: the stop index
 * @new: the output array
 *
 * Return: void.
 */
void merge_sort_top_down(int *array, size_t start, size_t stop, int *newArray)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	merge_sort_top_down(newArray, start, mid, array);
	merge_sort_top_down(newArray, mid, stop, array);
	merge_compare(newArray, start, stop, array);
}


/**
 * merge_sort - sorts by merge sort algorithm
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *newArray;
	size_t i;


	if (!array || size < 2)
		return;

	newArray = malloc(sizeof(int) * size);
	if (!newArray)
		return;
	for (i = 0; i < size; i++)
		newArray[i] = array[i];
	merge_sort_top_down(array, 0, size, newArray);
	free(newArray);
}
