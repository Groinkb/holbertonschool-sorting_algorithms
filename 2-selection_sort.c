#include "sort.h"

/**
 * insertion_sort - function that sorts elements in an array using
 * insertion sort technique
 * @array: array
 * @size: size of the array
 */
void insertion_sort(int *array, size_t size)
{
	size_t i, j;
	int key;

	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		print_array(array, size);
	}
}
