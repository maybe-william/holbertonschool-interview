#include "holberton.h"

/**
 * wildcmp - compare two strings if one has a wildcard
 * @s1: regular string
 * @s2: string that might have wildcard
 * Return: 1 if they "match", 0 if not.
 */
int wildcmp(char *s1, char *s2)
{
	int tmp = 0;

	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
	{
		if (*s1 != '\0')
			tmp = wildcmp(s1 + 1, s2);
		return (wildcmp(s1, s2 + 1) || tmp);
	}
	return (0);
}
