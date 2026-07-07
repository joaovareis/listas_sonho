import math

R = float(input("Digite o raio: "))
h = float(input("Digite a altura: "))

r_quadrado = (2*R*h) - (h**2)
area_secao = math.pi * r_quadrado
volume_calota = (math.pi * (h**2) * (3*R- h)) / 3

print(f"A area da secao é {area_secao}")
print(f"O volume da calota é {volume_calota}")