
VERDADEIRO = lambda x,y:x
FALSO      = lambda x,y:y
IF         = lambda cond, f1, f2: cond(f1, f2)

print(IF(VERDADEIRO, 10, 5)) 
print(IF(FALSO, 10, 5))


lista = [1,2,3]
# 1 + (2 + (3 + 0))
# f(1, f(2, f(3, f(0))))


somador = lambda x: lambda acc: somador(acc) + x
# somador = /x acc -> somador(acc) + x

s1 = somador(2)
# s1 = /acc -> somador(acc) + 2
# s1 = /acc -> (/x acc -> somador(acc) + x x) + 2

s2 = s1(4)
# s2 = /acc -> somador(acc) + 2



