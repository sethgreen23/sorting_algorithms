#include "sort.h"

/**
 * partition - the partition function implemented
 * with the Lomuto partition scheme
 *
 * @array: The array to partition
 * @low: The lower bound of the array
 * @high: The higher bound of the array
 * @size: size of the array
 *
 * Return: nothing
 */
int partition(int *array, int low, int high, int size)
{
	int  pivot, temp, i, j;

	pivot = array[high];
	i = j = low;
	for (; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			print_array(array, size);
		}
	}
	array[high] = array[i];
	array[i] = pivot;
	return (i);
}

/**
 * quick_sort_algo - the main quick sort function
 *
 * @array: The array to sort
 * @low: The lower bound of the array
 * @high: The higher bound of the array
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort_algo(int *array, int low, int high, int size)
{
	int pivot;

	if (low >= high)
		return;
	pivot = partition(array, low, high, size);
	quick_sort_algo(array, low, pivot - 1, size);
	quick_sort_algo(array, pivot + 1, high, size);
}
/**
 * quick_sort - Quick sort algorithm
 * Implemented with the Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_algo(array, 0, size - 1, size);
}
