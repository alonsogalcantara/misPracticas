def factorial(x):
    if x == 1:
        return 1
    else:
        return x * factorial(x-1)

def fibo1(number):
    if number == 0:
        return 0
    elif number == 1:
        return 1
    else:
        return fibo1(number-1) + fibo1(number-2)


x=10
for i in range(0, x):
    print(fibo1(i))

#print(fibo1(x))
