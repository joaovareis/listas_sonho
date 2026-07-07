temp_corpo = 80
temp_ambiente = 25
constante = 0.1
tempo = 0

while abs(temp_corpo - temp_ambiente) > 1:

    temp_corpo -= constante * (temp_corpo - temp_ambiente)

    if abs(temp_corpo - 40) < 1:

        print(f"Levou {tempo} segundos para o corpo atingir 40°")

    tempo += 1

print(f"Levou {tempo} segundos para o corpo atingir 0°")