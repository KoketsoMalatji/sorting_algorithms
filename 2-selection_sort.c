#include "sort.h"

/**
 * selection_sort - sorts an array using the selection algorithm
 * @array: pointer to array
 * @size: size of the array
 * Returns: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, index;
	int value;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		value = array[i];
		index = i;
		for (j = i; j < size; j++)
		{
			if (value > array[j])
			{
				index = j;
				value = array[j];
			}
		}
		if (value == array[i] && index == i)
			continue;
		array[index] = array[i];
		array[i] = value;
		print_array(array, size);
	}
}
