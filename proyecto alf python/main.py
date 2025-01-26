from fechas import obtener_fecha, validar_fecha, normalizar_fecha, comparar_fechas
from coordenadas import obtener_coordenada, normalizar_coordenada, calcular_distancias, convertir_decimal
from nif import obtener_nif, validar_nif
from telefonos import validar_telefono

import regex as re
import sys
import os
import math

# ER
pattern_linea = r'(?P<telefono>[^;]+[^ ])[ ]?;[ ]?(?P<nif>[^;]+[^ ])[ ]?;[ ]?(?P<fecha>[^;]+[^ ])[ ]?;[ ]?(?P<coordenadas>[^;]+[^ ])[ ]?;[ ]?(?P<producto>[^;]+[^ ])[ ]?;[ ]?(?P<precio>[^;]+[^\n])'

def validar_linea(linea):
    if m:=re.match(pattern_linea, linea):
        if validar_telefono(m.group('telefono')) and obtener_nif(m.group('nif')) and obtener_fecha(m.group('fecha')) and obtener_coordenada(m.group('coordenadas')): 
            return m 
    return None 

def normalizar(linea):
    es_linea_valida = validar_linea(linea)
    if es_linea_valida != None:
        datos = es_linea_valida.groupdict()

        fecha_normalizada = normalizar_fecha(datos['fecha'])
        if fecha_normalizada == "Fecha Incorrecta":
            return None
        datos['fecha'] = fecha_normalizada

        coordenada_normalizada = normalizar_coordenada(datos['coordenadas'])
        if coordenada_normalizada == None:
            return None
        datos['coordenadas'] = coordenada_normalizada

        nif_valido = validar_nif(datos['nif'])
        if not nif_valido:
            return None
            
        # Devolvemos el diccionario con los datos normalizados
        return datos
    
    else: #si linea no válida
        return None

def norm(fichero):
    if os.path.isfile(fichero):  # Verifica si el fichero existe
        with open(fichero, 'r', encoding="utf-8") as f:
            for linea in f:
                datos_normalizados = normalizar(linea)
                if datos_normalizados != None:
                    print(f"{datos_normalizados['telefono']};{datos_normalizados['nif']};{datos_normalizados['fecha']};{datos_normalizados['coordenadas']};{datos_normalizados['producto']};{datos_normalizados['precio']}")
    else:
                print(f"Error: El fichero '{fichero}' no existe.")

def buscar_fecha(fecha_desde, fecha_hasta, fichero):
    fecha_desde_dic = obtener_fecha(fecha_desde)
    fecha_hasta_dic = obtener_fecha(fecha_hasta)

    fecha_desde_valida = validar_fecha(fecha_desde_dic)
    fecha_hasta_valida = validar_fecha(fecha_hasta_dic)

    if not fecha_hasta_valida or not fecha_desde_valida: 
        return None
    
    try:
        with open(fichero, 'r', encoding='utf-8') as file:
            for linea in file:
                # Validar si la línea sigue el formato correcto
                es_valida = validar_linea(linea)
                if not es_valida:
                    continue
                datos = es_valida.groupdict()
                datos_fecha = obtener_fecha(datos['fecha'])
                if datos_fecha and validar_fecha(datos_fecha):
                    if comparar_fechas(fecha_desde_dic, fecha_hasta_dic ,datos_fecha):
                        
                        print(linea, end="")
    except FileNotFoundError:
        print(f"El fichero {fichero} no existe")
        return False

def buscar_telefono(telefono, fichero):
    try:
        with open(fichero, 'r', encoding='utf-8') as file:
            lineas = file.readlines()
            for linea in lineas: 
                es_linea_valida = validar_linea(linea) 
                if es_linea_valida: 
                    validar_telefono(telefono)
                    if telefono == es_linea_valida.group('telefono'):
                        print(linea)
                        
    except FileNotFoundError:
        print(f"Error: El fichero '{fichero}' no existe")
        return False

def buscar_nif(nif_a_buscar, fichero):
    try:
        with open(fichero, 'r', encoding='utf-8') as file:
            lineas = file.readlines()
            
            for linea in lineas:
                match = validar_linea(linea)
                if match and match.group('nif') == nif_a_buscar:
                    print(linea)
    except FileNotFoundError:
        print(f"Error: el fichero {fichero} no existe")
                
def buscar_localizacion(coordenada_1, hasta, fichero):
    decimal_coordenada_1 = convertir_decimal(obtener_coordenada(coordenada_1))

    try: 
        with open(fichero, 'r', encoding='utf-8') as file:
            lineas = file.readlines()

            for linea in lineas: 
                linea_valida = validar_linea(linea)
                if linea_valida: 
                    coordenada_fichero = linea_valida.group('coordenadas')
                    coordenada_decimal_fichero = convertir_decimal(obtener_coordenada(coordenada_fichero))

                    distancia = calcular_distancias(decimal_coordenada_1, coordenada_decimal_fichero)
                    if distancia < float(hasta):
                        print(linea)
    except FileNotFoundError:
        print(f"Error: el fichero {fichero} no existe")
        return False



def programa():
    if len(sys.argv) == 3 and sys.argv[1] == '-n':
            fichero = sys.argv[2]
            norm(sys.argv[2])
    elif len(sys.argv) == 4:
        if sys.argv[1] == '-sphone':
            encontrado = buscar_telefono(sys.argv[2], sys.argv[3])
        elif sys.argv[1] == '-snif':
            encontrado = buscar_nif(sys.argv[2], sys.argv[3])
    elif len(sys.argv) == 5: 
        if sys.argv[1] == '-stime':
            buscar_fecha(sys.argv[2], sys.argv[3], sys.argv[4])
        if sys.argv[1] == '-slocation':
            buscar_localizacion(sys.argv[2], sys.argv[3], sys.argv[4])
        
# Prueba
if __name__ == '__main__':  

    programa()
    