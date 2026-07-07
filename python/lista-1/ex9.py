import math

r = float(input("Insira o raio da esfera: "))

vol = (r**3) * 4 * math.pi / 3
surf = (r**2) * 4 * math.pi

print(f"O volume é {vol} e a área é {surf}")