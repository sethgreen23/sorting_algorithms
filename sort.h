#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer sorted in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
int size_list(listint_t *list);
void swap_node(listint_t **current, listint_t **previous);
void change_pos(listint_t **curr, listint_t **prev);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void shell_swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
#endif
