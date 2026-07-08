comandos = [9, 10, 2, 5, 7, 9, 1]

def dobrar(l:list):

    return list(map(lambda x: x*2, l))

print(dobrar(comandos))