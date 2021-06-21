class persona:
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad

    def hablar(self):
        return f'Hola soy {self.nombre} y tengo {self.edad} anios'

class arquitecto(persona):
    def __init__(self, nombre, edad):
        super().__init__(nombre, edad)

    def presentar(self):
        return f'Soy arquitecto y uso un casco'

class doctor(persona):
    def __init__(self, nombre, edad):
        super().__init__(nombre, edad)

    def presentar(self):
        return f'Soy doctor y uso una bata'

if __name__ == '__main__':
    per = persona('Juan', '29')
    print(per.hablar())

    perAr = arquitecto('Hector', '30')
    print(perAr.hablar(), perAr.presentar())

    perDoc = doctor('Felipe', '25')
    print(perDoc.hablar(), perDoc.presentar())
