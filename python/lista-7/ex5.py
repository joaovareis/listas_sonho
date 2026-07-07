input = "robo aprende aprende rapido"

sepr = input.split()

contagem = {}

for w in sepr:

    contagem[w] = contagem.get(w, 0) + 1

print(contagem)
