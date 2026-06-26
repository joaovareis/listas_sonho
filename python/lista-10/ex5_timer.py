import time

def in_execution(function):

    """
    A decorator that logs the time needed for a function execution.

    Args:
        function (callable): The function to be decorated.

    Returns:
        callable: The wrapped function with logging behavior.
    """
    
    def wrapper(*args, **kwargs):

        start = time.time()

        function(*args, **kwargs)
        finish = time.time()

        print(f"O tempo de execução foi {finish - start:.3f}s")

    return wrapper

@in_execution
def hello_wait_world():

    time.sleep(5)

    print("Hello World")

hello_wait_world()