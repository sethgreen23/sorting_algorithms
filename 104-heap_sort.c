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
	int startIndex, i, n;

	if (array == NULL || size <= 1)
		return;
	startIndex = ((int)size / 2) - 1;
	for (i = startIndex; i >= 0; i--)
		heapify(array, (int)size, i, size);
	for (n = (int)size - 1; n >= 0; n--)
	{
		if (n != 0)
		{
			swap_heap(&array[n], &array[0]);
			print_array(array, size);
			heapify(array, n, 0, size);
		}
	}
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
 * heapyfy - deleting the elements to sort the array
 * @array: The array to sort
 * @n: size of the current array
 * @i: the index we want to heapify from
 * @size: The size of the array
 *
 * Return: nothing
 */
void heapify(int *array, int n, int i, size_t size)
{
	int l, r, largest;

	l = (2 * i) + 1;
	r = (2 * i) + 2;
	largest = i;
	if (l < n && array[l] > array[largest])
		largest = l;
	if (r < n && array[r] > array[largest])
		largest = r;
	if (i != largest)
	{
		swap_heap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}
