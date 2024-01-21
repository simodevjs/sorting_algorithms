#ifndef SORT
#define SORT

#include <stdio.h>
#include <stdlib.h>

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting_algoritms */
void bubble_sort(int *array, size_t size);

/* Insertion */
void insertion_sort_list(listint_t **list);

#endif
