#include "sort.h"

/**
 * heap_sort - Heap Sort
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	build_heap(array, size);
	sort_heap(array, size);
}
/**
 * swap_heap - swap two integers
 * @a: value a
 * @b: value b
 *
 * Return: nothing
 */
void swap_heap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * build_heap - build the heap
 * @array: The array to change it to a heap
 * @size: The size of the array
 *
 * Return: nothing
 */
void build_heap(int *array, size_t size)
{
	int i, parent, j;

	for (i = 0; i < (int)size; i++)
	{
		j = i;
		while (j >= 0)
		{
			parent = (j - 1) / 2;
			if (array[parent] < array[j])
			{
				swap_heap(&array[parent], &array[j]);
				print_array(array, size);
				j = parent;
			}
			else
				break;
		}
	}
}

/**
 * sort_heap - deleting the elements to sort the array
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: nothing
 */
void sort_heap(int *array, size_t size)
{
	int size_srt = (int)size, idx_left, idx_right, left, right, j = 0;

	for (size_srt = size_srt - 1; size_srt >= 0;)
	{
		swap_heap(&array[size_srt], &array[0]);
		print_array(array, size);
		--size_srt;
		j = 0;
		while (j <= size_srt)
		{
			idx_left = (2 * j) + 1;
			idx_right = (2 * j) + 2;
			left = (idx_left <= size_srt) ? array[idx_left] : 0;
			right = (idx_right <= size_srt) ? array[idx_right] : 0;
			if (left >= right)
			{
				if (left > array[j])
				{
					swap_heap(&array[idx_left], &array[j]);
					print_array(array, size);
					j = idx_left;
				}
				else
					break;
			}
			else
			{
				if (right > array[j])
				{
					swap_heap(&array[idx_right], &array[j]);
					print_array(array, size);
					j = idx_right;
				}
				else
					break;
			}
		}
	}
}
