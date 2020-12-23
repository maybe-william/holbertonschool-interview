#!/usr/bin/python3
"""
pascal_triangle
"""


def pascal_triangle(n):
    """
    generate a series of arrays representing
    rows of pascal's triangle up to level n
    """
    if n <= 0:
        return []
    if n == 1:
        return [[1]]

    prev_tri = pascal_triangle(n - 1)
    last_row = prev_tri[-1]

    current_row = []
    acc = 0
    for x in last_row:
        current_row.append(acc + x)
        acc = x
    current_row.append(1)

    prev_tri.append(current_row)

    return prev_tri
