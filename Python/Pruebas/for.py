def diccio():
    diccionario = {'nombre': 'Roberto', 'edad': '20'}
    
    print("Elementos de un diccionario")

    for elemento in diccionario.items():
        print(elemento)

def listaa():
    lis = [1, 2, 3, "Hola", 'Tu']
    print("Elementos de una lista")
    for elemento in lis:
        print(elemento)
        
diccio()
listaa()