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
    
nomes = ["Vasculhador", "Drone", "Foguete", "Setembro"]

lista_robos = [Robot(name = nome) for nome in nomes]

for indice, robo in enumerate(lista_robos):
    robo.move(indice, indice+1) #Poderia ser utilizado random.randint(a, b) para ser aleatório, mas assim dá pra conferir o resultado

for robo in lista_robos:
    print(f"{robo}\n{robo.distance_to_origin()}\n")
