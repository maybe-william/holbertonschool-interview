#include "menger.h"
#include "math.h"


/**
 * get_char - get the char for the position in the square
 * @x: the x position of the char
 * @y: the y position of the char
 * @level: the level of square to get the char from
 * Return: the char at that position in that level square
 */
char get_char(int x, int y, int level)
{
    int size, mod, x_third, y_third;


    if (level == 1)
    {
        if (x == 1 && y == 1)
            return ' ';
        else
            return '#';
    }

    size = (int)pow(3, level);
    mod = size/3;

    x_third = x/mod;
    y_third = y/mod;
    if (x_third == 1 && y_third == 1)
        return ' ';
    else
        return (get_char(x % mod, y % mod, level - 1));

}

/**
 * menger - function description
 * @level: parameter description
 */
void menger(int level)
{
    int size, i, j;

    if (level < 0)
        return;
    if (level == 0)
    {
        putchar('#');
        putchar('\n');
        return;
    }

    size = (int)pow(3,level);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            putchar(get_char(j, i, level));
        }
        putchar('\n');
    }
}
