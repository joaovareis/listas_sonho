import math

r = 2
ang = [i*math.pi/18 for i in range(36)]

steps = [(round(r*math.cos(ang[i]), 2), round(r*math.sin(ang[i]), 2)) for i in range(36)]

primeiros_5 = steps[:5]

ultimos_5 = steps[-5:]

print(primeiros_5, ultimos_5)