import random

sujetos = ["Ivan", "Alonso", "Esmeralda", "Sophia", "Jessica", "Miranda", "Karla", "Dayanna", "Karen", "Isaac", "Hector", "Kassandra"]
pronombresF = ["la", "las"]
pronombresM = ["el", "los", "lo"]
verbos = ["compra", "maneja", "corre", "come", "toma", "bebe", "rompe", "ejecuta", "cancela"]
objetos = ["computadora", "taza", "pantalla", "carro", "telefono", "silla", "gato", "perro"]

objetoss = random.choice(objetos)
print(random.choice(sujetos)  +" " +random.choice(verbos) + " " + (pronombresF[0] if objetoss[len(objetoss)-1] == "a" else pronombresM[0]) + " " +objetoss)
