#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of ints
 * @list: a double linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_n = NULL;

	if (!list)
		return;
	curr_n = (*list)->next;
	while (curr_n != NULL)
	{
		while (curr_n->prev != NULL && curr_n->prev->n > curr_n->n)
		{
			curr_n->prev->next = curr_n->next;
			if (curr_n->next != NULL)
				curr_n->next->prev = curr_n->prev;
			curr_n->next = curr_n->prev;
			curr_n->prev = curr_n->next->prev;
			curr_n->next->prev = curr_n;
			if (curr_n->prev == NULL)
				*list = curr_n;
			else
				curr_n->prev->next = curr_n;
			print_list(*list);
		}
		curr_n = curr_n->next;
	}
}
