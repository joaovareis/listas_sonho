ang = 0

for i in range(3):
    ang += float(input(f"Insira o ângulo {i+1}: "))

if ang != 180:
    print("Não forma um triangulo")
else: print("Parabens é um triangulo")