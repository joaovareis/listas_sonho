import math

num = [1, 2, 3, 4, 5, 6, 7, 8, 9]
par = set()
impar = set()
primo = set()

def e_primo(n):
    if n <= 1:
        return False
    
    if n == 2:
        return True
    
    if n % 2 == 0:
        return False
    
    raiz = int(math.sqrt(n))
    for i in range(3, raiz + 1, 2):
        if n % i == 0:
            return False
            
    return True

for n in num:
    if e_primo(n):
        primo.append(n)
    
    if n%2 == 0:
        par.append(n)
    
    else: impar.append(n) #poderia usar o set para encontrar a diferença com o set dos impares e primos e o set contendo todos

print(primo, par, impar)