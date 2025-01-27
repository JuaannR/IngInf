def letraDNI (x):
   resto = int(x)%23
   letra = None
   if resto == 0:
        letra = 'T'
   elif resto == 1:
        letra = 'R'
   elif resto == 2:
        letra = 'W'
   elif resto == 3:
       letra = 'A'
   elif resto == 4:
       letra = 'G'
   elif resto == 5:
       letra = 'M'
   elif resto == 6:
       letra = 'Y'
   elif resto == 7:
       letra = 'F'
   elif resto == 8:
       letra = 'P'
   elif resto == 9:
       letra = 'D'
   elif resto == 10:
       letra = 'X'
   elif resto == 11:
       letra = 'B'
   elif resto == 12:
       letra = 'N'
   elif resto == 13:
       letra = 'J'
   elif resto == 14:
       letra = 'Z'
   elif resto == 15:
       letra = 'S'
   elif resto == 16:
       letra = 'Q'
   elif resto == 17:
       letra = 'V'
   elif resto == 18:
       letra = 'H'
   elif resto == 19:
       letra = 'L'
   elif resto == 20:
       letra = 'C'
   elif resto == 21:
       letra = 'K'
   elif resto ==22:
       letra = 'E'
   return letra

def dni_valido (nif):
    letra = nif[-1]
    numero = nif[0:8]

    if len(numero) == 8 and letraDNI(numero) == letra:
        print('DNI valido')
    else:
        print('DNI erroneo')
    return 0
# 1º funcion

a = int(input('Introduce los digitos de tu DNI: '))
l = letraDNI(a)
print('La letra de tu DNI es: ' +l)

# 2º funcion
nif = input('Introduce un DNI: ')
dni_valido(nif)









