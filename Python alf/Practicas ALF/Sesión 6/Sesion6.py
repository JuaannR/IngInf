import re
#import regex as re
"""
if __name__ == "__main__":
    patron = r"\d{8}[A-Z]"
    er_dni = re.compile(patron)
    cadena = "48854653P"
    m = er_dni.fullmatch(cadena)  # usamos fullmatch en vez de match para validar la cadena entera
    if m:
        print("Hay match")
        print(f"Inicio: {m.start()} Final: {m.end()}")
        try:
            print(cadena[m.end()])
        except:
            print(cadena[m.end()-1])
    else:
        print("Error, no hay match")



if __name__ == "__main__":
    patron2 = r"\d+"
    er_digitos2 = re.compile(patron2)
    cadena2 = "AB 12 DE 34"
    nueva = er_digitos2.sub("-",cadena2)
    print(nueva)



def sust(m):
    suma=0
    for i in m.group(0):
        suma += int(i)
    return str(suma)

if __name__ == "__main__":
    patron = r"(?P<numero>\d{8})(?P<letra>[A-Z])"
    er_dni = re.compile(patron)
    cadena = "12345678A"
    m = er_dni.match(cadena)
    print(m.group("letra") + m.group("numero"))
"""