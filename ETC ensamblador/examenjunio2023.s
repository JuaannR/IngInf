# Examen de ETC de ensamblador

	.data	
	.align	2
jump_table000:
	.word	B11_1
	.word	B11_4
	.word	B11_12
	.word	B11_18
	.align	2
pacientes:
	.word	7
	.asciiz		"Zorka Setare Kuhn\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	1956
	.word	8
	.word	6
	.word	162
	.byte	77
	.space	3
	.word	6
	.asciiz		"Elin Konstantin Silva\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	1967
	.word	11
	.word	1
	.word	168
	.byte	77
	.space	3
	.word	3
	.asciiz		"Robert Susanoo Van Bokhoven\0\0\0\0\0\0\0"
	.space	1
	.word	1987
	.word	2
	.word	16
	.word	172
	.byte	72
	.space	3
	.word	8
	.asciiz		"Astraia Agostino Saari\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	1995
	.word	1
	.word	24
	.word	187
	.byte	77
	.space	3
	.word	2
	.asciiz		"Farouk Akmad Bridges\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	1978
	.word	3
	.word	17
	.word	180
	.byte	72
	.space	3
	.space	900
	.align	2
num_pacientes:
	.word	5
	.align	2
consultas:
	.word	6
	.word	2015
	.word	4
	.word	5
	.asciiz		"Resfriado."
	.space	139
	.space	2
	.word	8
	.word	2015
	.word	6
	.word	18
	.asciiz		"Bronquiolitis."
	.space	135
	.space	2
	.word	2
	.word	2015
	.word	7
	.word	3
	.asciiz		"Faringitis."
	.space	138
	.space	2
	.word	6
	.word	2015
	.word	7
	.word	9
	.asciiz		"Otitis."
	.space	142
	.space	2
	.word	7
	.word	2015
	.word	10
	.word	4
	.asciiz		"Pierna izquierda rota."
	.space	127
	.space	2
	.word	3
	.word	2015
	.word	11
	.word	15
	.asciiz		"Dolor de muelas."
	.space	133
	.space	2
	.word	2
	.word	2015
	.word	1
	.word	17
	.asciiz		"Astigmatismo."
	.space	136
	.space	2
	.word	2
	.word	2015
	.word	4
	.word	12
	.asciiz		"Conjuntivitis."
	.space	135
	.space	2
	.word	6
	.word	2015
	.word	4
	.word	16
	.asciiz		"Miopía."
	.space	141
	.space	2
	.word	2
	.word	2015
	.word	5
	.word	15
	.asciiz		"Lipotimia."
	.space	139
	.space	2
	.word	8
	.word	2016
	.word	6
	.word	26
	.asciiz		"Rubéola."
	.space	140
	.space	2
	.word	7
	.word	2016
	.word	9
	.word	26
	.asciiz		"Gripe."
	.space	143
	.space	2
	.word	7
	.word	2016
	.word	9
	.word	30
	.asciiz		"Hipocondria."
	.space	137
	.space	2
	.word	3
	.word	2016
	.word	10
	.word	24
	.asciiz		"Sinusitis."
	.space	139
	.space	2
	.word	3
	.word	2016
	.word	1
	.word	14
	.asciiz		"Dolor de garganta."
	.space	131
	.space	2
	.word	2
	.word	2016
	.word	3
	.word	15
	.asciiz		"Gota."
	.space	144
	.space	2
	.word	2
	.word	2016
	.word	3
	.word	23
	.asciiz		"Lepra."
	.space	143
	.space	2
	.word	3
	.word	2016
	.word	3
	.word	26
	.asciiz		"Gastroenteritis."
	.space	133
	.space	2
	.word	3
	.word	2016
	.word	4
	.word	13
	.asciiz		"Bronquitis."
	.space	138
	.space	2
	.word	7
	.word	2016
	.word	6
	.word	7
	.asciiz		"Pierna derecha rota."
	.space	129
	.space	2
	.space	13440
	.align	2
num_consultas:
	.word	20
str000:
	.asciiz		"ID: "
str001:
	.asciiz		", Nombre: "
str002:
	.asciiz		", Fecha nacimiento: "
str003:
	.asciiz		", Altura: "
str004:
	.asciiz		"cm\n"
str005:
	.asciiz		"\n\nExamen de ETC de ensamblador\n\n 1. Ordenar pacientes por edad\n 2. Mostrar estadísticas anuales\n 3. Mostrar y contar consultas por paciente\n 0. Salir\n\nElige una opción: "
