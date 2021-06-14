def division(num1, num2):
    return num1 / num2

def multiplicacion(num1, num2):
    return num1*num2

while True:
    try:
        div = division(a, b)
        multi = multiplicacion(a, b)
    except Exception as e: #Si el programa encuentra fallos
        print(e, 'Se le va a asignar valores')
        a = 5
        b = 5
    else: #Continua en el dado caso que no encuentre fallos
        print('No error')
        print(div+multi)
        break
