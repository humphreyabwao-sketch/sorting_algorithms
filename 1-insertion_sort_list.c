#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * prints the list after each time you swap two elements
 *
 * @list: pointer to the linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	/* An list does not need to be sorted if its size is less than 2 */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		next = current->next;

		/* if 2 adjacent nodes are out of order */
		while (current->prev && (current->n < current->prev->n))
		{
			/* swap current and current->prev */
			prev = current->prev;

			current->prev = prev->prev;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;  /* update the head of the list */

			prev->next = current->next;
			if (prev->next)
				prev->next->prev = prev;

			current->next = prev;
			prev->prev = current;

			/* print list */
			print_list(*list);
		}

		current = next;
	}
}
