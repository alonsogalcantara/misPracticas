class empleado:

    def __init__(self, nombre, apellido_p):
        self._nombre = nombre
        self._apellido_p = apellido_p

    @property
    def correo(self):
        return f'{self._nombre}_{self._apellido_p}@correo.com'

    @property
    def nombre_completo(self):
        return f'{self._nombre} {self._apellido_p}'

    @nombre_completo.setter
    def nombre_completo(self, nombre):
        nombre, apellido_p = nombre.split(' ')
        self._nombre = nombre
        self._apellido_p = apellido_p

if __name__ == '__main__':
    emp1 = empleado('Jesus', 'Gomez')
    emp1.nombre_completo = 'Gerardo Jimenez'
    print(emp1.nombre_completo)
    print(emp1.correo)
