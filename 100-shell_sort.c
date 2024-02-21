#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using Shell sort
 * with Knuth sequence
 *
 * @array: int *
 * @size: size_t
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int temp, i, j;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= (int)gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
