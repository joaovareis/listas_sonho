def weighted_average(*args):

    """
    Calculates the weighted average of a set of arguments.

    Args:
        *args(tuple): (value, weight).

    Returns:
        float: Weighted average.

    Raises:
        TypeError: If the elements inside the tuples are not int or float.
        ValueError: If a tuple does not contain exactly 2 elements (value, weight).
        ZeroDivisionError: If the sum of all weights is zero. 
    """

    weight = 0
    total = 0
    w_average = 0

    for item in args:

        if isinstance(item, tuple):
            try:

                valor, peso = item 

                if isinstance(valor, (int, float)) and isinstance(peso, (int, float)):

                    total += valor*peso
                    weight += peso

            except Exception as e: print(f"[ERROR]: {e}")

    try: w_average = total/weight

    except Exception as e: print(f"[ERROR]: {e}")
    
    return w_average

a, b, c, d, e, f, g= (11, 1), (1, 2), (3, 4), (1, 2), (11, "cachorro"), ("bola", 2), (11, 3, 4) #8*1 + 1*2 + 3*4 + 1*2 / 1 + 2 + 4 + 2 = 27/9 = 3

print(weighted_average(a, b, c, d, e, f, g))