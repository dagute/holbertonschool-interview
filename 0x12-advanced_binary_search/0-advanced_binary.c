#include "search_algos.h"
/**
 * print_array - This function print an array
 * @array: Array
 * @left: Size of array
 * @right: Value to find
 * Return: Nothing
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d", array[i]);
	printf("\n");
}
/**
 * rec_binsearch - Recursive advanced binary search
 * @array: Array
 * @left: left element of array
 * @right: right element of array
 * @value: Value to find
 * Return: Always EXIT_SUCCESS
 */

int rec_binsearch(int *array, size_t left, size_t right, int value)
{
	size_t half;

	if (left < right)
	{
		half = left + (right - left) / 2;
		print_array(array, (int)left, (int)right);
		if (array[half] >= value)
			return (rec_binsearch(array, left, half, value));
		else
			return (rec_binsearch(array, half + 1, right, value));
				return ((int)(half));
	}
	if (array[left] == value)
		return (left);
	print_array(array, (int)left, (int)right);
	return (-1);
}
/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: Array
 * @size: Size of array
 * @value: Value to find
 * Return: Always EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left, right;

	if (!array)
		return (-1);

	left = 0;
	right = size - 1;
	return (rec_binsearch(array, left, right, value));

}
