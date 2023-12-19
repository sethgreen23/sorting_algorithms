#include "sort.h"

/**
 * bitonic_sort - Bitonic Sorted algorithm
 * @array: The array to sort
 * @size: The array size
 *
 * Return: nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	bitonic_srt(array, 0, (int)size, size, 1);
}
/**
 * bitonic_srt - bitonic sorting recursive function
 * @array: the array to sort
 * @lb: lower bound
 * @mid: mid value
 * @size: size of the big array
 * @direction: the direction of the sorting
 */
void bitonic_srt(int *array, int lb, int mid, size_t size, int direction)
{
	int k;
	char *d;

	if (mid > 1)
	{
		d = (direction == 1) ? "UP" : "DOWN";
		k = mid / 2;
		printf("Merging [%d/%lu] (%s):\n", mid, size, d);
		print_array(array + lb, mid);
		bitonic_srt(array, lb, k, size, 1);
		bitonic_srt(array, lb + k, k, size, 0);
		merge_bitonic(array, lb, mid, size, direction);
		printf("Result [%d/%lu] (%s):\n", mid, size, d);
		print_array(array + lb, mid);

	}
}
/**
 * merge_bitonic - merge the left and right subarrays
 * @array: The array to sort
 * @lb: lower bound
 * @mid: mid position
 * @size: size of the big array
 * @direction: direction of the sorting
 *
 * Return: nothing
 */
void merge_bitonic(int *array, int lb, int mid, size_t size, int direction)
{
	int k, i;

	if (mid > 1)
	{
		k = mid / 2;
		for (i = lb; i < lb + k; i++)
		{
			if (direction == (array[i] > array[i + k]))
			{
				swap_bitonic(&array[i], &array[i + k]);
				merge_bitonic(array, lb, k, size, direction);
				merge_bitonic(array, lb + k, k, size, direction);
			}
		}
	}
}
/**
 * swap_bitonic - swap values
 * @a: a
 * @b: b
 *
 * Return: nothing
 */
void swap_bitonic(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
