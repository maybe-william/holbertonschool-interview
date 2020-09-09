#include "search_algos.h"

/**
 * print_arr - print the array at each step
 * @array: the array
 * @size: the size of the array
 */
void print_arr(int *array, size_t size)
{
	unsigned int i = 0;
	char *ending;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		ending = "\n";
		if (i < size - 1)
			ending = ", ";
		printf("%d%s", array[i], ending);
	}
}

/**
 * bin_recur - recursive binary search
 * @array: the array
 * @size: the length of the array
 * @value: the sought value
 * @start: the indices before the value
 * Return: -1 if not found, otherwise the index
 */
int bin_recur(int *array, size_t size, int value, int start)
{
	int mid;

	print_arr(array, size);
	if (size == 1)
	{
		if (array[0] == value)
			return (start);
		return (-1);

	}
	if (size == 2)
	{
		if (array[0] == value)
			return (start);
		return (bin_recur(array + 1, 1, value, start + 1));
	}

	mid = (size - 1) / 2;
	if (array[mid] >= value)
		return (bin_recur(array, mid + 1, value, start + 0));
	return (bin_recur(array + mid + 1, size - (mid + 1), value, start + mid + 1));
}

/**
 * advanced_binary - binary search finding lowest index of value
 * @array: the array to search
 * @size: the size of the array
 * @value: the value to search for
 * Return: the index of the found value
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (bin_recur(array, size, value, 0));
}
