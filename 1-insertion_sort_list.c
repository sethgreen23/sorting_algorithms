#include "sort.h"

/**
 * change_pos - change the position of the nodes
 * @prev: previous node
 * @curr: current node
 *
 * Return: nothing
 */
void change_pos(listint_t **curr, listint_t **prev)
{
	if ((*prev)->prev == NULL && (*curr)->next != NULL)
	{
		(*curr)->prev = NULL;
		(*curr)->next->prev = *prev;
		(*prev)->next = (*curr)->next;
	}
	else if ((*curr)->next == NULL && (*prev)->prev != NULL)
	{
		(*prev)->next = NULL;
		(*prev)->prev->next = *curr;
		(*curr)->prev = (*prev)->prev;
	}
	else if ((*curr)->next != NULL && (*prev)->prev != NULL)
	{
		(*curr)->next->prev = *prev;
		(*prev)->prev->next = *curr;
		(*prev)->next = (*curr)->next;
		(*curr)->prev = (*prev)->prev;
	}
	else
	{
		(*curr)->prev = NULL;
		(*prev)->next = NULL;
	}
	(*curr)->next = *prev;
	(*prev)->prev = *curr;
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
