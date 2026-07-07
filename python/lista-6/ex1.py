temperaturas = [32.1, 33.5, 34.0, 35.2, 36.1]
sum = 0

print(f"O primeiro item é {temperaturas[0]}")
print(f"O último item é {temperaturas[-1]}")

for i in range(len(temperaturas)):
    sum += temperaturas[i]

print(f"A média é {sum/len(temperaturas)}")


