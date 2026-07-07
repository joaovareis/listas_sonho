name = str(input("Digite o nome do robo: "))
vel = float(input("Digite a velocidade atual: "))
batt = float(input("Digite o nivel da bateria: "))
ope = str(input("Digite o modo de operação: "))

print(f"{"":=^40}")
print(f"{"STATUS DO ROBÔ":^40}")
print(f"{"":=^40}")

print(f"Robô: {name}")
print(f"Velocidade atual: {vel:.2f} m/s")
print(f"Bateria: {batt:.0f} %")
print(f"Modo de operação: {ope}")

print(f"{"":=^40}")