#ifndef SANDPILE_H
#define SANDPILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sandpile(int grid[3][3]);
static void print_grid(int grid[3][3]);
void add_matrix(int grid1[3][3], int grid2[3][3]);
void downfall(int grid[3][3], int x, int y);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
