opt = int(input("Digite a opção: "))

match opt:
    case 1: print("Iniciar sistema")
    case 2: print("Configurações")
    case 3: print("Ajuda")
    case 4: print("Encerrar sistema")
    case _: print("Opcao inválida")
    