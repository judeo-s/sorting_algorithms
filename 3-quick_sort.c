#include "sort.h"

/**
 * swap - a function that swaps elements in an array
 *
 * @a: int *
 * @b: int *
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - a functio n that is used to divde the array for sorting
 *
 * @array: int *
 * @left: int
 * @right: int
 * @size: size_t
 * Return: int
 */
int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right], i, j;

	i = left - 1;
	for (j = left; j <= right - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	i++;
	if (array[i] > pivot)
	{
		swap(&array[i], &array[right]);
		print_array(array, size);
	}
	return (i);
}

/**
 * sort - a function that starts the algorithm
 *
 * @arr: int *
 * @left: int
 * @right: int
 * @size: size_t
 */
void sort(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = lomuto_partition(arr, left, right, size);
		sort(arr, left, pivot - 1, size);
		sort(arr, pivot + 1, right, size);
	}
}

/**
 * quick_sort - A function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: int *
 * @size: size_t
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}
