from ex1.math_utils import is_even, add_numbers
from user.age import check_age


a = float(input("Insira o primeiro número a ser somado: "))
b = float(input("Insira o segundo número a ser somado: "))

print(f"O resultado é {add_numbers(a,b)}")

c = int(input("Insira o número a ser determinado se é par: "))

print(f"O resultado é {is_even(c)}")

name = str(input("Digite seu nome: "))
age = int(input("Digite sua idade: "))

check_age(name, age)