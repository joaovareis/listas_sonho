a = int(input("Insira o coeficiente a: "))
b = int(input("Insira o coeficiente b: "))
c = int(input("Insira o coeficiente c: "))

delta = (b ** 2) - 4 * a * c

root1 = (-b + delta**(1/2)) / (2*a)

root2 = (-b - delta**(1/2)) / (2*a)

if root1 == root2:

    print(f"Raiz unica: {root1}")

else: print(f"Raiz 1: {root1}, Raiz 2: {root2}")

