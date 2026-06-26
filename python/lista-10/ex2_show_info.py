def show_info(**kwargs):

    """
    Shows the keys and values for the received kwargs..

    Args:
        **kwargs (dict): Colletion of items to be printed on the terminal.

    Returns:
        Printed arguments.
    """
    try:
        for chave, valor in kwargs.items():

            print(f"{chave}: {valor}")

    except Exception as e: print(f"[ERROR]: {e}")

show_info(name="João", age=20, course="Engenharia")