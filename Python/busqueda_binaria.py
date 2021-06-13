import random

def burbuja(a = list()):
    '''Ordena de menor a mayor una lista dada
    Regresa la msima lista ya ordenada'''
    for i in range(1, len(a)):
        for j in range(0, len(a)-i):
            if(a[j+1] < a[j]):
                aux = a[j]
                a[j] = a[j+1]
                a[j+1] = aux
    return a

def busqueda_binaria(lista=list(), comienzo=0, final=0, objetivo=0):
    if comienzo > final:#Evita que la recursion sea infitina
        return False
    elif comienzo == final:
        return False

    print(f'Buscando {objetivo} entre {lista[comienzo]} y {lista[final-1]}')

    medio = (comienzo+final) // 2 #Obtiene la mitad de la lista

    if lista[medio] == objetivo: #Compara si el objetivo de la busqueda es igual a la mitad
        return True
    elif lista[medio] < objetivo:#Compara si el objetivo de la busqueda es menor a la mitad
        return busqueda_binaria(lista=lista, comienzo=medio + 1, final=final, objetivo=objetivo)
    else: # Compara si el objetivo de la busqueda es mayor a la mitad / si no son los otras dos opciones
        return busqueda_binaria(lista=lista, comienzo=comienzo, final=medio - 1, objetivo=objetivo)
    pass

if __name__ == '__main__':
    a = [random.randint(0, 10) for i in range(0, 10)]
    objetivo = random.randint(0,10)
    print(f'Buscando {objetivo} en la lista {burbuja(a)}')
    print('Se encontro el objetivo' if busqueda_binaria(lista=burbuja(a), comienzo=0, final=len(burbuja(a)), objetivo=objetivo) else 'No se encontro el objetivo')
