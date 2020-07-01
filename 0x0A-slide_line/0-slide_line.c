#include "slide_line.h"


/**
 * slide_merge_right - slide a line right like the game 2048
 * @line: the array representing the line of numbers
 * @size: the size of the array
 * Return: 0 on failure, 1 on success
 */
int slide_merge_right(int *line, size_t size)
{
	int end = size - 1;
	int put_pos = end;
	int pos1 = end;
	int pos2 = end;
	int value;
	int equal_values = 0;

	while (pos1 >= 0 || pos2 >= 0)
	{
		while (pos1 >= 0 && line[pos1] == 0)
			pos1--;
		pos2 = pos1 - 1;
		while (pos2 >= 0 && line[pos2] == 0)
			pos2--;
		if (pos1 < 0)
			break;

		equal_values = pos2 >= 0 && line[pos1] == line[pos2];

		if (equal_values)
		{
			value = line[pos1] * 2;
			line[pos1] = 0;
			line[pos2] = 0;
			line[put_pos] = value;
		}
		if (!equal_values)
		{
			value = line[pos1];
			line[pos1] = 0;
			line[put_pos] = value;
		}

		pos1 = pos2;
		pos2--;
		put_pos--;
	}
	return (1);
}

/**
 * slide_merge_left - slide a line left like the game 2048
 * @line: the array representing the line of numbers
 * @size: the size of the array
 * Return: 0 on failure, 1 on success
 */
int slide_merge_left(int *line, size_t size)
{
	int put_pos = 0;
	int pos1 = 0;
	int pos2 = 0;
	int value;
	int equal_values = 0;

	while ((size_t)pos1 < size || (size_t)pos2 < size)
	{
		while ((size_t)pos1 < size && line[pos1] == 0)
			pos1++;
		pos2 = pos1 + 1;
		while ((size_t)pos2 < size && line[pos2] == 0)
			pos2++;
		if ((size_t)pos1 >= size)
			break;

		equal_values = (size_t)pos2 < size && line[pos1] == line[pos2];

		if (equal_values)
		{
			value = line[pos1] * 2;
			line[pos1] = 0;
			line[pos2] = 0;
			line[put_pos] = value;
		}
		if (!equal_values)
		{
			value = line[pos1];
			line[pos1] = 0;
			line[put_pos] = value;
		}

		pos1 = pos2;
		pos2++;
		put_pos++;
	}
	return (1);
}





/**
 * slide_line - slide a line left or right like the game 2048
 * @line: the array representing the line of numbers
 * @size: the size of the array
 * @direction: the left or right enum (macro)
 * Return: 0 on failure, 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{

return (0);
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (!line || !(*line))
		return (0);
	if (size == 1)
		return (1);

	if (direction == SLIDE_LEFT)
		return (slide_merge_left(line, size));
	else
		return (slide_merge_right(line, size));
}
