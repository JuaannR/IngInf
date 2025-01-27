import random
aleatorio = random.randint(1,10)

n = int(input('Estoy pensando en un número del 1 al 10, intenta adivinarlo: '))

while n != aleatorio:
    if aleatorio < n:
        print('El número es mas pequeño. Prueba otra vez')
    elif aleatorio > n:
        print('El número es mas grande. Prueba otra vez')
    n = int(input('Intentalo de nuevo: '))
print('¡Ganaste!')
