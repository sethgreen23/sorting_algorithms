#include "sort.h"



/**
 * bubble_sort - Bubble sort in an array
 * @array: The array to sort
 * @size: The size of @array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, pass;
	int swapped = 1, temp;

	if (array == NULL || size <= 1)
		return;
	for (pass = size - 1; pass != 0 && swapped; pass--)
	{
		swapped = 0;
		for (i = 0; i <= pass - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
