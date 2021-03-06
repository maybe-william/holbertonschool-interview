#!/usr/bin/python3
""" N-queens problem hard version """


import sys


def check_diagonal(grid, point, direction=True):
    """ check the diagonal for one point """
    x = point[0]
    y = point[1]
    size = len(grid)
    ones = 0
    while (x >= 0 and x < size and y >= 0 and y < size):
        ones = ones + grid[x][y]
        if direction:
            x = x+1
            y = y+1
        else:
            x = x-1
            y = y+1
        if ones > 1:
            return False
    return True


def check_valid(grid):
    """ check the validity of a grid """
    # check rows and columns
    for i in range(len(grid)):
        x = 0
        y = 0
        for j in range(len(grid)):
            x = x + grid[i][j]
            y = y + grid[j][i]
        if x > 1 or y > 1:
            return False

    # check diagonals to bottom-right
    for k in range(len(grid)):
        pt1 = [0, k]
        pt2 = [k, 0]
        good = (check_diagonal(grid, pt1) and check_diagonal(grid, pt2))
        if not good:
            return False

    # check diagonals to bottom-left
    for i2 in range(len(grid)):
        pt1 = [len(grid) - 1, i2]
        pt2 = [len(grid) - 1 - i2, 0]
        good = check_diagonal(grid, pt1, False)
        good = (good and check_diagonal(grid, pt2, False))
        if not good:
            return False
    return True


def get_solutions(size, grid, col=0, solutions=[], acc=[]):
    """ recursively build solutions """
    if col == size:
        solutions.append(acc[:])
        return solutions
    for i in range(size):
        grid[col][i] = 1
        if (check_valid(grid)):
            # add point to acc
            pt = [col, i]
            acc.append(pt)

            get_solutions(size, grid, col+1, solutions, acc)
            # remove point from acc
            acc.remove(pt)
        # remove one from grid
        grid[col][i] = 0

    return solutions


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    size = 0
    try:
        size = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)
    if size < 4:
        print("N must be at least 4")
        exit(1)

    grid = []
    for i in range(size):
        grid.append([])
        for j in range(size):
            grid[-1].append(0)

    for s in get_solutions(size, grid):
        print(s)
