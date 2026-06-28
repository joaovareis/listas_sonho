class Robot:

    def __init__(self, **kwargs):

        self.name = kwargs.get('name')
        self.pos_x = kwargs.get('x', 0.0)
        self.pos_y = kwargs.get('y', 0.0)
        self.vel = kwargs.get('vel', 0.0)
        
    def move(self, dx, dy):

        self.pos_x += dx
        self.pos_y += dy

    def distance_to_origin(self):

        dist = (self.pos_x**2 + self.pos_y**2)**(1/2)

        return dist
    
    def __str__(self) -> str:

        return f"Nome: {self.name}\nPosição em x: {self.pos_x}\nPosição em y: {self.pos_y}"
    
class Fleet:

    def __init__(self):

        self.lista_robos = []

    def add_robot(self, **kwargs):

        self.lista_robos.append(Robot(**kwargs))

    def move_all(self, dx, dy):

        for robo in self.lista_robos:

            robo.move(dx*robo.vel, 0) #Somente no eixo x? Typo?

    def fleet_state(self):

        for robo in self.lista_robos:
            print(f"{robo}\n")        

frota = Fleet()

frota.add_robot(name="Alfredo", vel=10)
frota.add_robot(name="Primavera", vel=2)

frota.move_all(1, 10)

frota.fleet_state()