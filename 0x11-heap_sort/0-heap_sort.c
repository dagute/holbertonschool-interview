#include "sort.h"
/**
 * swap_int - change the value of two variable with pointers
 * @x: pointer x
 * @y: pointer y
 */
void swap_int(int *x, int *y)
{
	int temp = *x;
		*x = *y;
		*y = temp;
}
/**
 * max_heapify - order according binary distribution
 * @array: pointer to array
 * @size: actual size
 * @i: actual position
 * @total: total size
 */
void max_heapify(int *array, int size, int i, size_t total)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap_int(&array[i], &array[largest]);
		print_array(array, total);
		max_heapify(array, size, largest, total);
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t total = size;

	if (array != NULL)
	{
		for (i = size / 2 - 1; i >= 0; i--)
			max_heapify(array, size, i, total);
		for (i = size - 1; i > 0; i--)
		{
			swap_int(&array[0], &array[i]);
			print_array(array, size);
			max_heapify(array, i, 0, total);
		}
	}
}
