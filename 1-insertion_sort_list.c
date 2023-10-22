#include "sort.h"

void swap(listint_t **head, listint_t **p1, listint_t **p2);
/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 *	in ascending order using the Insertion sort algorithm
 *@list: the list to be sorted
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *ptr2, *temp;
	int key;

	if (list == NULL)
		return;
	ptr = *list;
	if (ptr == NULL || ptr->next == NULL)
		return;

	ptr = ptr->next;
	while (ptr)
	{
		key = ptr->n;
		ptr2 = ptr->prev;

		temp = ptr->next;
		while (ptr2 && (ptr2->n) > (key))
		{
			swap(list, &ptr2, &(ptr2->next));
			print_list(*list);
			ptr2 = ptr2->prev->prev;
		}

		ptr = temp;

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
