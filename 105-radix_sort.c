#include "sort.h"

/**
 * get_max - find the maximum value
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: nothing
 */
int get_max(int *array, size_t size)
{
	int m;
	size_t i;

	m = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > m)
			m = array[i];
	}
	return m;
}

/**
 * radix_sort - radix sorting algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int m, exp;

	m = get_max(array, size);
	for (exp = 1; m / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}

/**
 * counting_sort_radix - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 * @exp: exponent
 *
 * Return: nothing
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int i, *b, *count;

	if (array == NULL || size <= 1)
		return;

	count = malloc(sizeof(int) * 10);
	if (count == NULL)
		return;
	for (i = 0; i <= 9; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		++count[(array[i] / exp) % 10];
	for (i = 1; i <= 9; i++)
		count[i] += count[i - 1];
	b = malloc(sizeof(int) * (int)size);
	if (b == NULL)
	{
		free(count), count = NULL;
		return;
	}
	for (i = (int)size - 1; i >= 0; i--)
	{
		b[--count[(array[i] / exp) % 10]] = array[i];
	}
	for (i = 0; i < (int)size; i++)
		array[i] = b[i];
	free(b), b = NULL;
	free(count), count = NULL;

}
