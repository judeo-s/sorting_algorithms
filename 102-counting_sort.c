#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort.
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max, *countArray, *output;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	countArray = calloc(max + 1, sizeof(int));
	if (countArray == NULL)
		return;

	for (i = 0; i < size; i++)
		countArray[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		countArray[i] += countArray[i - 1];

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(countArray);
		return;
	}

	print_array(countArray, max + 1);
	for (i = 0; i < size; i++)
	{
		output[countArray[array[i]] - 1] = array[i];
		countArray[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(countArray);
	free(output);
}
