from itertools import product

xs = [1,2,3,4]
ys = [1,2]

prod_c = [
    x*y 
    for x in xs 
    for y in ys 
    if x==y
]
print(prod_c)

prod_c2 = [
    x*y for x,y in product(xs, ys) 
    if (x+y)%2==0
]
print(prod_c2)