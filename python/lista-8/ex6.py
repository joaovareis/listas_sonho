def clamp_velocity(vel:float, lim:float):

    if vel > lim:
        return lim
    else: return vel

print(clamp_velocity(10, 5))
print(clamp_velocity(6, 12))