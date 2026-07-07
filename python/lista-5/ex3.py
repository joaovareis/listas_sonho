age = int(input("Digite a idade: "))

if (age < 0):

    print("Valor inválido (menor que zero)")

elif (age < 13):

    print("Parabens voce é uma criança")

elif (12 < age < 18):

    print("Parabens voce é adolescente")

elif (17 < age < 60):

    print("Parabens voce é adulto")

else:

    print("Parabens voce é idoso")