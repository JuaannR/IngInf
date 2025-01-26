import regex as re 
import sys
import os 

#Expresiones Regulares
patron_DNI = r'(?P<numerosDNI>\d{8})(?P<letraDNI>[TRWAGMYFPDXBNJZSQVHLCKE])'
patron_NIE = r'(?P<primeraLetraNIE>[XYZ])(?P<numerosNIE>\d{7})(?P<segundaLetraNIE>[TRWAGMYFPDXBNJZSQVHLCKE])'
patron_NIF = re.compile(r'(?P<pat_nif>\d{8}[TRWAGMYFPDXBNJZSQVHLCKE]|[XYZ]\d{7}[TRWAGMYFPDXBNJZSQVHLCKE])')

def obtener_nif(nif):
    #Cambiar toda la entrada a mayúscula
    nif = nif.upper()

    re_1 = re.compile(patron_DNI)
    re_2 = re.compile(patron_NIE)
    nif_dic = dict()
    if m := re_1.fullmatch(nif):
        nif_dic['numerosDNI'] = m.group("numerosDNI")
        nif_dic['letraDNI'] = m.group("letraDNI")
    if m := re_2.fullmatch(nif):
        nif_dic['primeraLetraNIE'] = m.group("primeraLetraNIE")
        nif_dic['numerosNIE'] = m.group("numerosNIE")
        nif_dic['segundaLetraNIE'] = m.group("segundaLetraNIE")
    return nif_dic

def calcular_letra_DNI(numeros_dni):
    letras =  'TRWAGMYFPDXBNJZSQVHLCKE'
    resto = numeros_dni % 23
    return letras[resto]

def validar_dni(nif):
    datos = obtener_nif(nif)
    if 'numerosDNI' in datos and 'letraDNI' in datos:
        numeros_dni = int(datos['numerosDNI'])
        letra_dni = datos['letraDNI']
        letra_calculada = calcular_letra_DNI(numeros_dni)
        return letra_dni == letra_calculada  
    return False

def validar_nie(nif):
    datos = obtener_nif(nif)
    if 'primeraLetraNIE' in datos and 'numerosNIE' in datos and 'segundaLetraNIE' in datos: 
        primera_letra = datos['primeraLetraNIE']
        numeros_nie = datos['numerosNIE']
        segunda_letra = datos['segundaLetraNIE']

        if primera_letra == 'X':
            convertido = '0'
        elif primera_letra == 'Y':
            convertido = '1'
        elif primera_letra == 'Z':
            convertido = '2'
        else:
            return False    #Si la letra inicial no es válida
        
        numero_completo_NIE = int(convertido + numeros_nie)
        letra_calculada = calcular_letra_DNI(numero_completo_NIE)
        return segunda_letra == letra_calculada
    
    return False

def validar_nif(nif):
    nif = nif.upper()
    re_dni = re.compile(patron_DNI)
    re_nie = re.compile(patron_NIE)
    
    if re_dni.fullmatch(nif):
        return validar_dni(nif)
    if re_nie.fullmatch(nif):
        return validar_nie(nif)
    
    return False

