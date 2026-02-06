lista = [1,2,3,4,5,6,7,8,9,10]

# Filtrar apenas numeros pares
pares = list(filter(lambda x: x%2==0, lista))
print(pares)

quadrados = list(map(lambda x: x**2, lista))
print(quadrados)


