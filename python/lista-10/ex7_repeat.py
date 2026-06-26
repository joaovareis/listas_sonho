def repeat(n):
    """
    A decorator that repeats a function "n" times.

    Args:
        function (callable): The function to be decorated.
        n (int): The number of times the function must be executed.

    Returns:
        callable: The wrapped function with logging behavior.
    """
    def mid_decorator(function):

        def wrapper(*args, **kwargs):

            for _ in range(n):
                function(*args, **kwargs)

        return wrapper
    
    return mid_decorator

@repeat(3)
def hello_world():

    print("Hello World")

hello_world()
