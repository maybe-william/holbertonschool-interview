#include "sandpiles.h"

/**
 * my_print - print the grid with an = above it
 * @grid: the grid to print
 */
void my_print(int grid[3][3])
{
	int i;
	int j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d", grid[i][j]);
			if (j == 2)
				printf("\n");
			else
				printf(" ");
		}
	}
}

/**
 * iterate - iterate over the pile p doing the function f for each element
 * @f: the function to do at each point
 * @p: the pile to iterate
 * @a: an extra pile
 * @b: a second extra pile
 * @flag: a flag to pass to the function to dispatch to the correct sub func
 */
void iterate(iter_func f, int p[3][3], int a[3][3], int b[3][3], int flag)
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			f(i, j, p[i][j], a, b, flag);
		}
	}
}

/**
 * add_check_zero - add two grids or check if done or zero a grid
 * @x: the current x
 * @y: the current y
 * @val: the current val
 * @a: an extra pile
 * @b: a second extra pile
 * @flag: a flag to dispatch to the correct sub function
 */
void add_check_zero(int x, int y, int val, int a[3][3], int b[3][3], int flag)
{
	if (flag == 1)
	{
		/* add grids */
		a[x][y] = a[x][y] + val;
	}

	if (flag == 2)
	{
		/* check not done */
		if (val == 1)
		{
			b[0][0] = 1;
		}
	}

	if (flag == 3)
	{
		/* zero grid */
		b[x][y] = 0;
	}
}

/**
 * get_do_topples - get the squares that need toppling or do the toppling
 * @x: the current x
 * @y: the current y
 * @val: the current val
 * @a: an extra pile
 * @b: a second extra pile
 * @flag: a flag to dispatch to the correct sub function
 */
void get_do_topples(int x, int y, int val, int a[3][3], int b[3][3], int flag)
{
	int xs[] = {-1, 1, 0, 0};
	int ys[] = {0, 0, -1, 1};
	int x2;
	int y2;
	int i;


	if (flag == 1)
	{
		/* get topples */
		if (val > 3)
		{
			b[x][y] = 1;
		}
	}

	if (flag == 2)
	{
		/* do topples */
		if (b[x][y] == 1)
		{
			for (i = 0; i < 4; i++)
			{
				x2 = x + xs[i];
				y2 = y + ys[i];
				if (!(x2 < 0 || y2 < 0 || x2 > 2 || y2 > 2))
				{
					a[x2][y2] = a[x2][y2] + 1;
				}
			}
			a[x][y] = a[x][y] - 4;
		}
	}
}

/**
 * sandpiles_sum - function description
 * @grid1: the starting and ending grid
 * @grid2: the added grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int not_done[3][3];
	int topple[3][3];

	/* add the two grids */
	iterate(add_check_zero, grid2, grid1, NULL, 1);
	/* set the not_done grid */
	not_done[0][0] = 1;
	/* zero the topple grid */
	iterate(add_check_zero, topple, NULL, topple, 3);
	/* while not done */
	while (not_done[0][0])
	{
		/* get the topples */
		iterate(get_do_topples, grid1, NULL, topple, 1);
		/* set not done to 0 */
		not_done[0][0] = 0;
		/* check if done */
		iterate(add_check_zero, topple, NULL, not_done, 2);
		/* if not done */
		if (not_done[0][0])
			/* print grid */
			my_print(grid1);
		/* do the topples */
		iterate(get_do_topples, grid1, grid1, topple, 2);
		/* zero the topple grid */
		iterate(add_check_zero, topple, NULL, topple, 3);
	}
}
