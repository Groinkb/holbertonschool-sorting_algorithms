#include "sort.h"
#include <stdio.h>
/**
 * swap - function that swaps to node
 * @firstNode: firstNode
 * @secondNode: secondNode
 * @list: list head
 */

void swap(listint_t *firstNode, listint_t *secondNode, listint_t **list)
{
	firstNode->next = secondNode->next;
	secondNode->prev = firstNode->prev;
	if (firstNode->prev != NULL)
		firstNode->prev->next = secondNode;
	else
		*list = secondNode;
	if (secondNode->next != NULL)
		secondNode->next->prev = firstNode;

	secondNode->next = firstNode;
	firstNode->prev = secondNode;
}

/**
 *insertion_sort_list - insetion sort algorithm
 *@list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *unsorted;

	if (list == NULL)
		return;
	sorted = *list;
	while (sorted->next != NULL)
	{
		if (sorted->n > sorted->next->n)
		{
			swap(sorted, sorted->next, list);
			print_list(*list);
			unsorted = sorted->prev;
			while (unsorted->prev != NULL && unsorted->n < unsorted->prev->n)
			{
				swap(unsorted->prev, unsorted, list);
				print_list(*list);
			}

		}
		else
			sorted = sorted->next;
	}
}
