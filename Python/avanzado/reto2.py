import math

# numeros no divisibles por 3


def main():
    return {i: i**3 for i in range(1, 101) if i % 3 != 0}


def reto():
    '''Los primeros 1000 numeros naturales como key
    y los valores su raiz cuadrada.'''
    return {i: '{0:.2f}'.format(math.sqrt(i)) for i in range(1, 1000)}


if __name__ == '__main__':
    print({i: '{0:.2f}'.format(math.sqrt(i)) for i in range(1, 1000)})
