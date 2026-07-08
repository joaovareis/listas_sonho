def calculate_average(g1: float, g2: float) -> float:

    """
    Calculates the average between two floats

    Args:
    gq (float): First number
    g2 (float): Second number

    Returns:
    float: Result of the mean.

    Raises:
    ValueError: If a or b are negative

    """


    if g1 < 0 or g2 < 0: 
        
        raise ValueError("Valor negativo")

    else: return (g1 + g2)/2

def divide_numbers(a: float, b: float) -> float:

    try:

        return a/b

    except ZeroDivisionError as e: 
        
        print(f"[ERRO] {e}")
        return 0.0