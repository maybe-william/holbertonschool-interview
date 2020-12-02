#!/usr/bin/python3
"""This module checks the perimeter of an island"""


def island_perimeter(grid):
    """Get the perimeter of an island without lakes"""

    def oob(point, grid):
        """Check if a point is out of bounds"""
        if point[0] < 0 or point[0] >= len(grid):
            return True
        if point[1] < 0 or point[1] >= len(grid[0]):
            return True
        return False

    def empty(point):
        """Check if a point is empty"""
        if oob(point, grid) or grid[point[0]][point[1]] == 0:
            return True
        return False

    def move(point, direction):
        """Return a new point moved in a direction"""
        return (point[0] + direction[0], point[1] + direction[1])

    if len(grid) == 0 or len(grid[0]) == 0:
        return 0

    t = (1, 0)
    r = (0, 1)
    b = (-1, 0)
    l = (0, -1)
    dirs = [t, r, b, l]

    startDir = 0
    startPoint = -1

    foundStart = False
    for y in range(len(grid)):
        if not foundStart:
            for x in range(len(grid[y])):
                if not foundStart and grid[y][x] == 1:
                    for z in range(4):
                        if empty(move((y, x), dirs[z])):
                            startPoint = (y, x)
                            startDir = z
                            foundStart = True
                            break

    if startPoint == -1:
        return 0

    currentPoint = startPoint
    currentDirection = startDir

    perimeter = 0
    done = False
    while not done:
        if empty(move(currentPoint, dirs[currentDirection])):
            perimeter = perimeter + 1
            currentDirection = (currentDirection + 1) % 4
        else:
            currentPoint = move(currentPoint, dirs[currentDirection])
            currentDirection = (currentDirection + 3) % 4
        done = currentPoint == startPoint and currentDirection == startDir

    return perimeter
