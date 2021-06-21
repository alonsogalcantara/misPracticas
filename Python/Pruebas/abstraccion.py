class carro:
    def __init__(self, color='negro'):
        self.color = color
        pass

    def encender_auto(self):
        print(f'El color del carro es {self.color}')
        self._encender_motor(estado = 'encendido')
        self._tanque()
        pass

    def _encender_motor(self, estado='apagado'):
        print(f'El motor esta {estado}')
        pass

    def _tanque(self, cantidad='lleno'):
        print(f'El tanque esta {cantidad}')
        pass

if __name__ == '__main__':
    carro1 = carro(color='blanco')
    carro1.encender_auto()

    carro2 = carro(color='rojo')
    carro2.encender_auto()
