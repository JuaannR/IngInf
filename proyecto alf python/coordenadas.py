import regex as re
import math


#expresiones regulares
patron_coordenada_1 = r'(?P<latitud>[-+]?(90\.0|[1-8]?\d\.\d+)),\s*(?P<longitud>[-+]?(180\.0|1[0-7]\d\.\d+|[1-9]?\d\.\d+))'
patron_coordenada_2 = r'(?P<grados1>(90|[1-8]?\d))°\s*(?P<min1>([0-5]?\d))‘\s*(?P<seg1>([0-5]?\d(\.\d+)?))"\s*(?P<NoS>(N|S))\s*,\s*(?P<grados2>(180|1[0-7][0-9]|[1-9][0-9]|[0-9]))°\s*(?P<min2>([0-5]?\d))‘\s*(?P<seg2>([0-5]?\d(\.\d+)?))"\s*(?P<WoE>(W|E))'
patron_coordenada_3 = r'(?P<grados1>090|0[0-8]\d)(?P<min1>[0-5][0-9])(?P<seg1>[0-5][0-9]\.\d{4})(?P<NoS>N|S)(?P<grados2>(180|1[0-7]\d)|0\d{2})(?P<min2>[0-5][0-9])(?P<seg2>[0-5][0-9]\.\d{4})(?P<WoE>W|E)'

def cambiar_a_sexagesimal(latitud, longitud):
    grados1signo = int(latitud)
    grados1 = abs(grados1signo)
    min1decimal = (abs(latitud) - grados1)*60
    min1 = int(min1decimal)
    seg1decimal = (min1decimal - min1)*60
    seg1 = f"{seg1decimal:.4f}"
    if (latitud >= 0):
        NoS = 'N'
    else:
        NoS = 'S'
        # :.4f fuerza a que se escriban 4 decimales

    grados2signo = int(longitud)
    grados2 = abs(grados2signo)
    min2decimal = (abs(longitud) - grados2)*60
    min2 = int(min2decimal)
    seg2decimal = (min2decimal - min2)*60
    seg2 = f"{seg2decimal:.4f}"

    if (longitud >= 0):
        WoE = 'E'
    else:
        WoE = 'W'

    coordenadas_dic = {
        'grados1': grados1,
        'min1': min1,
        'seg1': seg1,
        'NoS': NoS,
        'grados2': grados2,
        'min2': min2,
        'seg2': seg2,
        'WoE': WoE
    }
    return coordenadas_dic

def obtener_coordenada(coordenada):
    re_1 = re.compile(patron_coordenada_1)
    re_2 = re.compile(patron_coordenada_2)
    re_3 = re.compile(patron_coordenada_3)
    coordenadas_dic = dict()
    if m := re_1.fullmatch(coordenada):
        latitud = float(m.group("latitud"))
        longitud = float(m.group("longitud"))

        coordenadas = cambiar_a_sexagesimal(latitud, longitud)
        coordenadas_dic.update(coordenadas)

    if m := re_2.fullmatch(coordenada):
        coordenadas_dic['grados1'] = m.group("grados1")
        coordenadas_dic['min1'] = m.group("min1")
        coordenadas_dic['seg1'] = m.group("seg1")
        coordenadas_dic['NoS'] = m.group("NoS")
        coordenadas_dic['grados2'] = m.group("grados2")
        coordenadas_dic['min2'] = m.group("min2")
        coordenadas_dic['seg2'] = m.group("seg2")
        coordenadas_dic['WoE'] = m.group("WoE")
    if m := re_3.fullmatch(coordenada):
        coordenadas_dic['grados1'] = m.group("grados1")
        coordenadas_dic['min1'] = m.group("min1")
        coordenadas_dic['seg1'] = m.group("seg1")
        coordenadas_dic['NoS'] = m.group("NoS")
        coordenadas_dic['grados2'] = m.group("grados2")
        coordenadas_dic['min2'] = m.group("min2")
        coordenadas_dic['seg2'] = m.group("seg2")
        coordenadas_dic['WoE'] = m.group("WoE")
    return coordenadas_dic

def normalizar_coordenada(coordenada) -> str:
    coordenada_dic = obtener_coordenada(coordenada)
    if not coordenada_dic:  
        return None
    
    return f"{int(coordenada_dic['grados1']):03}{int(coordenada_dic['min1']):02}{float(coordenada_dic['seg1']):07.4f}{coordenada_dic['NoS']}{int(coordenada_dic['grados2']):03}{int(coordenada_dic['min2']):02}{float(coordenada_dic['seg2']):07.4f}{coordenada_dic['WoE']}"


def convertir_decimal(coordenada):
    grados_lat = coordenada.get('grados1')
    minutos_lat = coordenada.get('min1')
    segundos_lat = coordenada.get('seg1')
    simbolo_lat = coordenada.get('NoS')

    grados_lon = coordenada.get('grados2')
    minutos_lon = coordenada.get('min2')
    segundos_lon = coordenada.get('seg2')
    simbolo_lon = coordenada.get('WoE')

    if simbolo_lat == 'S':
        simbolo_lat = '-'
    else: 
        simbolo_lat = '+'

    if simbolo_lon == 'W':
        simbolo_lon = '-'
    else:
        simbolo_lon = '+'

    latitud = float(grados_lat) + (float(minutos_lat)/60) + (float(segundos_lat)/3600)
    longitud = float(grados_lon) + (float(minutos_lon)/60) + (float(segundos_lon)/3600)

    latitud_cs = f'{simbolo_lat}{latitud}'
    longitud_cs = f'{simbolo_lon}{longitud}'

    return {'latitud': float(latitud_cs),'longitud': float(longitud_cs)}


def calcular_distancias(coordenada_desde, coordenada_fichero):

    lat1 = coordenada_desde.get('latitud')
    lon1 = coordenada_desde.get('longitud')
    lat2 = coordenada_fichero.get('latitud')
    lon2 = coordenada_fichero.get('longitud')
    # Radio de la Tierra en km
    R = 6371.0

    lat1_rad = math.radians(lat1)
    lon1_rad = math.radians(lon1)
    lat2_rad = math.radians(lat2)
    lon2_rad = math.radians(lon2)

    delta_lat = lat2_rad - lat1_rad
    delta_lon = lon2_rad - lon1_rad
    
    a = math.sin(delta_lat / 2)**2 + math.cos(lat1_rad) * math.cos(lat2_rad) * math.sin(delta_lon / 2)**2
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))

    distancia = R * c

    return distancia

