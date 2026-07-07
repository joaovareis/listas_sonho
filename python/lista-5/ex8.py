num = int(input("Digite o número que deseja encontar a raiz: "))
tol = float(input("Digite a tolerancia: "))
it = int(input("Digite o número de iterações: "))

x  = 1.0

for i in range (it):

    if abs(x**2 - num) < tol:
        break

    else: x -= (x**2 - num) / (num * x)

print(x)