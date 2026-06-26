def verify_login(function):

    """
    A decorator that detects if a boolean is true prior to execution

    Args:
        function (callable): The function to be decorated.

    Returns:
        callable: The wrapped function with logging behavior.
    """
    
    def wrapper(*args, **kwargs):

        if user_is_logged:
            function(*args, **kwargs)
        
        else: print("Acesso negado")

    return wrapper

@verify_login
def hello_world():

    print("Hello World")

user_is_logged = False

hello_world()

user_is_logged = True

hello_world()