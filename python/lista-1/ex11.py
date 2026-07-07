h1 = float(input("Digite h1: "))
h2 = float(input("Digite h2: "))

g = 9.81
v1 = 1.0

v2 = ((v1**2) + 2 * g * (h1 - h2))**(1/2)

print(f"O carrinho vai passar em h2 a {v2} m/s")