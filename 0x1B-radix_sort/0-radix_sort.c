#include "sort.h"


/**
 * check_sorted - function description
 * @array: parameter description
 * @size: parameter description
 * Return: 1 if sorted, 0 otherwise
 */
int check_sorted(int *array, size_t size)
{
	size_t i = 0, sorted = 0;

	sorted = 1;
	for (i = 1; i < size; i++)
		if (array[i] < array[i - 1])
			sorted = 0;

	if (sorted == 1)
		return (1);
	return (0);
}

/**
 * radix_helper - function description
 * @array: parameter description
 * @size: parameter description
 * @digit: the digit to sort
 */
void radix_helper(int *array, size_t size, size_t digit)
{
	size_t i = 0, j = 0;
	size_t digits[10];
	int *radices[10];
	int tmp, count;

	if (check_sorted(array, size) == 1)
		return;
	for (i = 0; i < 10; i++)
		digits[i] = 0;
	for (i = 0; i < size; i++)
	{
		tmp = array[i] % digit;
		tmp = tmp / (digit / 10);
		digits[tmp] = digits[tmp] + 1;
	}
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
 * radix_sort - function description
 * @array: parameter description
 * @size: parameter description
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	radix_helper(array, size, 10);
}
