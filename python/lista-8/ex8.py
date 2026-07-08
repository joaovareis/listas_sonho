import math

def warpToPi(ang:float):

    if ang < 0:

        return -(ang % math.pi)
    
    else: return ang % math.pi

print(warpToPi(3*math.pi))
print(warpToPi(-2.5*math.pi))
