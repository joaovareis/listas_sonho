x0 = 0
v0 = 1.0
a = 0.5
dt = 0.1
tempo_total = 2.0

passos = int(tempo_total / dt) + 1

tempos = [round(i*dt, 1) for i in range(passos)]

pos = [round(x0 + (v0 * t) + (a*(t**2)/2), 2) for t in tempos]

print(pos)