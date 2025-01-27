""""
import re

#patron_fecha1 = r"(?P<diatipo1>  )"

def valida_tlf(telefono):
    patron = r"(\d{3} ){2}(\d{3})"   #expresion regular telefono
    re_tlf = re.compile(patron)
    m = re_tlf.fullmatch(telefono)

    if m:
        print("Hace match VIVA")
        return telefono
    else:
        return ""   #devolvemos cadena vacía por si queremos operar con cadenas más tarde

def valida_dni(dni):
    patron = r"(?P<numero>\d{8})(?P<letra>[A-Z])"
    re_dni = re.compile(patron)
    m = re_dni.fullmatch(dni)

    if m:
        numero_dni = m.group("numero")
        letra_dni = m.group("letra")
        valido = comprobar_dni(numero_dni, letra_dni)
        if valido:
            return dni
        else:
            print("dni no valido")
            return None
    else:
        return None

# TODO meter la funcion de validar el dni
def comprobar_dni(n,l):
    return True

def validar_fecha(fecha):
    fecha = "1254/12/12 11:47 AM"
    #TODO añadir las expresiones regulares de los 3 tipos de fecha
    patron_conjunto = f"(?P<fecha1>{patron_fecha1}) | (?P<fehca2>{patron_fecha2}) | (?P<fecha3{patron_fecha3})"
    re_fecha = re.compile(patron_conjunto)
    m = re_fecha.fullmatch(fecha)
        if m.group("fecha1"):
            #TODO
            print("Es de tipo 1")
            #dia = m.group("diatipo1")  /// seleccionar del primer tipo de fecha el dia
            #mes =
            #anno =
            #minutos =
            #valida = comprobar_fecha_tipo1(dia, mesm annom hora, minutos) /// para validar la fecha despues de extraerla
        elif m.group("fecha2"):
            print("Es de tipo 2")
            # dia = m.group("diatipo2")
            # mes =
            # anno =
            # minutos =
            # valida = comprobar_fecha_tipo2 (dia, mesm annom hora, minutos)
            # if valida:
                #return transformar_fecha_tipo2
            # LAS FECHAS DE TIPO 1 SE RETURNEAN TAL CUAL.
            # LAS DE TIPO 2 Y 3 HAY QUE PASARLAS AL FORMATO 1
        elif m.group("fecha3"):
            print("Es de tipo 3")


if __name__ == "__main__":
    cadena = "904 432 234"
    print(valida_tlf(cadena))

    dni = "12345678P"
    print(valida_dni(dni))
"""

#cuerpo practica

cadena1 = '666 777 999 ; 12345678Z ; 2000-02-09 22:30 ; 30.0, -40.5 ; iMac ; 2300€'
cadena2 = '566 677 899 ; 87654321X ; May 20, 2000 10:30 pm ; 30° 0‘ 0.0000" N, 40° 30‘ 0.0000" W ; Ipad ; 600€'
cadena3 = '673 723 229 ; 12345678Z; 22:30:00 05/03/2002 ; 0300000.0000N0403000.0000W ; Iphone ; 399.99€'


def validar_linea(linea) :
    return true


def normalizar(linea):
    
    valida = validar_linea(linea)
    if valida:
        valida_fecha(fecha)
    pass

if __name__ == '__main__':
    print('Pycharm')


