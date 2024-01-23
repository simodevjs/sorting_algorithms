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
 * shell_sort - Sort an array of ints asce using the shell sort algorithm.
 * @array: Array of integers.
 * @size:  Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t GP, ida, jida;

	if (array == NULL || size < 2)
		return;

	for (GP = 1; GP < (size / 3);)
		GP = GP * 3 + 1;

	for (; GP >= 1; GP /= 3)
	{
		for (ida = GP; ida < size; ida++)
		{
			jida = ida;
			while (jida >= GP && array[jida - GP] > array[jida])
			{
				swap_int(array + jida, array + (jida - GP));
				jida -= GP;
			}
		}
		print_array(array, size);
	}
}

