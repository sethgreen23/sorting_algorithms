#include "sort.h"

/**
 * change_pos - change the position of the nodes
 * @prev: previous node
 * @curr: current node
 *
 * Return: nothing
 */
void change_position(listint_t **cur_n, listint_t **prev_n, listint_t **lst)
{
	if (size_list(*lst) == 2)
	{
		(*prev_n)->next = NULL;
		(*cur_n)->prev = NULL;
	}
	else if ((*prev_n)->prev == NULL)
	{
		(*cur_n)->prev = NULL;
		(*prev_n)->next = (*cur_n)->next;
		(*cur_n)->next->prev = *prev_n;
	}
	else if ((*cur_n)->next == NULL)
	{
		(*prev_n)->next = NULL;
		(*prev_n)->prev->next = *cur_n;
		(*cur_n)->prev = (*prev_n)->prev;
	}
	else
	{
		(*prev_n)->prev->next = *cur_n;
		(*prev_n)->next = (*cur_n)->next;
		(*cur_n)->prev = (*prev_n)->prev;
		(*cur_n)->next->prev = *prev_n;
	}
	(*cur_n)->next = *prev_n;
	(*prev_n)->prev = *cur_n;
}

/**
 * swap_node - Swap the nodes
 *
 * @previous: previous node
 * @current: current node
 *
 * Return: nothing
 */
void swap_node(listint_t **current, listint_t **previous)
{
	listint_t *temp;

	temp = *current;
	*current = *previous;
	*previous = temp;
}

/**
 * size_list - count the size of a list
 *
 * @list: list to count the length
 *
 * Return: 0 or length of the list
 */
int size_list(listint_t *list)
{
	int size;

	if (list == NULL)
		return (0);
	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

/**
 * insertion_sort_list - Insertion sort
 * @list: list to sort
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *previous = NULL, *current = NULL, *pointer = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	pointer = *list;
	while (pointer != NULL)
	{
		current = pointer;
		previous = pointer->prev;
		while (previous != NULL)
		{
			if (previous->n > current->n)
			{
				change_pos(&current, &previous);
				swap_node(&current, &previous);
				if (previous->prev == NULL)
					*list = previous;
				print_list(*list);
			}
			current = previous;
			previous = previous->prev;
		}
		pointer = pointer->next;
	}
}
