def hora_correcta (hora,minuto,segundo):
    #if hora>=0 and hora<=23 and minuto>=0 and minuto<=59 and segundo>=0 and segundo<=59:
    if all(0 <= x <= 59 for x in [segundo, minuto]) and 0 <= hora <= 23:    #forma simplificada de escribir lo de arriba
        print(f'La hora {hora}:{minuto}:{segundo} es correcta')
    else:
        print('La hora no es correcta')
h = int(input('Introduce la hora: '))
m = int(input('Introduce los minutos: '))
s = int(input('Introduce los segundos: '))

hora_correcta(h,m,s)


