#!/usr/bin/python3
"""This module is for the minimum operations problem"""


def getFactor(n):
    """Get the largest factor of n"""
    if n == 1:
        return 1
    for x in range(n-1, 0, -1):
        if n % x == 0:
            return x


def minOperations(n):
    """Find the min operations to get from 1 to n using copy and paste"""
    if type(n) is not int or n < 2:
        return 0

    return minOpRec(n, 0)



def minOpRec(n, acc):
    """Recursive solution to the minOp problem"""
    if n == 1:
        return 0
    factor = getFactor(n)
    if factor == 1:
        return acc + n
    return minOpRec(factor, acc + (n // factor))
