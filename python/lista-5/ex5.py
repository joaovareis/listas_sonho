a = int(input("Insira o lado 1: "))
b = int(input("Insira o lado 2: "))
c = int(input("Insira o lado 3: "))

if ((a+b) <= c or (a+c) <= b or (b+c) <= a):

    print("Nao é um triangulo")

elif (a == b == c):

    print("Parabens é equilatero")

elif (a == b or b == c or c == a):

    print("Parabens é isosceles")

else: print("É escaleno")
