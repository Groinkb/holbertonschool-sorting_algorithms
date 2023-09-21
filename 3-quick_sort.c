#include "sort.h"

/**
 * hoare_partition - function that implements Hoare partition scheme
 * @array: array
 * @low: first index
 * @high: last index
 * @size: size of array
 * Return: pivot index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, tmp;
	int i = low - 1;
	int j = high + 1;

	pivot = array[low];

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
		{
			return j;
		}

		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * hoare_quick_sort - Hoare partition scheme implemented
 * @array: array
 * @low: first index
 * @high: last index
 * @size: size of array
 */
void hoare_quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = hoare_partition(array, low, high, size);

		hoare_quick_sort(array, low, pivot, size);
		hoare_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the quick sort algorithm (Hoare partition scheme)
 * @array: array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_quick_sort(array, 0, size - 1, size);
}
