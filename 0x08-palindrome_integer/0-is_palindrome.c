#include "palindrome.h"

/**
 * is_palindrome - check if an unsigned int is a palindrome
 * @n: the unsigned int
 * Return: 1 if palindrome, else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long x = n;
	unsigned long last_div = 1;
	unsigned long first_digit, last_digit;

	while (x / last_div > 10)
		last_div = last_div * 10;

	while (last_div > 1)
	{
		first_digit = x % 10;
		last_digit = (x / last_div) % 10;

		if (first_digit != last_digit)
			return (0);

		x = x / 10;
		last_div = last_div / 100;
	}
	return (1);

}
