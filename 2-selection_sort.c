#include "sort.h"

/**
 * selection_sort - Selection sort
 * @array: The array to sort
 * @size: The array size
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, min_index, j;
	int min_value, found, temp;

	for (i = 0; i < size; i++)
	{
		found = 0;
		min_index = i;
		j = i;
		min_value = array[i];
		for (; j < size; j++)
		{
			if (array[j] < min_value)
			{
				min_index = j;
				min_value = array[j];
				found = 1;
			}
		}
		if (found)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