str006:
	.asciiz		"\n\n"
str007:
	.asciiz		"Pacientes antes de ordenarlos:\n"
str008:
	.asciiz		"\nPacientes después de ordenarlos:\n"
str009:
	.asciiz		"Estadísticas anuales de "
str010:
	.asciiz		":\nTotal de consultas: "
str011:
	.asciiz		"\nTotal de pacientes: "
str012:
	.asciiz		" ["
str013:
	.asciiz		"]"
str014:
	.asciiz		"\nAltura media de los pacientes: "
str015:
	.asciiz		"Total de consultas para el paciente "
str016:
	.asciiz		": "
str017:
	.asciiz		"¡Adiós!\n"
str018:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"

	.text	

# EJERCICIO 1
ordenar_pacientes_por_nacimiento:
	addiu	$sp, $sp, -16
	sw	$s2, 12($sp)
	sw	$s1, 8($sp)
	sw	$s0, 4($sp)
	sw	$ra, 0($sp)
	li      $s0, 0 #i=0
	lw      $s1, num_pacientes
        la      $s2, pacientes
B0_0:   bge     $s0, $s1, B0_1
	beq     $s0, 0, B0_2
	mul     $t0, $s0, 60
	addu    $a0, $s2, $t0
	addiu	$a0, $a0, 40
	addiu   $a1, $a0, -60
	jal     comparar_fechas
	bne     $v0, $0, B0_2
	move    $a0, $s0
	addiu   $a1, $a0, -1
	jal     intercambiar_pacientes
	addiu   $s0, $s0, -1
	j       B0_0
B0_2:   addiu   $s0, $s0, 1
	j       B0_0
B0_1:   lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	addiu	$sp, $sp, 16
	jr      $ra

# EJERCICIO 2
calcular_estadisticas:
	addiu 	$sp, $sp, -24
	sw	$s4, 20($sp)
	sw	$s3, 16($sp)
	sw	$s2, 12($sp)
	sw	$s1, 8($sp)
	sw	$s0, 4($sp)
	sw	$ra, 0($sp)
        li	$s0, 0 #i=0
        lw	$s1, num_consultas
        move	$s4, $a0
        move	$s2, $a1 #estadisticas direccion
        cfor:
        bge	$s0, $s1, cfin_for
        #primer if
        la	$t0, consultas
        mul	$t1, $s0, 168 #i x tamaño
        addu	$s3, $t0, $t1 #s3 es consultas[i]
        lw	$t1, 4($s3) #consultas[i].fecha.ano
        bne	$t1, $s4, cfin_if2
        lw	$t2, 0($s2)
        addiu	$t2, $t2, 1
        sw	$t2, 0($s2)
        #segundo if
        move	$a0, $s2 #$s2 es estadisticas
        lw	$t7, 0($s3)
        move	$a1, $t7 #consultas[i].paciente_id
        jal paciente_ya_visto
        bne	$v0, $0, cfin_if2
        lw	$t4, 4($s2) #t4 es indice
        addiu	$t2, $t4, 1
        sw	$t2, 4($s2) #estadisticas->num_pacientes_id_vistos = indice + 1
        la	$t5, 8($s2)
        mul	$t7, $t4, 4
        addu	$t5, $t5, $t7 #t5 es la direccion 
        lw	$t6, 0($s3)
        sw	$t6, 0($t5) #estadisticas->pacientes_id_vistos[indice] = consultas[i].paciente_id;
        move	$a0, $t6
        jal	buscar_paciente_por_id
        move	$t6, $v0 #paciente *p
        lw	$t5, 88($s2)
        lw	$t3, 52($t6)
        addu	$t5, $t5, $t3
        sw	$t5, 88($s2)
        cfin_if2:
        addiu	$s0, $s0, 1
        j	cfor
        cfin_for:
        lw	$t1, 4($s2)
        ble	$t1, 0, cfin_if3
        lw	$t2, 88($s2)
        lw	$t3, 4($s2)
        div	$t4, $t2, $t3
        sw	$t4, 88($s2)
        cfin_if3:
        lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
        lw	$s3, 16($sp)
        lw	$s4, 20($sp)
        addiu	$sp, $sp, 24
        jr	$ra

