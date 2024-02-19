#include "sort.h"


/**
 * listint_position_swap - a function to swap the postions of two
 * elements in a the listint_t data structure
 *
 * @current: listint_t *
 * @next: listint_t *
 * @head: listint_t **
 */
void listint_position_swap(listint_t *current, listint_t *next,
		listint_t **head)
{
	if (!current || !next || current == next || !current->next)
		return;
	if (current->next != next)
		return;

	current->next = next->next;
	next->prev = current->prev;

	current->prev = next;
	next->next = current;

	if (current->next)
		current->next->prev = current;
	if (next->prev)
		next->prev->next = next;

	if (*head == current)
		*head = next;
}


/**
 * insertion_sort_list - a function that sorts array of integers
 * in ascending order using the insertion sort algorithm
 *
 * @list: listint_t **
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list);
	while (current)
	{
		temp = current;

		if (temp->next && temp->n > temp->next->n)
		{
			listint_position_swap(temp, temp->next, list);
			print_list(*list);
			temp = temp->prev;
		}
		while (temp->prev && temp->n < temp->prev->n)
		{
			listint_position_swap(temp->prev, temp, list);
			print_list(*list);
		}
		current = temp->next;
	}
}
