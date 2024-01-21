#include "sort.h"

/**
 * swaper - Swap two integers in an array.
 * @A: The first integer to swap.
 * @B: The second integer to swap.
 */
void swaper(int *A, int *B)
{
	int cntn;

	cntn = *A;
	*A = *B;
	*B = cntn;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool logi = false;

	if (array == NULL || size < 2)
		return;

	while (logi == false)
	{
		logi = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swaper(array + i, array + i + 1);
				print_array(array, size);
				logi = false;
			}
		}
		len--;
	}
}
