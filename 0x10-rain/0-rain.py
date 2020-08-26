#!/usr/bin/python3
""" Check how much rainfall is caught by an array """


def rain(walls):
    """ Check how much rain will stay within the array walls """

    if type(walls) is not list or len(walls) <= 2:
        return 0

    for x in walls:
        if x < 0:
            return 0

    extra = [[0, 0, x] for x in walls]

    left_max = 0

    for y in extra:
        y[0] = left_max
        if y[2] > left_max:
            left_max = y[2]

    extra.reverse()

    right_max = 0

    for z in extra:
        z[1] = right_max
        if z[2] > right_max:
            right_max = z[2]

    total = 0
    for a in extra:
        tmp = min(a[0], a[1]) - a[2]
        if tmp > 0:
            total = total + tmp

    return total
