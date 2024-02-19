#include "sort.h"

/**
 * bubble_sort - a function that sorts array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: int *
 * @size: size_t
 */
void bubble_sort(int *array, size_t size)
{
	int current,swapped;
	size_t i, j;

	if(!array || size <= 0)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				current = array[j];
				array[j] = array[j + 1];
				array[j + 1] = current;
				swapped = 1;
				if (swapped)
				{
					print_array(array, size);
				}
			}
		}
	}
}
