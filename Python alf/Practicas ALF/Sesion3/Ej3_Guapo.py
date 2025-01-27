import random
from datetime import datetime, timedelta

# funcion para generar un telefono aleatorio
# recalcar que tiene un número menos(8), ya que cuando se imprima en pantalla
# tendrá por defecto un 6 como primer digito para que parezca español jeje

def generar_telefono_aleatorio():
    telefono = random.randint(00000000, 99999999)
    return telefono

#funcion para generar un DNI aleatorio
def generar_DNI_aleatorio():
    conjunto = 'TRWAGMYFPDXBNJZSQVHLCKE'
    numeros_dni = random.randint(0, 99999999)
    letra = conjunto[numeros_dni % 23]
    nif = str(numeros_dni) + letra
    return nif

#funcion para generar un instante de tiempo aleatorio
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

#fucion para generar unas coordenadas aleatorias
def generar_coordenadas_aleatorias():
    latitud = random.uniform(-90,90)
    longitud = random.uniform(-180,180)
    lat = round(latitud, 7)
    lon = round(longitud,7)
    return lat, lon

#funcion para generar un articulo aleatorio de la lista
def generar_articulo_aleatorio():
    productos = ["iMac", "iPhone", "Portátil", "Teclado Gamer", "Ratón", "Ipad", "PC", "Nada"]
    return random.choice(productos)

def generar_precio_aleatorio():
    precio = random.randint(700,3000)
    return precio

n = int(input("Introduce el número de lineas a generar: "))


for i in range(n):
    telefono = generar_telefono_aleatorio()
    DNI = generar_DNI_aleatorio()
    fecha = generar_fecha_aleatoria()
    coordenadas = generar_coordenadas_aleatorias()
    producto = generar_articulo_aleatorio()
    precio = generar_precio_aleatorio()
    print(f"+34 6{telefono}; {DNI}; {fecha}; {coordenadas}; {producto}; {precio}€ ")