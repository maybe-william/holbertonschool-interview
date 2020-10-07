#!/usr/bin/python3
"""Rotates a 2d matrix"""


def swap(matrix, a, b):
    """swap two values"""
    matrix[a[0]][a[1]] = matrix[a[0]][a[1]] ^ matrix[b[0]][b[1]]
    matrix[b[0]][b[1]] = matrix[a[0]][a[1]] ^ matrix[b[0]][b[1]]
    matrix[a[0]][a[1]] = matrix[a[0]][a[1]] ^ matrix[b[0]][b[1]]


def rotate_2d_m(matrix):
    """flip diagonally, then flip horizontally for a clockwise rotation"""
    size = len(matrix)

    for x in range(size):
        for y in range(size):
            if x > y:
                swap(matrix, (x, y), (y, x))
    for y in range(size//2):
        for x in range(size):
            swap(matrix, (x, y), (x, size-y-1))
