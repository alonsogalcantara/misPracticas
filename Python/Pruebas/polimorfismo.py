class rectangulo:
    def __init__(self, base, altura):
        self.base=base
        self.altura=altura

    def area(self):
        return f'{self.base} * {self.altura} = {self.base*self.altura}'

class cuadrado(rectangulo):
    def __init__(self, lado):
        super().__init__(lado, lado)
        pass

if __name__ == '__main__':
    recArea = rectangulo(5, 2)
    print(recArea.area())

    cuaArea = cuadrado(5)
    print(cuaArea.area())
