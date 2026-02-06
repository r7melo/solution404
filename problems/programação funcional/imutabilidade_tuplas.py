tupla = ('romario', 'carlos', 'roberto', 'josé')

n_tupla = tuple(sorted(map(lambda v: v.upper(), tupla)))

print(tupla, n_tupla)