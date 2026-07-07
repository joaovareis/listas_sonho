ano = int(input("Digite o ano: "))

if ano % 400 == 0:
    print("Parabens é bissexto")

elif (ano % 100 == 0):

    print("Nao é bissexo")

elif (ano % 4 == 0):

    print("Parabens é bissexto")

else: print("Não é bissexo")