#include "sort.h"
/**
*integer_count- number of times integer appears in an array
*
*@array: array given
*@size: size of array
*@range: number to check for occurance
*
*Return: number of occurances
*/
int integer_count(int *array, size_t size, int range)
{
	int total = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] == range)
			total++;
	}
	return (total);
}

/**
*counting_sort - counting sort algorithm
*
*@array: array to be sorted
*@size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int j = 0, b = 0, a = 0;
	size_t i, c;
	int *array2, *newArray;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > j)
		{
			j = array[i];
		}
	}
	array2 = malloc(sizeof(int) * (j + 1));
	if (!array2)
		return;
	for (c = 0; c < ((size_t)j + 1); c++)
	{
		if (c == 0)
			array2[c] = integer_count(array, size, a);
		else
		{
			b = array2[c - 1] + integer_count(array, size, a);
			array2[c] = b;
		}
		r++;
	}
	print_array(array2, (j + 1));
	newArray = malloc(sizeof(int) * size);
	if (!newArray)
	{
		free(array2);
		return;
	}
	for (i = 0; i < size; i++)
		newArray[array2[array[i]]-- - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = newArray[i];
	free(newArray);
	free(array2);
}
