
	.data	
	.align	2
jump_table000:
	.word	B14_4
	.word	B14_5
	.word	B14_9
	.word	B14_15
	.word	B14_22
	.word	B14_25
	.align	2
pieza1:
	.word	3
	.word	3
	.asciiz		" *   ****"
	.space	1014
item_auxiliar:
	.align	2
	.space	108
	.align	2
main.t1:
	.word	5
	.word	4
	.asciiz		"11112222333344445555"
	.space	1003
	.align	2
main.t2:
	.word	5
	.word	4
	.asciiz		"101312a2933a33442456"
	.space	1003
	.align	2
main.t3:
	.word	5
	.word	10
	.asciiz		"aaaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeee"
	.space	973
	.align	2
main.t4:
	.word	5
	.word	10
	.asciiz		"aaazzzazaabbbbb33bxbcccxc55cccddddddzz22222zeeeeee"
	.space	973
	.align	2
main.test:
	.word	2369
	.word	2021
	.word	8712
	.word	8510
	.word	1060
	.word	7543
	.word	8849
	.word	1504
	.word	2533
	.word	3045
	.word	7228
	.word	8911
	.word	6856
	.word	2825
	.word	9510
	.word	4352
	.word	8870
	.word	6191
	.word	2500
	.word	2856
	.align	2
main.t118:
	.word	5
	.word	9
	.asciiz		"aaaaaaaaabbbbbbbbbcccccccccdddddddddeeeeeeeee"
	.space	978
	.align	2
main.t219:
	.word	7
	.word	8
	.asciiz		"jfsvnrpotigdsfbkndsvfelkrgoirgfgijdsfgkndffkgjh123456789"
	.space	967
	.align	2
main.test24:
	.asciiz		"abc"
	.space	96
	.word	3
	.word	5
	.asciiz		"def"
	.space	96
	.word	8
	.word	2
	.asciiz		"ghi"
	.space	96
	.word	3
	.word	1
	.asciiz		"jkl"
	.space	96
	.word	0
	.word	3
	.asciiz		"mnñ"
	.space	95
	.word	0
	.word	2
str000:
	.asciiz		"+"
str001:
	.asciiz		"-"
str002:
	.asciiz		"+\n"
str003:
	.asciiz		"|"
str004:
	.asciiz		"|\n"
str005:
	.asciiz		"\n\nExamen de ETC de ensamblador\n\n 1. Simular juego de la vida (prueba contar_vecinos)\n 2. Comparar tableros\n 3. Clasificar números\n 4. Eliminar caracteres de tableros\n 5. Ordenar\n 0. Salir\n\nElige una opción: "
str006:
	.asciiz		"\n\n"
str007:
	.asciiz		"Iteración "
str008:
	.asciiz		":\n"
str009:
	.asciiz		"\n Pulsa «X» para salir, o cualquier otra para pasar a la siguiente iteración. "
str010:
	.asciiz		"Comparando:\n"
str011:
	.asciiz		"y:\n"
str012:
	.asciiz		"Resultado:\n"
str013:
	.asciiz		"Los tableros no son del mismo tamaño, por lo que no se pueden comparar celda a celda.\n"
str014:
	.asciiz		"\nPulse una tecla para otra prueba.\n"
str015:
	.asciiz		"Clasificando: "
str016:
	.asciiz		"\nPares: "
str017:
	.asciiz		"\nImpares: "
str018:
	.asciiz		"abde"
str019:
	.asciiz		"jgf"
str020:
	.asciiz		"Eliminado «"
str021:
	.asciiz		"» de:\n"
str022:
	.asciiz		"Lista sin ordenar:\n"
str023:
	.asciiz		"\nLista ordenada:\n"
str024:
	.asciiz		"¡Adiós!\n"
str025:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"

	.text	

tablero_celda_addr:
	lw	$t1, 4($a0)
	mul	$t1, $t1, $a1
	addu	$t1, $t1, $a2
	addu	$t1, $a0, $t1
	addiu	$v0, $t1, 8
	jr	$ra

