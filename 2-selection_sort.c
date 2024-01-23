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
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
    int *min;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min = array + i;
        for (j = i + 1; j < size; j++)
            min = (array[j] < *min) ? (array + j) : min;

        if ((array + i) != min)
        {
            swap_int(array + i, min);
            print_array(array, size);
        }
    }
}


