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

if __name__ == '__main__':
    a = [random.randint(0, 10) for i in range(0, 10)]
    print(f'Lista sin ordenar: {a}')
    print(f'Lista ordenada {burbuja(a)}')
