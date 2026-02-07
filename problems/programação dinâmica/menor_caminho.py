N = 9

arestas = [
    (1, 2, 1), 
    (1, 3, 2), 
    (2, 4, 6), 
    (2, 5, 12),
    (3, 4, 3), 
    (3, 6, 4), 
    (4, 5, 4), 
    (4, 6, 3),
    (4, 7, 15), 
    (4, 8, 7), 
    (5, 7, 7), 
    (6, 8, 7),
    (6, 9, 15), 
    (7, 9, 3), 
    (8, 9, 10)
]

grafo = [[None]*(N+1) for _ in range(N+1)]

destinos_i0 = lambda i0: [i for i, x in enumerate(grafo[i0]) if x != None]

for u, v, w in arestas:
    grafo[u][v] = w

def melhor_caminho(i0, T, caminhada=None):

    if caminhada is None:
        caminhada = {'caminho':[i0], 'distancia':0}

    if i0 == T: 
        print(caminhada)
        return caminhada

    cmns = []
    for i1 in destinos_i0(i0):

        cmn = caminhada.copy()

        cmn['caminho'] = cmn['caminho'] + [i1]
        cmn['distancia'] = grafo[i0][i1] + cmn['distancia']
        cmns.append(melhor_caminho(i1, T, cmn))


    return min(cmns, key=lambda x: x['distancia'])
    



mc = melhor_caminho(1, 9)
print("Melhor Caminho ===")
print(mc)