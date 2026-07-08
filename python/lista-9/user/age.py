def check_age(name:str, age: int) -> None:

    try:

        if age<0:
            raise ValueError("[ERRO]: Idade negativa fornecida")
        
        elif age >= 18:
            print(f"Parabens, {name}, você é de maior")

        else: print(f"Infelizmente, {name}, você é menor")

    except Exception as e: print(e)