# EJERCICIO 3
mostrar_y_contar_consultas:
	#apilar
	addiu 	$sp, $sp, -20
	sw	$s3, 16($sp)
	sw	$s2, 12($sp)
	sw	$s1, 8($sp)
	sw	$s0, 4($sp)
	sw	$ra, 0($sp)
	
	li	$s0, 0 #i=0
	li	$s1, 0 #cont=0
	move	$s2, $a0 #paciente
	mc_for:
	lw	$t0, num_consultas
	bge	$s0, $t0, mc_finfor
	#vamos a hacer el if
	la	$t1, consultas
	mul	$t2, $s0, 168 #iXtamaño
	addu	$t2, $t2, $t1
	lw	$t3, 0($t2) #consultas[i].paciente_id
	lw	$t4, 0($s2) #paciente->id
	#if
	bne	$t3, $t4, mc_finif
	addiu	$s1, $s1, 1 #cont++
	move	$s3, $t2 #&consultas[i]
	#print_integer(consultas[i].fecha.anyo);
	lw	$a0, 4($s3)
	jal print_integer
	#print_character(-);
	li	$a0, '-'
	jal	print_character
	#print_integer(consultas[i].fecha.mes);
	lw	$a0, 8($s3)
	jal print_integer
	#print_character(-);
	li	$a0, '-'
	jal	print_character
	#print_integer(consultas[i].fecha.dia);
	lw	$a0, 12($s3)
	jal print_integer
	#print_character( );
	li	$a0, ' '
	jal	print_character
	#print_string(consultas[i].informe);
	la	$a0, 16($s3)
	jal	print_string
	#print retorno de carro
	li	$a0, '\n'
	jal	print_character
	mc_finif:
	addiu	$s0, $s0, 1 #i++
	j	mc_for
	mc_finfor:
	move	$v0, $s1 #return cont
	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
        lw	$s3, 16($sp)
        addiu	$sp, $sp, 20
       	jr	$ra

mostrar_fecha:
	addiu	$sp, $sp, -32
	sw	$ra, 28($sp)
	sw	$s1, 24($sp)
	sw	$s0, 20($sp)
	move	$s0, $a0
	lw	$a0, 0($a0)
	jal	longitud_integer
	li	$t1, 4
	subu	$a1, $t1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 0($s0)
	jal	print_integer
	li	$a0, 45
	jal	print_character
	lw	$a0, 4($s0)
	jal	longitud_integer
	li	$s1, 2
	subu	$a1, $s1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 4($s0)
	jal	print_integer
	li	$a0, 45
	jal	print_character
	lw	$a0, 8($s0)
	jal	longitud_integer
	subu	$a1, $s1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 8($s0)
	jal	print_integer
	lw	$s0, 20($sp)
	lw	$s1, 24($sp)
	lw	$ra, 28($sp)
	addiu	$sp, $sp, 32
	jr	$ra

longitud_integer:
	slti	$v0, $a0, 1
	beqz	$a0, B8_3
	lui	$t1, 26214
	ori	$v1, $t1, 26215
B8_2:	mult	$a0, $v1
	mfhi	$t1
	srl	$a1, $t1, 31
	sra	$t1, $t1, 2
	addu	$t1, $t1, $a1
	addiu	$v0, $v0, 1
	addiu	$a0, $a0, 9
	sltiu	$a1, $a0, 19
	move	$a0, $t1
	beqz	$a1, B8_2
B8_3:	jr	$ra

repite_caracter:
	addiu	$sp, $sp, -32
	sw	$ra, 28($sp)
	sw	$s1, 24($sp)
	sw	$s0, 20($sp)
	blez	$a1, B9_3
	move	$s0, $a1
	move	$s1, $a0
B9_2:	move	$a0, $s1
	jal	print_character
	addiu	$s0, $s0, -1
	bnez	$s0, B9_2
B9_3:	lw	$s0, 20($sp)
	lw	$s1, 24($sp)
	lw	$ra, 28($sp)
	addiu	$sp, $sp, 32
	jr	$ra

mostrar_paciente:
	addiu	$sp, $sp, -24
	sw	$ra, 20($sp)
	sw	$s0, 16($sp)
	move	$s0, $a0
	la	$a0, str000
	jal	print_string
	lw	$a0, 0($s0)
	jal	longitud_integer
	li	$t1, 4
	subu	$a1, $t1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 0($s0)
	jal	print_integer
	la	$a0, str001
	jal	print_string
	addiu	$a0, $s0, 4
	jal	print_string
	la	$a0, str002
	jal	print_string
	addiu	$a0, $s0, 40
	jal	mostrar_fecha
	la	$a0, str003
	jal	print_string
	lw	$a0, 52($s0)
	jal	print_integer
	la	$a0, str004
	jal	print_string
	lw	$s0, 16($sp)
	lw	$ra, 20($sp)
	addiu	$sp, $sp, 24
	jr	$ra

