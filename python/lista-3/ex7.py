x  = 1.0
tol = 1e-6
it = 100

for i in range (it):

    if abs(x**2 - 2) < tol:
        break

    else: x -= (x**2 - 2) / (2 * x)

print(x)