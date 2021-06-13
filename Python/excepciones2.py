def division(num1, num2):
    return num1 / num2

def multiplicacion(num1, num2):
    return num1*num2

while True:
    try:
        div = division(a, b)
        multi = multiplicacion(a, b)
        print(div)
        print(multi)
    except Exception as e:
        print(e, 'Se le va a asignar valores')
        a = 5
        b = 5
    else:
        print('No error')
        print(div+multi)
        break