intercambiar_pacientes:
	addiu	$sp, $sp, -96
	sw	$ra, 92($sp)
	sw	$s3, 88($sp)
	sw	$s2, 84($sp)
	sw	$s1, 80($sp)
	sw	$s0, 76($sp)
	move	$s0, $a1
	sll	$t1, $a0, 2
	sll	$v0, $a0, 6
	subu	$t1, $v0, $t1
	la	$s3, pacientes
	addu	$s1, $s3, $t1
	addiu	$s2, $sp, 16
	move	$a0, $s2
	move	$a1, $s1
	li	$a2, 60
	jal	memcpy
	sll	$t1, $s0, 2
	sll	$v0, $s0, 6
	subu	$t1, $v0, $t1
	addu	$s0, $s3, $t1
	move	$a0, $s1
	move	$a1, $s0
	li	$a2, 60
	jal	memcpy
	move	$a0, $s0
	move	$a1, $s2
	li	$a2, 60
	jal	memcpy
	lw	$s0, 76($sp)
	lw	$s1, 80($sp)
	lw	$s2, 84($sp)
	lw	$s3, 88($sp)
	lw	$ra, 92($sp)
	addiu	$sp, $sp, 96
	jr	$ra

buscar_paciente_por_id:
	lw	$v1, num_pacientes
	li	$v0, 0
	blez	$v1, B5_4
	la	$a1, pacientes
B5_2:	lw	$t1, 0($a1)
	beq	$t1, $a0, B5_5
	addiu	$v1, $v1, -1
	addiu	$a1, $a1, 60
	bnez	$v1, B5_2
B5_4:	jr	$ra
B5_5:	move	$v0, $a1
	jr	$ra

comparar_fechas:
	lw	$v1, 0($a1)
	lw	$a2, 0($a0)
	slt	$t1, $a2, $v1
	li	$v0, 1
	bnez	$t1, B1_6
	li	$v0, 0
	bne	$a2, $v1, B1_6
	lw	$t1, 4($a1)
	lw	$v0, 4($a0)
	slt	$v0, $v0, $t1
	bnez	$v0, B1_6
	bne	$a2, $v1, B1_6
	lw	$t1, 4($a1)
	lw	$v1, 4($a0)
	li	$v0, 0
	bne	$v1, $t1, B1_6
	lw	$t1, 8($a1)
	lw	$v0, 8($a0)
	slt	$v0, $v0, $t1
B1_6:	jr	$ra

paciente_ya_visto:
	lw	$v1, 4($a0)
	slt	$v0, $zero, $v1
	blez	$v1, B4_6
	lw	$t1, 8($a0)
	beq	$t1, $a1, B4_6
	addiu	$v0, $a0, 12
	li	$a2, 1
B4_3:	move	$a0, $a2
	beq	$v1, $a2, B4_5
	addiu	$t1, $v0, 4
	addiu	$a2, $a0, 1
	lw	$a3, 0($v0)
	move	$v0, $t1
	bne	$a3, $a1, B4_3
B4_5:	slt	$v0, $a0, $v1
B4_6:	jr	$ra

	.globl	main
main:
	addiu	$sp, $sp, -200
	sw	$ra, 196($sp)
	sw	$fp, 192($sp)
	sw	$s7, 188($sp)
	sw	$s6, 184($sp)
	sw	$s5, 180($sp)
	sw	$s4, 176($sp)
	sw	$s3, 172($sp)
	sw	$s2, 168($sp)
	sw	$s1, 164($sp)
	sw	$s0, 160($sp)
	jal	clear_screen
	addiu	$s0, $sp, 64
	addiu	$t1, $s0, 8
	sw	$t1, 60($sp)
	la	$t1, str005
	sw	$t1, 40($sp)
	la	$t1, str006
	sw	$t1, 36($sp)
	la	$t1, str018
	sw	$t1, 32($sp)
	la	$t1, str017
	sw	$t1, 28($sp)
	la	$t1, str007
	sw	$t1, 24($sp)
	la	$t1, str008
	sw	$t1, 20($sp)
	la	$s7, str009
	la	$fp, str010
	la	$s3, str011
	la	$t1, str012
	sw	$t1, 56($sp)
	la	$t1, str013
	sw	$t1, 52($sp)
	la	$s6, str014
	la	$t1, str015
	sw	$t1, 48($sp)
	la	$t1, str016
	sw	$t1, 44($sp)
	j	B11_2
