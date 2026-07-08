def add_numbers(a: float, b: float) -> float:
    """
    Sum a and b.

    Args:
    a (float): First number
    b (float): Second number

    Returns:
    float: Result of the sum

    Raises:
    TypeError: If a or b aren't float or int. 

    """
    return a + b

def is_even(number: int) -> bool:

    """
    Detects if a number is even

    Args:
    number (int): The number to be determined if it's even.

    Returns:
    bool: Result of the evaluation

    Raises:
    TypeError: If number isn't a int.

    """
    if number % 2 == 0:
        return True
    else: return False

