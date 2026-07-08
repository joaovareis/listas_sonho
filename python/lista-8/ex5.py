import math

def is_prime(n:int):
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

print(is_prime(349))
print(is_prime(43))