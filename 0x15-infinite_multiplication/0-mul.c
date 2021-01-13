#include "holberton.h"

/**
 * print_num - prints an array of integers like a number
 * @nums: array of integers
 * @size: size of the array of integers
 */
void print_num(int *nums, int size)
{
	int x = 0;

	if (!nums && !size)
	{
		printf("0\n");
		exit(0);
	}
	while (nums[x] == 0)
		x++;
	for (; x < size; x++)
	{
		printf("%d", nums[x]);
	}
	printf("\n");
}
/**
 * bigmul - multiplies two large numbers
 * @num1: large integer as a string
 * @num2: large integer as a string
 * Return: 1 on success, 0 on failure
 */
int bigmul(char *num1, char *num2)
{
	int x, y;
	int len1, len2, sum, n1, n2 = 0;
	int *nums;

	len1 = strlen(num1);
	len2 = strlen(num2);

	nums = calloc(len1 + len2, sizeof(len1 + len2));
	if (!nums)
		return (0);

	for (x = len1 - 1; x >= 0; x--)
	{
		n1 = num1[x] - '0';
		for (y = len2 - 1; y >= 0; y--)
		{
			n2 = num2[y] - '0';
			sum = (n1 * n2) + nums[x + y + 1];
			nums[x + y] += sum / 10;
			nums[x + y + 1] = sum % 10;
		}
	}
	print_num(nums, len1 + len2);
	free(nums);
	return (1);
}
/**
 * main - Entry point: multiplies two positive numbers
 * @argc: number of arguments passed
 * @argv: arguments passed (integers)
 * Return: 0 in success, 1 on failure
 */
int main(int argc, char **argv)
{
	int x, y = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (x = 1; argv[x]; x++)
		for (y = 0; argv[x][y]; y++)
			if (argv[x][y] < '0' || argv[x][y] > '9')
			{
				printf("Error\n");
				exit(98);

			}

	if (*argv[1] == '0' || *argv[2] == '0')
		print_num(NULL, 0);
	if (!bigmul(argv[1], argv[2]))
		return (1);
	return (0);
}
