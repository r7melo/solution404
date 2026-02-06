from functools import reduce

lista = [1,2,4,8,4,2,3,4,5,9,7,3,1]

produto = reduce(lambda acc, x: acc*x, lista, initial=1)
print(produto)

maior = reduce(lambda x, y: x if x>y else y, lista)
print(maior)