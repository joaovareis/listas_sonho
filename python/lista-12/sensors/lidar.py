class Lidar:
    def __init__(self, **kwargs):

        self.__num_points: int = kwargs.get('num_points')
        self.__range: tuple[float, float] = kwargs.get("range")
        self.__resolution: float = (self.__range[1] - self.__range[0]) / self.__num_points
    
    def read_lidar(self):

        print("Peguei dados do Lidar")

    def set_num_points(self, num:int):

        self.__num_points = num

        self.__resolution = (self.__range[1] - self.__range[0]) / self.__num_points

    def set_range(self, range:tuple[float, float]):

        self.__range = range

        self.__resolution = (self.__range[1] - self.__range[0]) / self.__num_points

    def get_resolution(self):

        return self.__resolution
    
    def get_range(self):

        return self.__range
    
    def get_num_points(self):

        return self.__num_points
    
if __name__ == "__main__":

    l1 = Lidar(num_points = 180, range = (-90, 90))

    print(f"Num pontos do Lidar: {l1.get_num_points()}")
    print(f"Resolução Lidar: {l1.get_resolution()}")
    print(f"Range Lidar: {l1.get_range()}")

    l1.set_num_points(200)
    l1.set_range((-50, 50))

    print(f"Num pontos do Lidar: {l1.get_num_points()}")
    print(f"Resolução Lidar: {l1.get_resolution()}")
    print(f"Range Lidar: {l1.get_range()}")

