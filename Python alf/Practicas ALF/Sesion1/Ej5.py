import random
numeros = []        #array vacio

for _ in range(5):
    aleatorio = random.randint(1,100)       #genera un numero aleatorio entre 1 y 100, ambos incluidos
    numeros.append(aleatorio)   #añade aleatorio al array numeros

print(numeros)