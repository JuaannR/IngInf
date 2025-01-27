import random
from datetime import datetime, timedelta

def generarNIF():
    letras = 'TRWAGMYFPDXBNJZSQVHLCKE'
    numeros_dni = random.randint(0, 99999999)
    letra = letras[numeros_dni % 23]
    nif = str(numeros_dni) + letra
    return nif

def generar_fecha_aleatoria():
    #Genera año entre incio-fin
    año_inicio = 2000
    año_fin = 2024
    año = random.randint(año_inicio, año_fin)

    # Genera mes entre 1 y 12
    mes = random.randint(1, 12)

    # Genera dia considerando el mes
    if mes == 2:
        #febrero, considerando años bisiestos
        if (año % 4 == 0 and año % 100 != 0) or (año % 400 == 0):
            día = random.randint(1, 29)  # Año bisiesto
        else:
            día = random.randint(1, 28)  # Año no bisiesto
    elif mes in [4, 6, 9, 11]:
        día = random.randint(1, 30)  # Meses con 30 días
    else:
        día = random.randint(1, 31)  # Meses con 31 días

   #Genera hora y minuto
    hora = random.randint(0, 23)
    minuto = random.randint(0, 59)

    # Crear la fecha y hora
    fecha = datetime(año, mes, día, hora, minuto)

    return fecha

def generar_coordenadas_aleatorias():
    latitud = random.uniform(-90,90)
    longitud = random.uniform(-180,180)

    return latitud, longitud

#DNI
nif = generarNIF()
print(f'El DNI es: {nif}')

#telefono
telefono = random.randint(00000000, 99999999)
print(f'Telefono: +34 6{telefono}')

#fecha
fecha = generar_fecha_aleatoria()
print("La fecha es: ", fecha.strftime('%Y-%m-%d %H:%M'))

#coordenadas
lat, lon = generar_coordenadas_aleatorias()
print("Latitud:",round(lat,6), "Longitud:", round(lon,6))

#lista de productos y seleccion aleatoira
productos = ["iMac", "iPhone", "Portátil", "Teclado Gamer", "Ratón", "Ipad", "PC", "Nada"]
product = random.choice(productos)
print("El producto es:",product)

#precio
precio = random.randint(500,3000)
print("El precio es:",precio,"€")