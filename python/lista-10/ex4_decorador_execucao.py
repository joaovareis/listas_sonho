def in_execution(function):

    """
    A decorator that logs the start and end of a function's execution.

    Prints a message immediately before the decorated function runs 
    and another message immediately after it finishes.

    Args:
        function (callable): The function to be decorated.

    Returns:
        callable: The wrapped function with logging behavior.
    """
    
    def wrapper(*args, **kwargs):

        print("Iniciando função...")
        function(*args, **kwargs)
        print("Finalizando função...")

    return wrapper

@in_execution
def hello_world():

    print("Hello World")

hello_world()