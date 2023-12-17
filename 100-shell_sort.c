#include "sort.h"
/**
 * shell_swap - swap two integers
 * @a: first element
 * @b: second element
 *
 * Return: nothing
 */
void shell_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * shell_sort - Shell Sorting Algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j;

	gap = 1;
	while (gap < (int)size)
		gap = gap * 3 + 1;
	for (gap = gap / 3; gap >= 1; gap = gap / 3)
	{
		for (j = gap; j < (int)size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] >= array[i])
					break;
				shell_swap(&array[i + gap], &array[i]);
			}
		}
		print_array(array, size);
	}
}
