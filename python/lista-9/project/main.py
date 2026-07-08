from school.grades import calculate_average, divide_numbers

g1 = int(input("Digite a primeira nota: "))
g2 = int(input("Digite a segunda nota: "))

try:
    
    calculate_average(g1, g2)

except Exception as e: print(f"[ERRO] {e}")

n1 = int(input("Digite o primeiro numero a ser dividido: "))
n2 = int(input("Digite o segundo numero a ser dividido: "))

print(f"O resultado da divisão é {divide_numbers(n1, n2)}")
