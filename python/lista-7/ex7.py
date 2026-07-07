num = (str(input("Digite os números em algarismo romano: ")).strip().lower().split())

letras = [list(n) for n in num]

tradutor = {'i': 1,
            'v': 5,
            'x': 10,
            'l': 50,
            'c': 100,
            'd': 500,
            'm': 1000}

traduzido = []

for lista_romano in letras:
    total = 0
    tamanho = len(lista_romano)
    
    for i in range(tamanho):
        valor_atual = tradutor[lista_romano[i]]
        
        if i + 1 < tamanho:
            valor_proximo = tradutor[lista_romano[i+1]]
            
            if valor_atual < valor_proximo:
                total -= valor_atual
            else:
                total += valor_atual
        else:
            total += valor_atual
            
    traduzido.append(total)

print(traduzido)