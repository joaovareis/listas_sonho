def log_func(function):
    """
    A decorator that explicitly prints the function received arguments.

    Args:
        function (callable): The function to be decorated.

    Returns:
        callable: The wrapped function with logging behavior.
    """
    def wrapper(*args, **kwargs):

        print(f"Argumentos posicionais: {args}")
        print(f"Argumentos nomeados: {kwargs}")

        function(*args, **kwargs)

    return wrapper


@log_func
def hello_world(*args, **kwargs):

    print("Hello World")

hello_world(1, 2, nome="Pedro")
