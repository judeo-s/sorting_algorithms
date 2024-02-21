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
 * cocktail_sort_list - a function that sorts array of integers
 * in ascending order using the cocktail shaker sortt algorithm
 *
 * @list: listint_t **
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp;
	int flag;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list);
	while (1)
	{
		temp = current;
		flag = 0;
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{
				listint_position_swap(temp, temp->next, list);
				print_list(*list);
				temp = temp->prev;
				flag = 1;
			}
			temp = temp->next;
		}
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				listint_position_swap(temp->prev, temp, list);
				print_list(*list);
				temp = temp->next;
				flag = 1;
			}
			temp = temp->prev;
		}
		if (!flag)
			break;
	}
}
