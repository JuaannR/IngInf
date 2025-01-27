def AnoBisiesto (x):
    if x%4 == 0 and (x%100 != 0 or x%400 == 0):
        print(f'El año {x} es bisiesto')
    else:
        print(f'El año {x} no es bisiesto')
a = int(input('Introduce un año: '))
AnoBisiesto(a)
#Divisible por 4 y no por 100 -> Bisiesto
#Divisible por 100 y 400 -> Bisiesto