#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked lst.
 * @h: A pointer to the head of the doubly-linked lst.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swaper2(listint_t **h, listint_t **n1, listint_t *n2)
{
    (*n1)->next = n2->next;
    if (n2->next != NULL)
        n2->next->prev = *n1;
    n2->prev = (*n1)->prev;
    n2->next = *n1;
    if ((*n1)->prev != NULL)
        (*n1)->prev->next = n2;
    else
        *h = n2;
    (*n1)->prev = n2;
    *n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked lst of integers
 *                       using the insertion sort algorithm.
 * @lst: A pointer to the head of a doubly-linked lst of integers.
 *
 * Description: Prints the lst after each swap.
 */
void insertion_sort_list(listint_t **lst)
{
    listint_t *iterat, *ins, *CTN;

    if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
        return;

    for (iterat = (*lst)->next; iterat != NULL; iterat = CTN)
    {
        CTN = iterat->next;
        ins = iterat->prev;
        while (ins != NULL && iterat->n < ins->n)
        {
            swaper2(lst, &ins, iterat);
            print_list((const listint_t *)*lst);
        }
    }
}


