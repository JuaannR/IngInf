import random
import string

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


numero = random.randint(10000000, 99999999 )
numero = str(numero)

print(f'El numero del DNI es: {numero}')

letra = letraDNI(numero)
print(f'La letra es: {letra}')

DNI_completo  = str(numero) + str(letra)
print(f'El DNI completo es: {DNI_completo}')


#letra aleatoria
#letra = random.choice(string.ascii_uppercase)
#print(f'La letra del DNI es: {letra}')