def calculator(*args):

    """
    Perform a multiplication or sum of the received arguments, depending on the first

    Args:
        *args (tuple): Operation (string) followed by values (float) to be used

    Returns:
        (float): The value returned by perfoming the operation solicited

    Raises:
        TypeError: If the first element is not an operation (string) or the following aren't numbers.
    """

    operation = args[0]
    values = args[1:]

    if not all(isinstance(val, (int, float)) for val in values):
        raise TypeError("All arguments after the operation must be numbers.")

    match operation:

        case "sum":
            print(sum(values))

        case "multi":
            total = 1
            for val in values: total *= val
            print(total)

        case _:
            raise TypeError(f"Expected operation 'sum' or 'multi' but received '{args[0]}'")

calculator("sum", 1, 2, 3)
calculator("multi", 2, 3, 4)
