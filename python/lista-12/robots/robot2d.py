class Robot2D:

    def __init__(self, **kwargs):

        self.name: str = kwargs.get('name')
        self.__pos : list[float, float, float] = [kwargs.get('x'), 
                                                  kwargs.get('y'), 
                                                  kwargs.get('theta')]
        
    def move(self, dx:float, dy:float, dtheta:float):

        self.__pos[0] += dx
        self.__pos[1] += dy
        self.__pos[2] += dtheta

    def get_pos(self):

        return self.__pos
    
    def _euclidian_distance(self, pos1, pos2):

        dist = ((pos2[0]-pos1[0])**2 + (pos2[1]-pos1[1])**2)**(1/2)

        return dist
    
    def distance_to_origin(self):

        dist = self._euclidian_distance(self.__pos, [0, 0, 0])

        return dist
    
    def distance_to_point(self, point_pos):

        dist = self._euclidian_distance(self.__pos, point_pos)

        return dist
    
    def __repr__(self):

        return f"Nome: {self.name}\nPosição em x: {self.__pos[0]}\nPosição em y: {self.__pos[1]}\nPosição em z: {self.__pos[2]}"

if __name__ == "__main__":
    
    r1 = Robot2D(name = 'Mettaton', x=0.0, y=0.0, theta=0.0)

    r1.move(3, 4, 90)
    
    print(f"A posição é (x, y, theta): {r1.get_pos()}")

    print(f"A distancia até a origem é: {r1.distance_to_origin()}")

    print(f"A distâncias até o ponto (4, 3) é: {r1.distance_to_point([4, 3])}")

    print(r1)

    try: print(r1._euclidian_distance(r1.__pos, [0, 0, 0]))
    except Exception as e: print(f"[ERRO]: {e}")