B11_1:	lw	$a0, 28($sp)
	jal	print_string
	li	$a0, 0
	jal	mips_exit
B11_2:	lw	$a0, 40($sp)
	jal	print_string
	jal	read_character
	lw	$a0, 36($sp)
	move	$s4, $v0
	jal	print_string
	andi	$t1, $s4, 255
	addiu	$v0, $t1, -48
	sltiu	$t1, $v0, 4
	beqz	$t1, B11_11
	sll	$t1, $v0, 2
	lw	$t1, jump_table000($t1)
	jr	$t1
B11_4:	lw	$a0, 24($sp)
	jal	print_string
	lw	$t1, num_pacientes
	blez	$t1, B11_7
	la	$s4, pacientes
	li	$s1, 0
B11_6:	move	$a0, $s4
	jal	mostrar_paciente
	addiu	$s1, $s1, 1
	lw	$t1, num_pacientes
	slt	$t1, $s1, $t1
	addiu	$s4, $s4, 60
	bnez	$t1, B11_6
B11_7:	jal	ordenar_pacientes_por_nacimiento
	lw	$a0, 20($sp)
	jal	print_string
	lw	$t1, num_pacientes
	blez	$t1, B11_10
	la	$s4, pacientes
	li	$s1, 0
B11_9:	move	$a0, $s4
	jal	mostrar_paciente
	addiu	$s1, $s1, 1
	lw	$t1, num_pacientes
	slt	$t1, $s1, $t1
	addiu	$s4, $s4, 60
	bnez	$t1, B11_9
B11_10:	li	$a0, 10
	jal	print_character
	j	B11_2
B11_11:	lw	$a0, 32($sp)
	jal	print_string
	jal	read_character
	j	B11_2
B11_12:	li	$s4, 2015
	j	B11_14
B11_13:	move	$a0, $s6
	jal	print_string
	lw	$a0, 152($sp)
	jal	print_integer
	la	$a0, str006
	jal	print_string
	addiu	$s4, $s4, 1
	li	$t1, 2017
	beq	$s4, $t1, B11_2
B11_14:	move	$a0, $s7
	jal	print_string
	move	$a0, $s4
	jal	print_integer
	move	$a0, $s0
	li	$a1, 0
	li	$a2, 92
	jal	memset
	move	$a0, $s4
	move	$a1, $s0
	jal	calcular_estadisticas
	move	$a0, $fp
	jal	print_string
	lw	$a0, 64($sp)
	jal	print_integer
	move	$a0, $s3
	jal	print_string
	lw	$s5, 68($sp)
	move	$a0, $s5
	jal	print_integer
	blez	$s5, B11_13
	lw	$a0, 56($sp)
	jal	print_string
	lw	$s1, 60($sp)
B11_16:	li	$a0, 32
	jal	print_character
	lw	$a0, 0($s1)
	jal	print_integer
	addiu	$s5, $s5, -1
	addiu	$s1, $s1, 4
	bnez	$s5, B11_16
	lw	$a0, 52($sp)
	jal	print_string
	j	B11_13
B11_18:	lw	$t1, num_pacientes
	blez	$t1, B11_2
	la	$s4, pacientes
	li	$s1, 0
B11_20:	move	$a0, $s4
	jal	mostrar_paciente
	move	$a0, $s4
	jal	mostrar_y_contar_consultas
	lw	$a0, 48($sp)
	move	$s5, $v0
	jal	print_string
	lw	$a0, 0($s4)
	jal	longitud_integer
	li	$t1, 4
	subu	$a1, $t1, $v0
	li	$a0, 48
	jal	repite_caracter
	lw	$a0, 0($s4)
	jal	print_integer
	lw	$a0, 44($sp)
	jal	print_string
	move	$a0, $s5
	jal	print_integer
	la	$a0, str006
	jal	print_string
	addiu	$s1, $s1, 1
	lw	$t1, num_pacientes
	slt	$t1, $s1, $t1
	addiu	$s4, $s4, 60
	bnez	$t1, B11_20
	j	B11_2

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

memset:
	move	$v0, $a0
memset_loop:
	beqz	$a2, memset_return
	sb	$a1, 0($a0)
	addiu	$a0, $a0, 1
	addiu	$a2, $a2, -1
	j	memset_loop
memset_return:
	jr	$ra

