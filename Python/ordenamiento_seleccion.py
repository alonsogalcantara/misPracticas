import random

def ordenamiento_Seleccion(a=list()):
    for i in range(len(a)-1, 0, -1):
        posicion_Mayor=0
        for j in range(1, i+1):
            if a[j]>a[posicion_Mayor]:
                print(f'{a[j]}>{a[posicion_Mayor]}')
                posicion_Mayor = j

            print(f'{a}')
        aux = a[i]
        a[i] = a[posicion_Mayor]
        a[posicion_Mayor] = aux
        #print(f'{a[posicion_Mayor]}, {i}')
    return a

if __name__ == '__main__':
    a = [random.randint(0, 100) for i in range(10)]
    print(a)
    print(ordenamiento_Seleccion(a))
