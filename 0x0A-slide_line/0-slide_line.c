#include "slide_line.h"
/**
 * slide_line - slides and merges an array of integers
 * @line: input array
 * @size: size of array
 * @direction: direction to slide to right or left
 * Return: 0 on failure, 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{
	if ((direction != SLIDE_LEFT) && (direction != SLIDE_RIGHT))
		return (0);
	if (direction == 0)
		slide_left(line, size);
	if (direction == 1)
		slide_right(line, size);
	return (1);
}

/**
 * slide_left - slides a line to the left
 * @line: input array
 * @size: size of array
 */
void slide_left(int *line, size_t size)
{
	int x = 0, y, prev = 0, aux;

	for (y = 0; y < (int)size; y++)
	{
		aux = line[y];
		if (!aux)
			continue;
		if (!prev)
			prev = aux;
		else if (prev == aux)
		{
			line[x++] = aux << 1;
			prev = 0;
		} else
		{
			line[x++] = prev;
			prev = aux;
		}
	}
	if (prev)
		line[x++] = prev;
	while (x < (int)size)
		line[x++] = 0;
}

/**
 * slide_right - slides a line to the right
 * @line: input array
 * @size: size of array
 */
void slide_right(int *line, size_t size)
{
	int prev = 0, x = size - 1, y, aux;

	for (y = size - 1; y >= 0; y--)
	{
		aux = line[y];
		if (!aux)
			continue;
		if (!prev)
			prev = aux;
		else if (prev == aux)
		{
			line[x--] = aux << 1;
			prev = 0;
		} else
		{
			line[x--] = prev;
			prev = aux;
		}
	}
	if (prev)
		line[x--] = prev;
	while (x >= 0)
		line[x--] = 0;
}
