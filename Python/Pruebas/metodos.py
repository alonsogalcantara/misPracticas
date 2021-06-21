class ejemplo:

    def __init__(self):
        self.atributo1 = 'Hola'
        print(self.atributo1)

    def multiplicacion(num1, num2):
        return num1*num2

    def meto1():

        def metodo2():
            return 'Hey'

        return metodo2()


print(ejemplo.meto1())
