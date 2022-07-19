#include "sort.h"

/**
 * get_max_gap - gets the a largest Knuth Sequence gap for this size
 * @size: the size of the array
 *
 * Return: the gap size
 */
size_t get_max_gap(size_t size)
{
	size_t n;

	n = 1;
	while (n < size)
		n = n * 3 + 1;
	return ((n - 1) / 3);
}

/**
 * shell_sort - shell_sort
 * @array: the integer array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, k;
	int temp;

	if (!array || !size)
		return;


	for (gap = get_max_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (k = i; k > gap - 1 && array[k - gap] > temp; k -= gap)
			{
				array[k] = array[k - gap];
			}
			array[k] = temp;
		}
		print_array(array, size);
	}
}
