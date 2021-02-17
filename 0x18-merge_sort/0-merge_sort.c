#include "sort.h"
/**
 * merge_sub - merges subarray sub with passed in array
 * @sub: copy of the array
 * @array: array to merge
 * @left: index of element to the left
 * @middle: index of element in the middle
 * @right: index of element to the right
 */
void merge_sub(int *sub, int *array, size_t left,size_t middle, size_t right)
{
	size_t i = left, j = middle, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	while (i < middle && j < right)
	{
		if (array[i] < array[j])
			sub[k++] = array[i++];
		else
			sub[k++] = array[j++];
	}

	while (i < middle)
		sub[k++] = array[i++];

	while (j < right)
		sub[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = sub[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
/**
* split - recursively call to get middle
* @sub: subarray to merge
* @array: input array to sort
* @left: beginning element
* @right: end element
* Return: void
*/
void split(int *sub, int *array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		split(sub, array, left, middle);
		split(sub, array, middle, right);
		merge_sub(sub, array, left, middle, right);
	}
}
/**
* merge_sort - sort by merging with subarray
* @array: array to sort
* @size: size of the array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	int *sub;

	if (!array || size < 2)
		return;

	sub = malloc(sizeof(int) * size);

	split(sub, array, 0, size);
	free(sub);
}
