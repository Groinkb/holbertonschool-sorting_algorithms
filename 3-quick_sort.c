#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to be partitioned
 * @low: Index of the low element
 * @high: Index of the high element
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int lomuto_partition(array, low, high, size)
int array[];
int low;
int high;
size_t size;
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_quick_sort - Lomuto quick sort implementation
 * @array: Array to be sorted
 * @low: Index of the low element
 * @high: Index of the high element
 * @size: Size of the array
 */
void lomuto_quick_sort(array, low, high, size)
int array[];
int low;
int high;
size_t size;
{
	if (low < high)
	{
		int part = lomuto_partition(array, low, high, size);

		lomuto_quick_sort(array, low, part - 1, size);
		lomuto_quick_sort(array, part + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick Sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(array, size)
int array[];
size_t size;
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, 0, size - 1, size);
}
