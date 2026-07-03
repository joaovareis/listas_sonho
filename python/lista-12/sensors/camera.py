class Camera:
    def __init__(self, *args):

        self._image_size: tuple[int, int] = args[0] if args else (0, 0)
    
    def take_picture(self):

        print("Tirei foto")

    def rec(self, sec:float):

        print(f"Gravei por {sec:.2f} segundos")

    def get_image_size(self):

        return self._image_size

if __name__ == "__main__":

    c1 = Camera((10, 100))
    c1.take_picture()
    c1.rec(3.1415)

    print(f"A camera tem dimensão {c1.get_image_size()}")