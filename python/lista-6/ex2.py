distancias = [1.5, 2.0, 0.8, 3.2, 1.1]

print(f"O menor objeto é {min(distancias)}")
print(f"O maior objeto é {max(distancias)}")

n = 0

for d in distancias:
    if d < 1:
        n += 1

print(f"Existem {n} objetos a menos de um metro")