tablero_set_celda:
	addiu	$sp, $sp, -24
	sw	$ra, 20($sp)
	sw	$s0, 16($sp)
	move	$s0, $a3
	jal	tablero_celda_addr
	sb	$s0, 0($v0)
	lw	$s0, 16($sp)
	lw	$ra, 20($sp)
	addiu	$sp, $sp, 24
	jr	$ra

tablero_get_celda:
	addiu	$sp, $sp, -24
	sw	$ra, 20($sp)
	jal	tablero_celda_addr
	lb	$v0, 0($v0)
	lw	$ra, 20($sp)
	addiu	$sp, $sp, 24
	jr	$ra

tablero_init:
	addiu	$sp, $sp, -32
	sw	$ra, 28($sp)
	sw	$s2, 24($sp)
	sw	$s1, 20($sp)
	sw	$s0, 16($sp)
	move	$s0, $a0
	sw	$a1, 0($s0)
	sw	$a2, 4($s0)
	lw	$t1, 0($s0)
	beqz	$t1, B3_6
	li	$s1, 0
	j	B3_3
B3_2:	lw	$a2, 4($s0)
B3_3:	li	$s2, 0
	beqz	$a2, B3_5
B3_4:	move	$a0, $s0
	move	$a1, $s1
	move	$a2, $s2
	li	$a3, 32
	jal	tablero_set_celda
	addiu	$s2, $s2, 1
	lw	$t1, 4($s0)
	sltu	$t1, $s2, $t1
	bnez	$t1, B3_4
B3_5:	lw	$t1, 0($s0)
	addiu	$s1, $s1, 1
	sltu	$t1, $s1, $t1
	bnez	$t1, B3_2
B3_6:	lw	$s0, 16($sp)
	lw	$s1, 20($sp)
	lw	$s2, 24($sp)
	lw	$ra, 28($sp)
	addiu	$sp, $sp, 32
	jr	$ra

tablero_copy:
	addiu	$sp, $sp, -40
	sw	$ra, 36($sp)
	sw	$s3, 32($sp)
	sw	$s2, 28($sp)
	sw	$s1, 24($sp)
	sw	$s0, 20($sp)
	move	$s0, $a1
	move	$s1, $a0
	lw	$t1, 0($s0)
	sw	$t1, 0($s1)
	lw	$t1, 4($s0)
	sw	$t1, 4($s1)
	lw	$t1, 0($s0)
	beqz	$t1, B4_5
	li	$s2, 0
B4_2:	lw	$t1, 4($s0)
	li	$s3, 0
	beqz	$t1, B4_4
B4_3:	move	$a0, $s0
	move	$a1, $s2
	move	$a2, $s3
	jal	tablero_get_celda
	move	$a0, $s1
	move	$a1, $s2
	move	$a2, $s3
	move	$a3, $v0
	jal	tablero_set_celda
	addiu	$s3, $s3, 1
	lw	$t1, 4($s0)
	sltu	$t1, $s3, $t1
	bnez	$t1, B4_3
B4_4:	lw	$t1, 0($s0)
	addiu	$s2, $s2, 1
	sltu	$t1, $s2, $t1
	bnez	$t1, B4_2
B4_5:	lw	$s0, 20($sp)
	lw	$s1, 24($sp)
	lw	$s2, 28($sp)
	lw	$s3, 32($sp)
	lw	$ra, 36($sp)
	addiu	$sp, $sp, 40
	jr	$ra

tablero_print:
	addiu	$sp, $sp, -40
	sw	$ra, 36($sp)
	sw	$s4, 32($sp)
	sw	$s3, 28($sp)
	sw	$s2, 24($sp)
	sw	$s1, 20($sp)
	sw	$s0, 16($sp)
	move	$s0, $a0
	la	$a0, str000
	jal	print_string
	lw	$t1, 4($s0)
	beqz	$t1, B5_3
	li	$s2, 0
	la	$s1, str001
