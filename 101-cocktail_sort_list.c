#include "sort.h"
#include <stdlib.h>

void swap(listint_t **head, listint_t **p1, listint_t **p2);
/**
 * cocktail_sort_list - a function that sorts a doubly linked list of integers
 *	in ascending order using  the Cocktail shaker sort algorithm
 *@list: the list to be sorted
 *
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *ptr = *list, *start = NULL, *end = NULL;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		while (ptr->next != end)
		{
			if (ptr->n > ptr->next->n)
			{
				swapped = 1;
				swap(list, &ptr, &ptr->next);
				print_list(*list);
			}
			else
				ptr = ptr->next;
		}
		end = ptr;

		if (!swapped)
			break;

		swapped = 0;
		ptr = ptr->prev->prev;

		while (ptr->prev != start)
		{
			if (ptr->n > ptr->next->n)
			{
				swapped = 1;
				swap(list, &ptr, &ptr->next);
				print_list(*list);
				ptr = ptr->prev->prev;
			}
			else
				ptr = ptr->prev;
		}

		start = ptr->prev;
	}


}
/**
 * swap - a helper function to swap two doubly linked list nodes
 *@head: a double pointer to the head of the doubly linked list
 *@p1: a double pointer to node 1
 *@p2: a double pointer to node 2
 *
 * Retutn: void
 */

void swap(listint_t **head, listint_t **p1, listint_t **p2)
{
	listint_t *temp =  (*p2)->next;

	(*p2)->next = (*p2)->prev;
	(*p2)->prev = (*p2)->next->prev;

	if ((*p1)->prev == NULL)
		*head = *p2;
	else
		(*p1)->prev->next = *p2;
	(*p1)->prev = *p2;
	(*p1)->next = temp;
	if (temp != NULL)
		temp->prev = *p1;
}
