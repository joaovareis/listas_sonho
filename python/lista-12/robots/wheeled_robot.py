from robots.robot_with_sensors import RobotWithCamera, RobotWithLidar
import math

class WheeledRobot(RobotWithCamera, RobotWithLidar):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.__wheel_radius: float = kwargs.get('wheel_radius')
        self.__circumference_func = lambda r: 2 * math.pi * r
        self.__wheel_circunference: float = self.__circumference_func(self.__wheel_radius)

    def set_wheel_radius(self, r:float):

        self.__wheel_radius = r
        self.__wheel_circunference = self.__circumference_func(self.__wheel_radius)

    def distance_from_revolutions(self, revolutions:float):

        dist = revolutions*self.__wheel_circunference

        return dist
    
    def sensors(self):
        super().sensors()
        
        return self.lidar, self.camera
    
if __name__ == "__main__":

    r1 = WheeledRobot(name = 'Chapisco', x=0.0, y=0.0, theta=0.0, wheel_radius = 3)

    print(f"Distancia percorrida: {r1.distance_from_revolutions(2)}")

    r1.set_wheel_radius(5)
    print(f"Distancia percorrida: {r1.distance_from_revolutions(2)}")

    print(f"Sensores: {r1.sensors()}")