B5_2:	move	$a0, $s1
	jal	print_string
	addiu	$s2, $s2, 1
	lw	$t1, 4($s0)
	sltu	$t1, $s2, $t1
	bnez	$t1, B5_2
B5_3:	la	$a0, str002
	jal	print_string
	lw	$t1, 0($s0)
	beqz	$t1, B5_8
	li	$s1, 0
	la	$s2, str003
	la	$s3, str004
B5_5:	move	$a0, $s2
	jal	print_string
	lw	$t1, 4($s0)
	li	$s4, 0
	beqz	$t1, B5_7
B5_6:	move	$a0, $s0
	move	$a1, $s1
	move	$a2, $s4
	jal	tablero_get_celda
	sll	$t1, $v0, 24
	sra	$a0, $t1, 24
	jal	print_character
	addiu	$s4, $s4, 1
	lw	$t1, 4($s0)
	sltu	$t1, $s4, $t1
	bnez	$t1, B5_6
B5_7:	move	$a0, $s3
	jal	print_string
	addiu	$s1, $s1, 1
	lw	$t1, 0($s0)
	sltu	$t1, $s1, $t1
	bnez	$t1, B5_5
B5_8:	la	$a0, str000
	jal	print_string
	lw	$t1, 4($s0)
	beqz	$t1, B5_11
	li	$s2, 0
	la	$s1, str001
B5_10:	move	$a0, $s1
	jal	print_string
	addiu	$s2, $s2, 1
	lw	$t1, 4($s0)
	sltu	$t1, $s2, $t1
	bnez	$t1, B5_10
B5_11:	la	$a0, str002
	jal	print_string
	lw	$s0, 16($sp)
	lw	$s1, 20($sp)
	lw	$s2, 24($sp)
	lw	$s3, 28($sp)
	lw	$s4, 32($sp)
	lw	$ra, 36($sp)
	addiu	$sp, $sp, 40
	jr	$ra

tablero_colocar_pieza:
	addiu	$sp, $sp, -48
	sw	$ra, 44($sp)
	sw	$s6, 40($sp)
	sw	$s5, 36($sp)
	sw	$s4, 32($sp)
	sw	$s3, 28($sp)
	sw	$s2, 24($sp)
	sw	$s1, 20($sp)
	sw	$s0, 16($sp)
	move	$s0, $a3
	move	$s1, $a2
	move	$s2, $a1
	lw	$t1, 0($s0)
	move	$s3, $a0
	beqz	$t1, B6_6
	li	$s4, 0
B6_2:	lw	$t1, 4($s0)
	beqz	$t1, B6_5
	addu	$s5, $s4, $s2
	li	$s6, 0
B6_4:	move	$a0, $s0
	move	$a1, $s4
	move	$a2, $s6
	jal	tablero_get_celda
	addu	$a2, $s1, $s6
	move	$a0, $s3
	move	$a1, $s5
	move	$a3, $v0
	jal	tablero_set_celda
	addiu	$s6, $s6, 1
	lw	$t1, 4($s0)
	sltu	$t1, $s6, $t1
	bnez	$t1, B6_4
B6_5:	lw	$t1, 0($s0)
	addiu	$s4, $s4, 1
	sltu	$t1, $s4, $t1
	bnez	$t1, B6_2
B6_6:	lw	$s0, 16($sp)
	lw	$s1, 20($sp)
	lw	$s2, 24($sp)
	lw	$s3, 28($sp)
	lw	$s4, 32($sp)
	lw	$s5, 36($sp)
	lw	$s6, 40($sp)
	lw	$ra, 44($sp)
	addiu	$sp, $sp, 48
	jr	$ra

# Devuelve el número de celdas alrededor de la indicada cuyo
# contenido no es el carácter espacio. 
# int contar_vecinos(Tablero* tablero, int fila, int columna);
contar_vecinos:
        # POR HACER
        break

