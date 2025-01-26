import regex as re
import sys
import os

#expresiones regulares
patron_fecha_1 = r'(?P<anyo>\d{1,4})\-(?P<mes>1[012]|0[1-9])\-(?P<dia>3[01]|[12][0-9]|0[1-9]) +(?P<hora>2[0-3]|[01][0-9]):(?P<min>[0-5][0-9])'
patron_fecha_2 = r'(?P<mes>[A-Za-z]+) +(?P<dia>3[01]|[12][0-9]|[1-9]), +(?P<anyo>\d{1,4}) +(?P<hora>1[0-2]|[1-9]):(?P<min>[0-5][0-9]) +(?P<ampm>(?i)am|pm|AM|PM)'
patron_fecha_3 = r'(?P<hora>2[0-3]|[01][0-9]):(?P<min>[0-5][0-9]):(?P<seg>[0-5][0-9]) +(?P<dia>3[01]|[12][0-9]|0[1-9])\/(?P<mes>1[012]|0[1-9])\/(?P<anyo>\d{1,4})'

def obtener_fecha(fecha):
    #autómata que valida el patrón 
    re_1 = re.compile(patron_fecha_1)
    re_2 = re.compile(patron_fecha_2)
    re_3 = re.compile(patron_fecha_3)
    fecha_dic = dict()  #diccionario

    if m := re_1.fullmatch(fecha):
        fecha_dic['anyo'] = m.group("anyo")
        fecha_dic['mes'] = m.group("mes")
        fecha_dic['dia'] = m.group("dia")
        fecha_dic['hora'] = m.group("hora")
        fecha_dic['min'] = m.group("min")
        fecha_dic['seg'] = '00'

    elif m := re_2.fullmatch(fecha):
        meses = {'january': '01', 'february': '02', 'march': '03', 'april': '04', 'may': '05', 'june': '06',
        'july': '07', 'august': '08', 'september': '09', 'october': '10', 'november': '11', 'december': '12'}
        fecha_dic['anyo'] = m.group("anyo")
        fecha_dic['mes'] = meses.get(m.group("mes").lower())
        fecha_dic['dia'] = m.group("dia")
        if m.group('ampm') == 'pm' or m.group('ampm') == 'PM': 
            hora = int(m.group("hora")) + 12
            if hora == 24:
                hora = '00' 
            
            fecha_dic['hora'] = str(hora)
        else: 
            fecha_dic['hora'] = m.group("hora")
        fecha_dic['min'] = m.group("min")
        fecha_dic['seg'] = '00'


    elif m:= re_3.fullmatch(fecha):
        fecha_dic['anyo'] = m.group("anyo")
        fecha_dic['mes'] = m.group("mes")
        fecha_dic['dia'] = m.group("dia")
        fecha_dic['hora'] = m.group("hora")
        fecha_dic['min'] = m.group("min")
        fecha_dic['seg'] = m.group("seg")

    if not fecha_dic:  # Si no se ha extraído ninguna fecha
        print(f"Error: Formato de fecha no válido para: {fecha}")
    return fecha_dic



#valida si la fecha dada es correcta o no
def validar_fecha(fecha):
    try:
        if not fecha.get('mes') or not fecha.get('dia') or not fecha.get('anyo'):
            return False  # Si falta algún campo, retorna False
        # mes de 31 dias
        if int(fecha['mes']) in [1, 3, 5, 7, 8, 10, 12]:
            if int(fecha['dia'])>0 and int(fecha['dia'])<32:
                return True
            else:
                return False
            
        # mes de 30 dias
        elif int(fecha['mes']) in [4, 6, 9, 11]:
            if int(fecha['dia'])>0 and int(fecha['dia'])<31:
                return True
            else:
                return False
            
        # february
        elif int(fecha['mes']) == 2:
            # año bisiesto
            if int(fecha['anyo'])%4 == 0 and (int(fecha['anyo'])% 100 != 0 or int(fecha['anyo'])%400 == 0):
                if int(fecha['dia']) > 0 and int(fecha['dia']) < 30:
                    return True
                else:
                    return False
                
            # año no bisiesto
            else:
                if int(fecha['dia'])>0 and int(fecha['dia'])<29:
                    return True
                else:
                    return False
        else:
            return False
    except (ValueError, TypeError):
        return False  # En caso de error con tipos de datos (por ejemplo, valores no numéricos)
    
def normalizar_fecha(fecha) -> str:
    fecha = obtener_fecha(fecha)
    fecha_correcta = validar_fecha(fecha)
    if(not fecha_correcta):
        return f"Fecha Incorrecta"
    
    return f"{fecha['anyo']}-{fecha['mes']}-{fecha['dia']} {fecha['hora']}:{fecha['min']}"

def comparar_fechas (fecha_desde, fecha_hasta, fecha_linea) -> bool:
    if comparar_fecha(fecha_desde, fecha_linea) != 1 and comparar_fecha(fecha_linea, fecha_hasta) != 1:
        return True
    else: 
        return False
    

def comparar_fecha(fecha_1, fecha_2): 
    if int(fecha_1.get('anyo')) < int(fecha_2.get('anyo')):
        return -1 
    elif int(fecha_1.get('anyo')) > int(fecha_2.get('anyo')):
        return 1
    else: 
        if int(fecha_1.get('mes')) < int(fecha_2.get('mes')):
            return -1 
        elif int(fecha_1.get('mes')) > int(fecha_2.get('mes')):
            return 1
        else: 
            if int(fecha_1.get('dia')) < int(fecha_2.get('dia')):
                return -1 
            elif int(fecha_1.get('dia')) > int(fecha_2.get('dia')):
                return 1
            else: 
                if int(fecha_1.get('hora')) < int(fecha_2.get('hora')):
                    return -1 
                elif int(fecha_1.get('hora')) > int(fecha_2.get('hora')):
                    return 1
                else: 
                    if int(fecha_1.get('min')) < int(fecha_2.get('min')):
                        return -1 
                    elif int(fecha_1.get('min')) > int(fecha_2.get('min')):
                        return 1
                    else: 
                        if int(fecha_1.get('seg')) <int( fecha_2.get('seg')):
                            return -1 
                        elif int(fecha_1.get('seg')) > int(fecha_2.get('seg')):
                            return 1
                        else: 
                            return 0