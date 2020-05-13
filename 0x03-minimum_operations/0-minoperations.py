#!/usr/bin/python3
"""This module is for the minimum operations problem"""


import math


def getFactor(n):
    """Get the smallest factor of n"""
    for x in range(2, math.ceil(math.sqrt(n + 1))):
        if n % x == 0:
            return x
    return 0


def minOpRec(n, acc):
    """Recursive solution to the minOp problem"""
    factor = getFactor(n)
    if factor == 0:
        return acc + n
    return minOpRec((n // factor), acc + factor)


def minOperations(n):
    """Find the min operations to get from 1 to n using copy and paste"""
    if type(n) is not int or n < 2:
        return 0

    return minOpRec(n, 0)
