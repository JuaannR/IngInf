def FechaCorrecta(anyo,mes,dia):
    # mes de 31 dias
    if mes in [1, 3, 5, 7, 8, 10, 12]:
        if dia>0 and dia<32:
            return True
        else:
            return False
    # mes de 30 dias
    elif mes in [4, 6, 9, 11]:
        if dia>0 and dia<31:
            return True
        else:
            return False
    # febrero
    elif mes == 2:
        # año bisiesto
        if anyo%4 == 0 and (anyo% 100 != 0 or anyo%400 == 0):
            if dia > 0 and dia < 30:
                return True
            else:
                return False
        # año no bisiesto
        else:
            if dia>0 and dia<29:
                return True
            else:
                return False
    else:
        return False


a = int(input('Introduce un año: '))
m = int(input('Introduce un mes: '))
d = int(input('Introduce un dia: '))
FechaCorrecta(a,m,d)