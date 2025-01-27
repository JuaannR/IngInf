def movimientos_alfil(r1, c1, r2, c2):
    # Si las posiciones ya son iguales, no se necesita ningún movimiento
    if r1 == r2 and c1 == c2:
        return 0
    # Si la suma de (fila + columna) es diferente en origen y destino, el movimiento no es posible
    elif (r1 + c1) % 2 != (r2 + c2) % 2:
        return "no move"
    # Si están en la misma diagonal, un movimiento es suficiente
    elif abs(r1 - r2) == abs(c1 - c2):
        return 1
    else:
        # En otros casos, puede llegar en exactamente dos movimientos
        return 2


# Lectura del número de casos de prueba
C = int(input())
input()  # Leer la línea en blanco después del número de casos

# Para cada caso
for _ in range(C):
    T = int(input())  # Leer el número de pruebas
    N = int(input())  # Leer el tamaño del tablero
    for _ in range(T):
        r1, c1, r2, c2 = map(int, input().split())  # Leer posiciones
        print(movimientos_alfil(r1, c1, r2, c2))

    input()  # Leer la línea en blanco entre casos