# Simula una iteración del Juego de la Vida de Conway 
simular_vida:
	addiu	$sp, $sp, -1080
	sw	$ra, 1076($sp)
	sw	$s5, 1072($sp)
	sw	$s4, 1068($sp)
	sw	$s3, 1064($sp)
	sw	$s2, 1060($sp)
	sw	$s1, 1056($sp)
	sw	$s0, 1052($sp)
	move	$s0, $a0
	addiu	$a0, $sp, 16
	move	$a1, $s0
	jal	tablero_copy
	lw	$t1, 0($s0)
	beqz	$t1, B8_10
	li	$s1, 0
	addiu	$s2, $sp, 16
	li	$s4, 2
	li	$s5, 3
B8_2:	lw	$t1, 4($s0)
	li	$s3, 0
	beqz	$t1, B8_9
B8_3:	move	$a0, $s2
	move	$a1, $s1
	move	$a2, $s3
	jal	contar_vecinos
	bne	$v0, $s4, B8_5
	move	$a0, $s2
	move	$a1, $s1
	move	$a2, $s3
	jal	tablero_get_celda
	move	$a0, $s0
	move	$a1, $s1
	move	$a2, $s3
	move	$a3, $v0
	j	B8_8
B8_5:	bne	$v0, $s5, B8_7
	move	$a0, $s0
	move	$a1, $s1
	move	$a2, $s3
	li	$a3, 42
	j	B8_8
B8_7:	move	$a0, $s0
	move	$a1, $s1
	move	$a2, $s3
	li	$a3, 32
B8_8:	jal	tablero_set_celda
	lw	$t1, 4($s0)
	addiu	$s3, $s3, 1
	sltu	$t1, $s3, $t1
	bnez	$t1, B8_3
B8_9:	lw	$t1, 0($s0)
	addiu	$s1, $s1, 1
	sltu	$t1, $s1, $t1
	bnez	$t1, B8_2
B8_10:	lw	$s0, 1052($sp)
	lw	$s1, 1056($sp)
	lw	$s2, 1060($sp)
	lw	$s3, 1064($sp)
	lw	$s4, 1068($sp)
	lw	$s5, 1072($sp)
	lw	$ra, 1076($sp)
	addiu	$sp, $sp, 1080
	jr	$ra

# Comprueba si los tableros a y b on del mismo tamaño. Si lo son,
# devuelve true, inicializa el tablero resultado y almacena en cada
# celda del mismo un caracter '<', '>' o '=' representando el
# resultado de la comparación de las celdas respectivas de los
# tableros a y b. Devuelve false en otro caso. 
# bool comparar_tableros_celda_a_celda(Tablero* resultado, Tablero* a, Tablero* b);
comparar_tableros_celda_a_celda:
        # POR HACER
        break

# Clasifica los números de array entrada (de longitud n_elementos) en
# pares e impares, almacenandolos respectivamente en los arrays pares
# e impares. Devuelve el número de elementos almacenados en el array
# pares (el número de elementos almacenados en el array impares será
# lo que falte hasta n_elementos). 
# int clasificar_numeros(int* entrada, int n_elementos, int* pares, int* impares);
clasificar_numeros:
        # POR HACER
        break

# Elimina del tablero los caracteres presentes en el array elimina, de
# tamaño n_eliminar 
# void eliminar_caracteres(Tablero* tablero, char* eliminar, int n_eliminar);
eliminar_caracteres:
        # POR HACER
        break

item_menor_que:
	lw	$v0, 100($a1)
	lw	$v1, 100($a0)
	bne	$v1, $v0, B12_2
	lw	$t1, 104($a1)
	lw	$v0, 104($a0)
	slt	$v0, $v0, $t1
	jr	$ra
B12_2:	slt	$v0, $v1, $v0
	jr	$ra

# Ordena los elementos del array, de tamaño n_items
# void ordenar_items(Item* array, int n_items);
ordenar_items: 
	addiu	$sp, $sp, -8
	sw	$s1, 4($sp)
	sw	$s0, 0($sp)
	move	$s0, $a0        # array
	move	$s1, $a1        # n_items
	li	$at, 0          # it
        li      $s5, 108        # sizeof(Item)
