#include "sort.h"


/**
 * radix_helper - A recursive helper function to do radix sort
 * @array: The array to sort
 * @size: The size of the array to sort
 * @digit: the current digit to sort by
 */
void radix_helper(int *array, size_t size, size_t digit)
{
	size_t i = 0, j = 0;
	size_t digits[10];
	int *radices[10];
	int tmp, count;

	for (i = 0; i < 10; i++)
		digits[i] = 0;
	for (i = 0; i < size; i++)
	{
		tmp = array[i] % digit;
		tmp = tmp / (digit / 10);
		digits[tmp] = digits[tmp] + 1;
	}
	if (digits[0] == size)
		return;
	for (i = 0; i < 10; i++)
		radices[i] = malloc(digits[i] * sizeof(int));
	for (i = 0; i < 10; i++)
	{
		count = 0;
		for (j = 0; j < size; j++)
			if (((array[j] % digit) / (digit / 10)) == i)
			{
				radices[i][count] = array[j];
				count++;
			}
	}
	count = 0;
	for (i = 0; i < 10; i++)
		for (j = 0; j < digits[i]; j++)
		{
			array[count] = radices[i][j];
			count++;
		}
	print_array((const int *)array, size);
	for (i = 0; i < 10; i++)
		free(radices[i]);
	radix_helper(array, size, digit * 10);
}


/**
 * radix_sort - Sort by each digit in turn
 * @array: The array to sort
 * @size: The size of the array to sort
 */
void radix_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	if (size < 2)
		return;
	radix_helper(array, size, 10);
}
