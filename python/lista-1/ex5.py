num = int(input("Digite o número: "))

c = int(num/100)
d = int((num - c * 100)/10)
u = num - c*100 - d*10

print(c, d, u)