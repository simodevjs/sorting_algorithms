#include "sort.h"

/**
 * swap_int - Swaps 2 integers in one array.
 * @A: Pointer to the first int.
 * @B: Pointer to the second int.
 */
void swap_int(int *A, int *B)
{
    int CTN;

    CTN = *A;
    *A = *B;
    *B = CTN;
}

/**
 * Seif_partition - Order a subset of an array of integers according to
 *                    the Seif partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @LF: The starting index of the subset to order.
 * @RL: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int Seif_partition(int *array, size_t size, int LF, int RL)
{
	int *pivot, above, below;

	pivot = array + RL;
	for (above = below = LF; below < RL; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_int(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_int(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * Seif_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @LF: The starting index of the array partition to order.
 * @RL: The ending index of the array partition to order.
 *
 * Description: Uses the Seif partition scheme.
 */
void Seif_sort(int *array, size_t size, int LF, int RL)
{
	int part;

	if (RL - LF > 0)
	{
		part = Seif_partition(array, size, LF, RL);
		Seif_sort(array, size, LF, part - 1);
		Seif_sort(array, size, part + 1, RL);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Seif partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	Seif_sort(array, size, 0, size - 1);
}
