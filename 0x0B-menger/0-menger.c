#include "menger.h"
/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 *
 */
void menger(int level)
{
	int i, j, x, y, output;
	char ch;

	output = pow(3, level);

	for (i = 0; i < output; i++)
	{
		for (j = 0; j < output; j++)
		{
			ch = '#';
			x = i;
			y = j;
			while (x > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
					ch = ' ';
				x /= 3;
				y /= 3;
			}
			printf("%c", ch);
		}
		printf("\n");
	}
}
