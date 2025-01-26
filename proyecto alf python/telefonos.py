import re
import sys
import os 

#ER general 
patron_general = r'(?P<general>\d{3} \d{3} \d{3})'
#Opcional 
patron_espn = r'(?P<simbolo>[+])(?P<prefijo_esp>34)[ ](?P<num_esp>\d{3} \d{3} \d{3})'
patron_uk = r'(?P<simbolo>[+])(?P<prefijo>44)[ ](?P<num_uk>\d{3} \d{3} \d{4})'
patron_usa = r'(?P<simbolo>[+])(?P<prefijo_usa>1)[ ](?P<num_usa>\d{3} \d{3} \d{4})'
patron_india = r'(?P<simbolo>[+])(?P<prefijo_india>91)[ ](?P<num_india>\d{3} \d{3} \d{4})'
patron_australia = r'(?P<simbolo>[+])(?P<prefijo_aus>61)[ ](?P<num_aus>\d{3} \d{3} \d{3})'

def validar_telefono(telefono):
    re_gen = re.compile(patron_general)
    m = re_gen.match(telefono) 
    if m: return True
    
    re_gen = re.compile(patron_espn)
    m = re_gen.match(telefono) 
    if m: return True

    re_gen = re.compile(patron_uk)
    m = re_gen.match(telefono) 
    if m: return True

    re_gen = re.compile(patron_usa)
    m = re_gen.match(telefono) 
    if m: return True

    re_gen = re.compile(patron_india)
    m = re_gen.match(telefono) 
    if m: return True

    re_gen = re.compile(patron_australia)
    m = re_gen.match(telefono) 
    if m: return True
    return False

