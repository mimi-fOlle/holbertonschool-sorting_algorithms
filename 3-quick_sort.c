#include "sort.h"

/**
  * swap - Swaps array
  * @a: The array a
  * @b: The array b
  */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
  * partition - Finds position of partition
  * @array: The array to sort
  * @low: The lowest index of array
  * @high: The highest index of array
  * @size: The size of array
  *
  * Return: i + 1
  */

int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1); /*place for swapping*/
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);

			if (j != i)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);

	if (high != (i + 1))
		print_array(array, size);
	return (i + 1);
}

/**
  * quickSort - Sorts divided array
  * @array: The array to sort
  * @low: The lowest index of array
  * @high: The highest index of array
  * @size: The size of array
  */

void quickSort(int array[], int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quickSort(array, low, pivot - 1, size);
		quickSort(array, pivot + 1, high, size);
	}
}

/**
  * quick_sort - Sorts an array of integers in ascending order
  * using the Quick sort algorithm
  * @array: The array to sort
  * @size: The size of array
  */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;

	quickSort(array, 0, (size - 1), size);
}