B13_2:	bge	$at, $s1, B13_7
        beqz    $at, B13_3
        mul	$t3, $at, $s5
        addu    $a0, $s0, $t3
        subu    $a1, $a0, $s5
        jal     item_menor_que
        bnez    $v0, B13_4        
B13_3:  addiu   $at, $at, 1
        j       B13_2
B13_4:  la      $a0, item_auxiliar
        addu    $a1, $s0, $s3
        li      $a2, 108
        jal     memcpy
        addu    $a0, $s0, $t3
        subu    $a1, $a0, $s5
        li      $a2, 108
        jal     memcpy
        addu    $a0, $s0, $t3
        subu    $a0, $a0, $s5
        la      $a1, item_auxiliar
        li      $a2, 108
        j       memcpy
        addiu   $at, $at, -1
        j       B13_2
B13_7:	lw	$s1, 0($sp)
	lw	$s0, 4($sp)
	addiu	$sp, $sp, 8
	jr	$ra

	.globl	main
main:
	addiu	$sp, $sp, -9112
	sw	$ra, 9108($sp)
	sw	$fp, 9104($sp)
	sw	$s7, 9100($sp)
	sw	$s6, 9096($sp)
	sw	$s5, 9092($sp)
	sw	$s4, 9088($sp)
	sw	$s3, 9084($sp)
	sw	$s2, 9080($sp)
	sw	$s1, 9076($sp)
	sw	$s0, 9072($sp)
	move	$fp, $sp
	addiu	$sp, $sp, -16
	jal	clear_screen
	addiu	$sp, $sp, 16
	la	$t1, str005
	sw	$t1, 96($fp)
	la	$t1, str006
	sw	$t1, 92($fp)
	la	$t1, str025
	sw	$t1, 88($fp)
	la	$t1, str024
	sw	$t1, 84($fp)
	addiu	$s4, $fp, 8040
	la	$t1, pieza1
	sw	$t1, 80($fp)
	la	$s6, str007
	sw	$s6, 76($fp)
	la	$t1, str008
	sw	$t1, 132($fp)
	la	$t1, str009
	sw	$t1, 128($fp)
	la	$t1, main.t1
	sw	$t1, 72($fp)
	addiu	$t1, $fp, 7008
	sw	$t1, 68($fp)
	la	$t1, main.t2
	sw	$t1, 64($fp)
	addiu	$t1, $fp, 5976
	sw	$t1, 60($fp)
	la	$t1, main.t3
	sw	$t1, 56($fp)
	addiu	$s7, $fp, 4944
	la	$t1, main.t4
	sw	$t1, 52($fp)
	addiu	$s0, $fp, 3912
	la	$t1, str010
	sw	$t1, 124($fp)
	la	$t1, str011
	sw	$t1, 120($fp)
	la	$t1, str012
	sw	$t1, 116($fp)
	la	$t1, str014
	sw	$t1, 112($fp)
	la	$t1, str013
	sw	$t1, 108($fp)
	la	$t1, main.test
	sw	$t1, 48($fp)
	la	$t1, str015
	sw	$t1, 44($fp)
	la	$t1, str016
	sw	$t1, 40($fp)
	la	$t1, str017
	sw	$t1, 36($fp)
	la	$t1, main.t118
	sw	$t1, 32($fp)
	la	$t1, main.t219
	sw	$t1, 28($fp)
	la	$v0, str019
	sw	$v0, 24($fp)
	la	$t1, str018
	sw	$t1, 20($fp)
	la	$t1, str020
	sw	$t1, 104($fp)
	la	$t1, str021
	sw	$t1, 100($fp)
	la	$t1, main.test24
	sw	$t1, 16($fp)
	la	$t1, str022
	sw	$t1, 12($fp)
	la	$t1, str023
	sw	$t1, 8($fp)
	j	B14_2
