#include "sort.h"

/**
 * merge - Merges tow sorted arrays
 *
 * @array: Pointer to array
 * @lb: Lower bound
 * @mid: Middle index
 * @ub: Upper bound
 * @size: Size of the array
 *
 * Return: nothing
 */
void merge(int *array, int lb, int mid, int ub, size_t size)
{
	int i, j, k, size_s, *sorted;

	(void)size;
	i = lb, j = mid, k = 0, size_s = ub - lb + 1;
	sorted = malloc(sizeof(int) * size_s);
	if (sorted == NULL)
		return;
	printf("Merging...\n");
	print_sub(array, lb, mid - 1, "left");
	print_sub(array, mid, ub, "right");
	while (i < mid && j <= ub)
	{
		if (array[i] <= array[j])
		{
			sorted[k] = array[i];
			i++;
		}
		else
		{
			sorted[k] = array[j];
			j++;
		}
		k++;
	}
	while (j <= ub)
	{
		sorted[k] = array[j];
		j++, k++;
	}
	while (i < mid)
	{
		sorted[k] = array[i];
		i++, k++;
	}
	print_sub(sorted, 0, size_s - 1, "Done");
	for (k = 0; k < size_s; k++)
		array[k + lb] = sorted[k];
	free(sorted), sorted = NULL;
}
/**
 * print_sub - print a sub array from lower to upper bounds
 *
 * @array: the array to print
 * @lb: lower bound
 * @ub: upper bound
 * @message: the message to print
 *
 * Return: nothing
 */
void print_sub(int *array, int lb, int ub, char *message)
{
	int i;

	printf("[%s]: ", message);
	for (i = lb; i <= ub; i++)
	{
		printf("%d", array[i]);
		if (i != ub)
			printf(", ");
	}
	printf("\n");

}
/**
 * merge_srt - Recursive merge sort
 *
 * @array: Pointer to array
 * @lb: Lower bound
 * @ub: Upper bound
 * @size: Size of the array
 *
 * Return: nothing
 */
void merge_srt(int *array, int lb, int ub, size_t size)
{
	int mid;

	if (lb >= ub)
		return;
	mid = (ub + lb + 1) / 2;
	merge_srt(array, lb, mid - 1, size);
	merge_srt(array, mid, ub, size);
	merge(array, lb, mid, ub, size);
}
/**
 * merge_sort - the main function of the merge sort
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int lb, ub;

	lb = 0, ub = (int)size - 1;
	if (array == NULL || size <= 1)
		return;
	merge_srt(array, lb, ub, size);
}
