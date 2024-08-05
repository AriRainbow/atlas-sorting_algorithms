#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using Insertion sort
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		key_node = current;
		current = current->next;

		/* move key_node to correct position in sorted part of list */
		while (key_node->prev != NULL && key_node->n < key_node->prev->n)
		{
			/* swap nodes key_node & key_node->n */
			temp = key_node->prev;
			temp->next = key_node->next;
			if (key_node->next != NULL)
				key_node->next->prev = temp;

			key_node->prev = temp->prev;
			key_node->next = temp;
			temp->prev = key_node;

			if (key_node->prev != NULL)
				key_node->prev->next = key_node;
			else
				*list = key_node;

			print_list(*list); /* after each swap */
		}
	}
}
