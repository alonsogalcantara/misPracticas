import random

def ordenamientoPorInsercion(a = list()):
   for i in range(1,len(a)):
     aux = a[i]
     posicion = i

     while posicion>0 and a[posicion-1]>aux:
         a[posicion]=a[posicion-1]
         posicion = posicion-1

     a[posicion]=aux

if __name__ == '__main__':
    a = [random.randint(0, 10) for i in range(10)]
    print(a)
    ordenamientoPorInsercion(a)
    print(a)
