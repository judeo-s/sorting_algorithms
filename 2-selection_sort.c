#include "sort.h"

/**
 * swap - a function that swaps elements in an array
 *
 * @array: int *
 * @i: int
 * @index: int
 */
void swap(int *array, int i, int index)
{
	int current;

	current = array[i];
	array[i] = array[index];
	array[index] = current;
}


/**
 * selection_sort - a function that sorts an array of integers in ascending
 * order using the selection sort algorithm
 *
 * @array: int *
 * @size: size_t
 */
void selection_sort(int *array, size_t size)
{
	int index;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[index])
				index = j;
			++j;
		}
		if ((size_t)index != i)
		{
			swap(array, i, index);
			print_array(array, size);
		}
	}
}
