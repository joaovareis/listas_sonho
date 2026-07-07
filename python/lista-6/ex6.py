estimado = [(0,0), (1,1), (2,2), (3,3)]
real = [(0,0), (1,0.8), (2.2,2.1), (2.9,3.2)]

erro = []

for i in range(len(real)):
    
    e = (((estimado[i][1] - real[i][1])**2) + ((estimado[i][0] - real[i][0])**2))**(1/2)

    erro.append(e)

print(erro)