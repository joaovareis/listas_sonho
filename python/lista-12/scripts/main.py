from robots.wheeled_robot import WheeledRobot

r1 = WheeledRobot(name = 'Chapisco', x=0.0, y=0.0, theta=0.0, wheel_radius = 3)

#===================
#       Ex1
#===================

print("\nEx1 ------------------\n")

r1.move(3, 4, 90)

print(f"A posição é (x, y, theta): {r1.get_pos()}")
print(f"A distancia até a origem é: {r1.distance_to_origin()}")
print(f"A distâncias até o ponto (4, 3) é: {r1.distance_to_point([4, 3])}")

print(r1)

try: print(r1._euclidian_distance(r1.__pos, [0, 0, 0]))
except Exception as e: print(f"[ERRO]: {e}")

print("\n")

#===================
#       Ex2
#===================

print("Ex2 ------------------\n")

r1.camera.take_picture()
r1.camera.rec(3.1415)

print(f"A camera tem dimensão {r1.camera.get_image_size()}")

print(f"Num pontos do Lidar: {r1.lidar.get_num_points()}")
print(f"Resolução Lidar: {r1.lidar.get_resolution()}")
print(f"Range Lidar: {r1.lidar.get_range()}")

r1.lidar.set_num_points(200)
r1.lidar.set_range((-50, 50))

print(f"Num pontos do Lidar: {r1.lidar.get_num_points()}")
print(f"Resolução Lidar: {r1.lidar.get_resolution()}")
print(f"Range Lidar: {r1.lidar.get_range()}")

print("\n")

#===================
#       Ex3
#===================

print("Ex3 ------------------\n")

print(f"Distancia percorrida: {r1.distance_from_revolutions(2)}")

r1.set_wheel_radius(5)
print(f"Distancia percorrida: {r1.distance_from_revolutions(2)}")

print(f"Sensores: {r1.sensors()}")
