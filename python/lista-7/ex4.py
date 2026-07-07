str1 = sorted(str(input("Digite a primeira string: ")))
str2 = sorted(str(input("Digite a segunda string: ")))

contagem = {}
validador = 0

for l in str1:
    
    contagem[l] = contagem.get(l, 0) + 1

for l in str2:

    contagem[l] = contagem.get(l, 0) - 1

for c in contagem:

    if contagem[c] == -1:

        validador +=1

if validador > 0: 
    print("Não é um anagrama")
else: print("Parabens, é um anagrama")