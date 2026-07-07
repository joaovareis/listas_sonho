pop = 500
growth = 0.03
loss = 10

for i in range(50):

    pop += (pop*0.03) - 10

    if pop > 1000:
        print(f"Limite de 1000 individuos atingidos: {pop:.0f}")
        break

if pop < 1000:

    print("As iterações foram completadas e não foi atingido o limite")