B14_1:	addiu	$sp, $sp, -16
	lw	$a0, 88($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	jal	read_character
	addiu	$sp, $sp, 16
B14_2:	addiu	$sp, $sp, -16
	lw	$a0, 96($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	jal	read_character
	addiu	$sp, $sp, 16
	move	$s1, $v0
	addiu	$sp, $sp, -16
	lw	$a0, 92($fp)
	jal	print_string
	sll	$t1, $s1, 24
	sra	$t1, $t1, 24
	addiu	$v0, $t1, -48
	li	$t1, 5
	sltu	$t1, $t1, $v0
	addiu	$sp, $sp, 16
	bnez	$t1, B14_1
	sll	$t1, $v0, 2
	lw	$t1, jump_table000($t1)
	jr	$t1
B14_4:	addiu	$sp, $sp, -16
	lw	$a0, 84($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 0
	jal	mips_exit
	addiu	$sp, $sp, 16
	j	B14_2
B14_5:	addiu	$sp, $sp, -16
	move	$a0, $s4
	li	$a1, 10
	li	$a2, 30
	jal	tablero_init
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	move	$a0, $s4
	li	$a1, 2
	li	$a2, 4
	lw	$a3, 80($fp)
	jal	tablero_colocar_pieza
	addiu	$sp, $sp, 16
	li	$s2, 0
	j	B14_7
B14_6:	addiu	$sp, $sp, -16
	move	$a0, $s4
	jal	simular_vida
	addiu	$sp, $sp, 16
	addiu	$s2, $s2, 1
B14_7:	addiu	$sp, $sp, -16
	jal	clear_screen
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	move	$a0, $s6
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	move	$a0, $s2
	jal	print_integer
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	lw	$a0, 132($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	move	$a0, $s4
	jal	tablero_print
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	lw	$a0, 128($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	jal	read_character
	sll	$t1, $v0, 24
	sra	$t1, $t1, 24
	ori	$t1, $t1, 32
	li	$v0, 120
	addiu	$sp, $sp, 16
	beq	$t1, $v0, B14_2
	j	B14_6
B14_9:	addiu	$sp, $sp, -16
	lw	$s2, 68($fp)
	move	$a0, $s2
	lw	$a1, 72($fp)
	li	$a2, 1032
	jal	memcpy
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	lw	$s5, 60($fp)
	move	$a0, $s5
	lw	$a1, 64($fp)
	li	$a2, 1032
	jal	memcpy
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	move	$a0, $s7
	lw	$a1, 56($fp)
	li	$a2, 1032
	jal	memcpy
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	move	$a0, $s0
	lw	$a1, 52($fp)
	li	$a2, 1032
	jal	memcpy
	addiu	$sp, $sp, 16
	li	$s1, 0
	sw	$s2, 2848($fp)
	sw	$s5, 2852($fp)
	sw	$s5, 2856($fp)
	sw	$s7, 2860($fp)
	sw	$s7, 2864($fp)
	sw	$s0, 2868($fp)
	sw	$s0, 2872($fp)
	sw	$s7, 2876($fp)
B14_10:	addiu	$sp, $sp, -16
	lw	$a0, 124($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$t1, $fp, 2848
	addu	$s2, $t1, $s1
	lw	$a0, 0($s2)
	addiu	$sp, $sp, -16
	jal	tablero_print
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	lw	$a0, 120($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	lw	$a0, 4($s2)
	addiu	$sp, $sp, -16
	jal	tablero_print
	addiu	$sp, $sp, 16
	addiu	$a0, $fp, 2880
	lw	$a2, 4($s2)
	lw	$a1, 0($s2)
	addiu	$sp, $sp, -16
	jal	comparar_tableros_celda_a_celda
	addiu	$sp, $sp, 16
	beqz	$v0, B14_12
	addiu	$sp, $sp, -16
	lw	$a0, 116($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	addiu	$a0, $fp, 2880
	jal	tablero_print
	j	B14_13
B14_12:	addiu	$sp, $sp, -16
	lw	$a0, 108($fp)
	jal	print_string
B14_13:	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	lw	$a0, 112($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	jal	read_character
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	la	$a0, str006			
	jal	print_string
	addiu	$s1, $s1, 8
	li	$t1, 32
	addiu	$sp, $sp, 16
	bne	$s1, $t1, B14_10
	j	B14_2
B14_15:	addiu	$sp, $sp, -16
	addiu	$s1, $fp, 2768
	move	$a0, $s1
	lw	$a1, 48($fp)
	li	$a2, 80
	jal	memcpy
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	lw	$a0, 44($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	li	$s2, 0
	li	$s3, 80
B14_16:	addu	$t1, $s1, $s2
	lw	$a0, 0($t1)
	addiu	$sp, $sp, -16
	jal	print_integer
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 32
	jal	print_character
	addiu	$s2, $s2, 4
	addiu	$sp, $sp, 16
	bne	$s2, $s3, B14_16
	move	$s6, $sp
	addiu	$sp, $sp, 0
	addiu	$s5, $sp, -80
	move	$sp, $s5
	addiu	$sp, $sp, 0
	addiu	$sp, $sp, 0
	addiu	$a0, $fp, 2768
	addiu	$s2, $sp, -80
	move	$sp, $s2
	addiu	$sp, $sp, 0
	addiu	$sp, $sp, -16
	li	$a1, 20
	move	$a2, $s5
	move	$a3, $s2
	jal	clasificar_numeros
	addiu	$sp, $sp, 16
	move	$s3, $v0
	addiu	$sp, $sp, -16
	lw	$a0, 40($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	slti	$t1, $s3, 1
	move	$s1, $s3
	bnez	$t1, B14_19
B14_18:	lw	$a0, 0($s5)
	addiu	$sp, $sp, -16
	jal	print_integer
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 32
	jal	print_character
	addiu	$sp, $sp, 16
	addiu	$s1, $s1, -1
	addiu	$s5, $s5, 4
	bnez	$s1, B14_18
B14_19:	addiu	$sp, $sp, -16
	lw	$a0, 36($fp)
	jal	print_string
	li	$t1, 20
	subu	$s1, $t1, $s3
	slti	$t1, $s1, 1
	addiu	$sp, $sp, 16
	bnez	$t1, B14_21
B14_20:	lw	$a0, 0($s2)
	addiu	$sp, $sp, -16
	jal	print_integer
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 32
	jal	print_character
	addiu	$sp, $sp, 16
	addiu	$s1, $s1, -1
	addiu	$s2, $s2, 4
	bnez	$s1, B14_20
B14_21:	addiu	$sp, $sp, -16
	li	$a0, 10
	jal	print_character
	addiu	$sp, $sp, 16
	move	$sp, $s6
	lw	$s6, 76($fp)
	j	B14_2
B14_22:	addiu	$sp, $sp, -16
	addiu	$s1, $fp, 1736
	move	$a0, $s1
	lw	$a1, 32($fp)
	li	$a2, 1032
	jal	memcpy
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	addiu	$s2, $fp, 704
	move	$a0, $s2
	lw	$a1, 28($fp)
	li	$a2, 1032
	jal	memcpy
	addiu	$sp, $sp, 16
	sw	$s1, 680($fp)
	li	$s1, 0
	lw	$t1, 20($fp)
	sw	$t1, 684($fp)
	li	$t1, 4
	sb	$t1, 688($fp)
	sw	$s2, 692($fp)
	lw	$t1, 24($fp)
	sw	$t1, 696($fp)
	li	$t1, 3
	sb	$t1, 700($fp)
B14_23:	addiu	$sp, $sp, -16
	lw	$a0, 104($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$t1, $fp, 680
	addu	$s2, $t1, $s1
	lw	$a0, 4($s2)
	addiu	$sp, $sp, -16
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	lw	$a0, 100($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	lw	$a0, 0($s2)
	addiu	$sp, $sp, -16
	jal	tablero_print
	addiu	$sp, $sp, 16
	la	$a0, str012			
	addiu	$sp, $sp, -16
	jal	print_string
	addiu	$sp, $sp, 16
	lb	$a2, 8($s2)
	lw	$a1, 4($s2)
	lw	$a0, 0($s2)
	addiu	$sp, $sp, -16
	jal	eliminar_caracteres
	addiu	$sp, $sp, 16
	lw	$a0, 0($s2)
	addiu	$sp, $sp, -16
	jal	tablero_print
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 10
	jal	print_character
	addiu	$s1, $s1, 12
	li	$t1, 24
	addiu	$sp, $sp, 16
	bne	$s1, $t1, B14_23
	j	B14_2
B14_25:	addiu	$sp, $sp, -16
	addiu	$s2, $fp, 136
	move	$a0, $s2
	lw	$a1, 16($fp)
	li	$a2, 540
	jal	memcpy
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	lw	$a0, 12($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	li	$s5, 0
	li	$s3, 540
B14_26:	addu	$s1, $s2, $s5
	addiu	$sp, $sp, -16
	move	$a0, $s1
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 32
	jal	print_character
	addiu	$sp, $sp, 16
	lw	$a0, 100($s1)
	addiu	$sp, $sp, -16
	jal	print_integer
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 32
	jal	print_character
	addiu	$sp, $sp, 16
	lw	$a0, 104($s1)
	addiu	$sp, $sp, -16
	jal	print_integer
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 32
	jal	print_character
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 10
	jal	print_character
	addiu	$s5, $s5, 108
	addiu	$sp, $sp, 16
	bne	$s5, $s3, B14_26
	li	$s3, 540
	addiu	$sp, $sp, -16
	addiu	$s2, $fp, 136
	move	$a0, $s2
	li	$a1, 5
	jal	ordenar_items
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	lw	$a0, 8($fp)
	jal	print_string
	addiu	$sp, $sp, 16
	li	$s5, 0
B14_28:	addu	$s1, $s2, $s5
	addiu	$sp, $sp, -16
	move	$a0, $s1
	jal	print_string
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 32
	jal	print_character
	addiu	$sp, $sp, 16
	lw	$a0, 100($s1)
	addiu	$sp, $sp, -16
	jal	print_integer
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 32
	jal	print_character
	addiu	$sp, $sp, 16
	lw	$a0, 104($s1)
	addiu	$sp, $sp, -16
	jal	print_integer
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 32
	jal	print_character
	addiu	$sp, $sp, 16
	addiu	$sp, $sp, -16
	li	$a0, 10
	jal	print_character
	addiu	$s5, $s5, 108
	addiu	$sp, $sp, 16
	bne	$s5, $s3, B14_28
	j	B14_2
	lw	$ra, 9108($sp)
	lw	$fp, 9104($sp)
	lw	$s7, 9100($sp)
	lw	$s6, 9096($sp)
	lw	$s5, 9092($sp)
	lw	$s4, 9088($sp)
	lw	$s3, 9084($sp)
	lw	$s2, 9080($sp)
	lw	$s1, 9076($sp)
	lw	$s0, 9072($sp)
	addiu	$sp, $sp, 9112
        jr      $ra

        
print_integer:
	li	$v0, 1
	syscall	
	jr	$ra

print_character:
	li	$v0, 11
	syscall	
	jr	$ra

print_string:
	li	$v0, 4
	syscall	
	jr	$ra

read_character:
	li	$v0, 12
	syscall	
	jr	$ra

clear_screen:
	li	$v0, 39
	syscall	
	jr	$ra

mips_exit:
	li	$v0, 17
	syscall	
	jr	$ra

memcpy:
	move	$v0, $a0
memcpy_loop:
	beqz	$a2, memcpy_return
	lbu	$t0, 0($a1)
	sb	$t0, 0($a0)
	addiu	$a0, $a0, 1
	addiu	$a1, $a1, 1
	addiu	$a2, $a2, -1
	j	memcpy_loop
memcpy_return:
	jr	$ra

