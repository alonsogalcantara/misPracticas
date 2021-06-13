class arbol_binario:
    '''Arbol binario'''

    def __init__(self, root=str()):
        '''Crea una nueva instancia de un arbol'''
        self.root = root
        self.hijo_izq = None
        self.hijo_der = None
        pass

    def get_hijo_izq(self):
        '''Devuelve el arbol binario correspondiente al hijo izquierdo del nodo actual.'''
        return self.hijo_izq
        pass

    def get_hijo_der(self):
        ''' Devuelve el arbol binario correspondiente al hijo derecho del nodo actual.'''
        return self.hijo_der
        pass

    def set_value(self, val=str()):
        '''Almacena el valor del parametro valor en el nodo actual.'''
        self.root = val
        pass

    def get_value(self):
        '''Devuelve el valor almacenado en el nodo actual.'''
        return self.root
        pass

    def create_hijo_izq(self, node):
        '''Crea un nuevo arbol binario y lo instala como el hijo izquierdo del nodo actual.'''
        if self.hijo_izq == None:
            self.hijo_izq = arbol_binario(node)
        else:
            t = arbol_binario(node)
            t.hijo_izq = self.hijo_izq
            self.hijo_izq = t
        pass

    def create_hijo_der(self, node):
        '''Crea un nuevo arbol binario y lo instala como el hijo derecho del nodo actual.'''
        if self.hijo_der == None:
            self.hijo_der = arbol_binario(node)
        else:
            t = arbol_binario(node)
            t.hijo_der = self.hijo_der
            self.hijo_der = t
        pass

    def preorden(self):
        '''Imprime el arbol en preorden'''
        print(self.root)
        if self.hijo_izq != None:
            self.hijo_izq.preorden()
        if self.hijo_der != None:
            self.hijo_der.preorden()
        pass

    def inorden(self):
        '''Imprime el arbol en inorden'''
        if self.hijo_izq:
            self.hijo_izq.inorden()
        print(self.root)
        if self.hijo_der != None:
            self.hijo_der.inorden()
        pass

    def postorden(self):
        '''Imprime el arbol en postorden'''
        if self.hijo_izq != None:
            self.hijo_izq.postorden()
        if self.hijo_der != None:
            self.hijo_der.postorden()
        print(self.root)
        pass

    pass

if __name__ == '__main__':
    arbol_Libro = arbol_binario('Libro')

    arbol_Libro.create_hijo_izq('Capitulo 1')
    arbol_Libro.create_hijo_der('Capitulo 2')

    arbol_Libro.get_hijo_izq().create_hijo_izq('Seccion 1.1')
    arbol_Libro.get_hijo_izq().create_hijo_der('Seccion 1.2')
    arbol_Libro.get_hijo_izq().get_hijo_der().create_hijo_izq('Seccion 1.2.1')
    arbol_Libro.get_hijo_izq().get_hijo_der().create_hijo_der('Seccion 1.2.2')

    arbol_Libro.get_hijo_der().create_hijo_izq('Seccion 2.1')
    arbol_Libro.get_hijo_der().create_hijo_der('Seccion 2.2')
    arbol_Libro.get_hijo_der().get_hijo_der().create_hijo_izq('Seccion 2.2.1')
    arbol_Libro.get_hijo_der().get_hijo_der().create_hijo_der('Seccion 2.2.2')

    #print('Preorden...')
    print(arbol_Libro.preorden())
