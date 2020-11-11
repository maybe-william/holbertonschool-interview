#!/usr/bin/python3
"""Add up coins to a sum"""


def makeChange(coins, total):
    """Tell the number of coins required for a sum"""
    if total <= 0:
        return 0
    if len(coins) <= 0:
        return -1

    sc = sorted(coins)
    sc = sc[::-1]

    num = 0
    running = total
    for c in sc:
        while (running - c >= 0):
            running = running - c
            num = num + 1

    if running != 0 and running - sc[-1] < 0:
        return -1
    return num
