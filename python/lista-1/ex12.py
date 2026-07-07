import math

v0 = float(input("Digite v0: "))
theta = float(input("Digite o ângulo: "))

g = 9.81

R = (v0**2) * math.sin(2*theta) / g

print(f"O alcance é {R} m")