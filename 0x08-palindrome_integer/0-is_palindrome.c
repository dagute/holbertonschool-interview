#include "palindrome.h"
/**
 * is_palindrome - checks whether or not a given integer is a palindrome
 * @n: input integer
 * Return: true or false
 */
int is_palindrome(unsigned long n)
{
	unsigned int r, t, sum = 0;

	for (t = n; n != 0; n = n / 10)
	{
		r = n % 10;
		sum = sum * 10 + r;
	}

	if (t == sum)
		return (1);
	else
		return (0);
}
