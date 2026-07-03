from robots.robot2d import Robot2D
from sensors.lidar import Lidar
from sensors.camera import Camera

class RobotWithCamera(Robot2D):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.camera = Camera((200, 200))

    def sensors(self):

        return self.camera
    
class RobotWithLidar(Robot2D):

    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        self.lidar = Lidar(num_points = 180, range = (-90, 90))

    def sensors(self):

        return self.lidar

if __name__ == "__main__":

    r1 = RobotWithCamera(name = 'Chapisco', x=0.0, y=0.0, theta=0.0)

    r1.camera.take_picture()
    r1.camera.rec(3.1415)

    print(f"A camera tem dimensão {r1.camera.get_image_size()}")

    r1.move(3, 4, 90)
    
    print(f"A posição é (x, y, theta): {r1.get_pos()}")

    print(f"A distancia até a origem é: {r1.distance_to_origin()}")

    print(f"A distâncias até o ponto (4, 3) é: {r1.distance_to_point([4, 3])}")

    print(r1)

    try: print(r1._euclidian_distance(r1.__pos, [0, 0, 0]))
    except Exception as e: print(f"[ERRO]: {e}")

    print(f"Sensores: {r1.sensors()}")

    r2 = RobotWithLidar(name = 'Mettaton', x=0.0, y=0.0, theta=0.0)

    print(f"Num pontos do Lidar: {r2.lidar.get_num_points()}")
    print(f"Resolução Lidar: {r2.lidar.get_resolution()}")
    print(f"Range Lidar: {r2.lidar.get_range()}")

    r2.lidar.set_num_points(200)
    r2.lidar.set_range((-50, 50))

    print(f"Num pontos do Lidar: {r2.lidar.get_num_points()}")
    print(f"Resolução Lidar: {r2.lidar.get_resolution()}")
    print(f"Range Lidar: {r2.lidar.get_range()}")

    r2.move(3, 4, 90)
    
    print(f"A posição é (x, y, theta): {r2.get_pos()}")

    print(f"A distancia até a origem é: {r2.distance_to_origin()}")

    print(f"A distâncias até o ponto (4, 3) é: {r2.distance_to_point([4, 3])}")

    print(r2)

    try: print(r2._euclidian_distance(r2.__pos, [0, 0, 0]))
    except Exception as e: print(f"[ERRO]: {e}")

    print(f"Sensores: {r2.sensors()}")