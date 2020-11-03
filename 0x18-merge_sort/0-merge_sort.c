#include "sort.h"

/**
 * my_print_array - print an array
 * @prefix: the preceding bit of info
 * @array: the array to print
 * @size: the size of the array to print
 */
void my_print_array(char* prefix, int *array, size_t size)
{
    size_t i = 0;

    printf("%s", prefix);
    for(i = 0; i < size; i++)
    {
        printf("%i", array[i]);
        if (i == size - 1) {
            printf("\n");
            return;
        }
        printf(", ");
    }
}

/**
 * swap - switch two numbers
 * @a: the first number
 * @b: the second number
 */
void swap(int *a, int *b)
{
    int x = *a;

    *a = *b;
    *b = x;
}

/**
 * merge_sort_rec - sort an array by recursively merging sorted sub arrays
 * @array: the array to merge_sort
 * @size: the length of the array
 * @buff: the buffer
 */
void merge_sort_rec(int *array, size_t size, int *buff)
{
    size_t mid = size / 2;
    size_t i = 0;
    size_t j = mid;
    size_t k = 0;

    if (size <= 1 || array == NULL) {
        return;
    }
    merge_sort_rec(array, mid, buff);
    merge_sort_rec(array + mid, size - mid, buff);
    printf("Merging...\n");
    my_print_array("[left]: ", array, mid);
    my_print_array("[right]: ", array + mid, size - mid);
    while(i < mid && j < size)
    {
      if (array[i] < array[j]) {
        buff[k] = array[i];
        i++;
      } else {
        buff[k] = array[j];
        j++;
      }
      k++;
    }
    for ( ; i < mid; i++, k++)
        buff[k] = array[i];
    for ( ; j < size; j++, k++)
        buff[k] = array[j];
    for (k = 0; k < size; k++)
        array[k] = buff[k];
    my_print_array("[Done]: ", array, size);
}

/**
 * merge_sort - sort an array merging sorted sub arrays
 * @array: the array to merge_sort
 * @size: the length of the array
 */
void merge_sort(int *array, size_t size)
{
    int *buff = NULL;

    if (array == NULL || size == 0)
      return;
    buff = malloc(size * sizeof(int));
    if (buff == NULL)
        return;
    merge_sort_rec(array, size, buff);
    free(buff);
}
