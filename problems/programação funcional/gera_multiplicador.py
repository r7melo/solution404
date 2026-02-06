
gera_multiplicador = lambda n: lambda x: x*n

dobrar = gera_multiplicador(2)

r = dobrar(5)

print(r)