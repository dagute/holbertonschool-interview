#include "sandpiles.h"

/**
 * print_grid - prints a matrix
 * @grid: 3x3 matrix
 */
static void print_grid(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}

/**
 * add_matrix - adds 2 matrixes together
 * @grid1: 3x3 matrix
 * @grid2: 3x3 matrix
 */
void add_matrix(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] = grid1[x][y] + grid2[x][y];
}

/**
 * sandpile - checks to see if a matrix is stable (all values must
 * be between 0 and 3)
 * @grid: 3x3 matrix
 * Return: true or false
 */
int sandpile(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			if (grid[x][y] > 3)
				return (0);
	return (1);
}

/**
 * downfall - collapses a sandpile at a given index
 * @grid: input grid
 * @x: input row
 * @y: input col
 */
void downfall(int grid[3][3], int x, int y)
{
	int r, a, b;
	int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	for (r = 0; r < 4; r++)
	{
		a = x + directions[r][0];
		b = y + directions[r][1];
		if ((x >= 0 && x < 3) && (y >= 0 && y < 3))
			grid[a][b] += 1;
	}
	grid[x][y] -= 4;
}

/**
 * sandpiles_sum - sum two matrixes and balances them out
 * @grid1: 3x3 matrix
 * @grid2: 3x3 matrix
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int s[3][3];
	int x, y, stable = 0;

	add_matrix(grid1, grid2);
	while (1)
	{
		stable = sandpile(grid1);
		if (!stable)
		{
			printf("=\n");
			print_grid(grid1);
			memcpy(s, grid1, 3 * 3 * sizeof(int));
			for (x = 0; x < 3; x++)
				for (y = 0; y < 3; y++)
					if (grid1[x][y] > 3)
						downfall(s, x, y);
			memcpy(grid1, s, 3 * 3 * sizeof(int));
		} else
			break;
	}
}
