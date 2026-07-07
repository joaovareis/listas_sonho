input = str(input("Digite sua string: ")).strip()

letras = [letra for letra in input if letra != " "]

contagem = {}

for l in letras:

    contagem[l] = contagem.get(l, 0) + 1

print(contagem)