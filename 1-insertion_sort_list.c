#include "sort.h"

/**
 * swap - swaps 2 nodes in a doubly-linked list
 * @a: address of first node
 * @b: address of second node
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

}

/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		k = i;
		i = i->next;
		while (k && k->prev)
		{
			if (k->prev->n > k->n)
			{
				swap(k->prev, k);
				if (!k->prev)
					*list = k;
				print_list((const listint_t *)*list);
			}
			else
				k = k->prev;
		}

	}
}
