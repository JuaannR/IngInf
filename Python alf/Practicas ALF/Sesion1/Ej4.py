def compara_fecha (dia1,mes1,anyo1,hora1,min1,seg1,dia2,mes2,anyo2,hora2,min2,seg2):
    if anyo1 < anyo2:
        print('La primera fecha es mas antigua')
    elif anyo1 > anyo2:
        print('La segunda fecha es mas antigua')
    #mismo año, comparamos meses
    else:
        if mes1 < mes2:
            print('La primera fecha es mas antigua')
        elif mes1 > mes2:
            print('La segunda fecha es mas antigua')
        #mismo año y mes, comparamos dia
        else:
            if dia1 < dia2:
                print('La primera fecha es mas antigua')
            elif dia1 > dia2:
                print('La segunda fecha es mas antigua')
            #mismo año, mes y dia. Comparamos hora
            else:
                if hora1 < hora2:
                    print('La primera fecha es mas antigua')
                elif hora1 > hora2:
                    print('La segunda fecha es mas antigua')
                #mismo año, mes, dia y hora
                else:
                    if min1 < min2:
                        print('La primera fecha es mas antigua')
                    elif min1 > min2:
                        print('La segunda fecha es mas antigua')
                    #mismo año, mes, dia, hora y minuto
                    else:
                        if seg1 < seg2:
                            print('La primera fecha es mas antigua')
                        elif seg1 > seg2:
                            print('La segunda fecha es mas antigua')
                        #todo igual
                        else:
                            print('Las dos fechas son iguales')

a1 = int(input('Introduce el año de la primera fecha: '))
me1 = int(input('Introduce el mes de la primera fecha: '))
d1 = int(input('Introduce el dia de la primera fecha: '))
h1 = int(input('Introduce la hora de la primera fecha: '))
mi1 = int(input('Introduce el minuto de la primera fecha: '))
s1 = int(input('Introduce el segundo de la primera fecha: '))
a2 = int(input('Introduce el año de la segunda fecha: '))
me2 = int(input('Introduce el mes de la segunda fecha: '))
d2 = int(input('Introduce el dia de la segunda fecha: '))
h2 = int(input('Introduce la hora de la segunda fecha: '))
mi2 = int(input('Introduce el minuto de la segunda fecha: '))
s2 = int(input('Introduce el segundo de la segunda fecha: '))

compara_fecha(d1,me1,a1,h1,mi1,s1,d2,me2,a2,h2,mi2,s2)

# tuplas, forma de resumir las fechas y ahorrarse 200 comparaciones...
#
#     fecha1 = (anyo1, mes1, dia1, hora1, min1, seg1)
#     fecha2 = (anyo2, mes2, dia2, hora2, min2, seg2)
#
#     if fecha1 < fecha2:
#         print('La primera fecha es más antigua')
#     elif fecha1 > fecha2:
#         print('La segunda fecha es más antigua')
#     else:
#         print('Las dos fechas son iguales')
#
# todos los input para pedir datos al usuario
