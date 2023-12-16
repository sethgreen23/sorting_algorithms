#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to sort
 * @low: starting index of partition
 * @high: ending index of partition
 * @size: size of the array
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - quick sort recursive function
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 *
 * Return: nothing
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low >= high)
		return;
	pivot = lomuto_partition(array, low, high, size);

	quicksort(array, low, pivot - 1, size);
	quicksort(array, pivot + 1, high, size);
}

/**
 * quick_sort - Sorts an array using the quicki sort algo
 * @array: array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
