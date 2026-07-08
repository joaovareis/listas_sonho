import math

def distance(p1:tuple, p2:tuple):

    dist = math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

    return dist

print(distance((0, 3), (0, 4)))

print(distance((1, 2), (4, 6)))