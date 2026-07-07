forcas = [
("FL", 120),
("FR", 110),
("RL", 130),
("RR", 115)
]

floor = ('a', 0)
sum = 0

for f in forcas:

    if f[1] > floor[1]:
        floor = f

    sum += f[1]

print(f"Perna com maior força: {floor[0]}")
print(f"Valor: {floor[1]}")
print(f"A força média é: {sum/len(forcas)}")