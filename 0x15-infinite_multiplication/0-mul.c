#include "holberton.h"
#include <stdlib.h>

/**
 * get_space - get a malloc'd space
 * @len: the length of the space
 * Return: The space
 */
char *get_space(int len)
{
	int i = 0;
	char *space;

	space = malloc(len + 1);
	for (i = 0; i < len; i++)
		space[i] = '0';
	space[i] = '\0';
	return (space);
}

/**
 * add - add two numbers (in string form)
 * @larger: num1
 * @smaller: num2
 * Return: the sum (in string form)
 */
char *add(char *larger, char *smaller)
{
	int i = 0, j = 0, k = 0, l = 0, pos1 = 0, pos2 = 0, carry = 0;
	char *res;
	char *tmp;

	while (larger[i])
		i++;
	while (smaller[j])
		j++;
	res = malloc(i + 1 + 1);
	for (k = 0; k < i + 1 + 1; k++)
		res[k] = '\0';
	tmp = malloc(i + 1 + 1);
	for (k = 0; k < i - j + 1; k++)
		tmp[k] = '0';
	for (; k < i + 1 + 1; k++, l++)
		tmp[k] = smaller[l];
	i--;
	for (; i >= 0; i--)
	{
		k = i + 1;
		pos2 = tmp[k] - '0';
		pos1 = larger[i] - '0';
		if (pos1 + pos2 + carry >= 10)
		{
			res[k] = ((pos1 + pos2 + carry) - 10) + '0';
			carry = 1;
		}
		else
		{
			res[k] = (pos1 + pos2 + carry) + '0';
			carry = 0;
		}
	}
	if (carry == 1)
		res[0] = '1';
	else
		res[0] = '0';
	free(tmp);
	return (res);
}

/**
 * squeegee - squeeze out zeros on the front
 * @windshield: the string to squeegee
 * Return: a string without leading zeros
 */
char *squeegee(char *windshield)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *new;

	while (windshield[j] == '0')
		j++;
	i = j;
	while (windshield[i])
		i++;

	new = malloc(i - j + 1);
	for (k = j; k < i + 1; k++)
		new[k - j] = windshield[k];
	free(windshield);
	return (new);
}

/**
 * twice - double the number in a string
 * @string: the number to double
 */
void twice(char *string)
{
	int i = 0;
	int digit = 0;
	int carry = 0;

	while (string[i])
		i++;
	i--;

	for (; i >= 0; i--)
	{
		digit = string[i] - '0';
		digit = digit + digit + carry;
		if (digit >= 10)
		{
			digit = digit - 10;
			carry = 1;
		} else
			carry = 0;
		string[i] = digit + '0';
	}
}

/**
 * half - halve the number in a string
 * @string: the number to halve
 * Return: 1 if a one was lost due to halving
 */
int half(char *string)
{
	int i = 0;
	int j = 0;
	int digit = 0;
	int carry = 0;

	while (string[i])
		i++;

	for (j = 0; j < i; j++)
	{
		digit = (string[j] - '0') / 2;
		digit = digit + (carry * 5);
		carry = (string[j] - '0') % 2;
		string[j] = digit + '0';
	}
	return (carry);
}

/**
 * zero - check if a string is all zeros
 * @string: the number to check
 * Return: 1 if all zeros, otherwise 0
 */
int zero(char *string)
{
	int i = 0;

	for (; string[i]; i++)
		if (string[i] != '0')
			return (0);
	return (1);
}

/**
 * russian - the russian peasant multiplication method
 * @larger: the first operand
 * @smaller: the second operand
 * @len: the len of the strings holding operands
 * Return: the result of the multiplication in a string
 */
char *russian(char *larger, char *smaller, int len)
{
	char *acc;
	int odd;
	char *tmp;


	acc = get_space(len);
	if (zero(larger) || zero(smaller))
		return (acc);

	while (!zero(smaller))
	{
		odd = half(smaller);
		if (odd == 1)
		{
			tmp = acc;
			acc = add(acc, larger);
			free(tmp);
		}
		twice(larger);
	}
	return (acc);
}


/**
 * acceptable - check if a char is a digit
 * @c: the char to check
 * Return: 0 if not a digit, 1 if a digit
 */
int acceptable(char c)
{
	switch (c)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return (1);
		default:
			return (0);
	}
}

/**
 * validate - check the inputs for data cleanliness
 * @one: the first input
 * @two: the second input
 * Return: 1 if data is clean, 0 otherwise
 */
int validate(char *one, char *two)
{
	int i = 0;

	for (; one[i]; i++)
		if (!acceptable(one[i]))
			return (0);
	for (i = 0; two[i]; i++)
		if (!acceptable(two[i]))
			return (0);
	return (1);
}

/**
 * main - the main method
 * @argc: the count of commandline args
 * @argv: the commandline args
 * Return: exit status
 */
int main(int argc, char *argv[])
{
	char *one, *two, *l, *s, *res, *tmp, *err = "Error";
	int i = 0, j = 0, k = 0, len = 0;

	if (argc != 3 || !validate(argv[1], argv[2]))
	{
		for (; err[i]; i++)
			_putchar(err[i]);
		_putchar('\n');
		exit(98);
	}
	one = argv[1];
	two = argv[2];
	while (one[i])
		i++;
	while (two[j])
		j++;
	len = i + j + 2;
	if (j > i)
	{
		res = one;
		one = two;
		two = res;
		res = NULL;
	}
	l = get_space(len);
	tmp = l;
	l = add(l, one);
	free(tmp);
	s = get_space(len);
	tmp = s;
	s = add(s, two);
	free(tmp);
	res = russian(l, s, len);
	res = squeegee(res);
	for (k = 0; res[k]; k++)
		_putchar(res[k]);
	_putchar('\n');
	free(l);
	free(s);
	free(res);
}
