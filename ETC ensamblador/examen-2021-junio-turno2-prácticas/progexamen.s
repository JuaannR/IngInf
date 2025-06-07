	.data	
jump_table000:
	.word	B5_1
	.word	B5_4
	.word	B5_6
	.word	B5_7
articulos:
	.word	2
	.word	20
	.asciiz		"Peras\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	3
	.word	10
	.asciiz		"Plátanos\0\0\0\0\0\0"
	.space	1
	.word	10
	.word	20
	.asciiz		"Manzanas\0\0\0\0\0\0"
	.space	1
	.word	6
	.word	30
	.asciiz		"Ciruelas\0\0\0\0\0\0"
	.space	1
	.word	20
	.word	20
	.asciiz		"Piñas\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	0
	.word	30
	.asciiz		"Aguacates\0\0\0\0\0"
	.space	1
	.word	5
	.word	40
	.asciiz		"Arándanos\0\0\0\0\0"
	.space	1
	.space	312
numarticulos:
	.word	7
facturas:
	.word	3
	.word	65
	.word	2
	.word	30
	.word	4
	.word	155
	.word	2
	.word	45
	.word	1
	.word	60
	.space	760
numfacturas:
	.word	5
str000:
	.asciiz		"  Artículo: "
str001:
	.asciiz		". Unidades: "
str002:
	.asciiz		". Precio unitario: "
str003:
	.asciiz		"Factura nº: "
str004:
	.asciiz		". Número de artículos: "
str005:
	.asciiz		". Importe total: "
str006:
	.asciiz		"\n\nExamen de ETC de ensamblador\n\n 1. Listado de facturas actuales\n 2. Ordenar artículos por valor total\n 3. Actualiza precio de artículos\n 0. Salir\n\nElige una opción: "
str007:
	.asciiz		"\n\n"
str008:
	.asciiz		"Listado de artículos sin ordenar:\n"
str009:
	.asciiz		"\nListado de artículos ordenados por valor total, de mayor a menor:\n"
main.arts:
	.word	2
	.word	20
	.asciiz		"Peras\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	3
	.word	10
	.asciiz		"Plátanos\0\0\0\0\0\0"
	.space	1
	.word	10
	.word	20
	.asciiz		"Manzanas\0\0\0\0\0\0"
	.space	1
	.word	6
	.word	30
	.asciiz		"Ciruelas\0\0\0\0\0\0"
	.space	1
	.word	20
	.word	20
	.asciiz		"Piñas\0\0\0\0\0\0\0\0\0"
	.space	1
	.word	0
	.word	30
	.asciiz		"Aguacates\0\0\0\0\0"
	.space	1
	.word	5
	.word	40
	.asciiz		"Arándanos\0\0\0\0\0"
	.space	1
str010:
	.asciiz		"Artículos antes del ajuste de precio:\n"
str011:
	.asciiz		"\nArtículos después del ajuste de precio (incremento del 20% cuando haya 5 o menos):\n"
str012:
	.asciiz		"¡Adiós!\n"
str013:
	.asciiz		"Opción incorrecta. Pulse cualquier tecla para seguir.\n"

	.text	


listar_articulos:
	addiu	$sp, $sp, -40	
	sw	$ra, 36($sp)
	sw	$s4, 32($sp)
	sw	$s3, 28($sp)
	sw	$s2, 24($sp)
	sw	$s1, 20($sp)
	sw	$s0, 16($sp)
	blez	$a1, B0_3	
	move	$s0, $a1
	addiu	$s1, $a0, 8	
	la	$s2, str000
	la	$s3, str001
	la	$s4, str002
B0_2:	move	$a0, $s2
	jal	print_string
	move	$a0, $s1	
	jal	print_string
	move	$a0, $s3	
	jal	print_string
	lw	$a0, -8($s1)	
	jal	print_integer
	move	$a0, $s4
	jal	print_string
	lw	$a0, -4($s1)	
	jal	print_integer
	li	$a0, 10
	jal	print_character
	addiu	$s0, $s0, -1	
	addiu	$s1, $s1, 24
	bnez	$s0, B0_2
B0_3:	lw	$s0, 16($sp)
	lw	$s1, 20($sp)
	lw	$s2, 24($sp)
	lw	$s3, 28($sp)
	lw	$s4, 32($sp)
	lw	$ra, 36($sp)
	addiu	$sp, $sp, 40
	jr	$ra

intercambiar_articulos:
	addiu	$sp, $sp, -24	
	sll	$t1, $a0, 3	
	sll	$v0, $a0, 4
	addu	$t1, $v0, $t1
	la	$v0, articulos
	addu	$t1, $v0, $t1
	lw	$v1, 4($t1)
	lw	$a0, 8($t1)
	lw	$a2, 12($t1)
	lw	$a3, 16($t1)
	lw	$t0, 20($t1)
	sw	$t0, 20($sp)
	sw	$a3, 16($sp)
	sw	$a2, 12($sp)
	sw	$a0, 8($sp)
	sw	$v1, 4($sp)
	lw	$v1, 0($t1)
	sw	$v1, 0($sp)
	sll	$v1, $a1, 3	
	sll	$a0, $a1, 4
	addu	$v1, $a0, $v1
	addu	$v0, $v0, $v1
	lw	$v1, 8($v0)
	lw	$a0, 12($v0)
	lw	$a1, 16($v0)
	lw	$a2, 20($v0)
	sw	$a2, 20($t1)
	sw	$a1, 16($t1)
	sw	$a0, 12($t1)
	sw	$v1, 8($t1)
	lw	$v1, 4($v0)
	sw	$v1, 4($t1)
	lw	$v1, 0($v0)
	sw	$v1, 0($t1)
	lw	$t1, 8($sp)	
	lw	$v1, 12($sp)
	lw	$a0, 16($sp)
	lw	$a1, 20($sp)
	sw	$a1, 20($v0)
	sw	$a0, 16($v0)
	sw	$v1, 12($v0)
	sw	$t1, 8($v0)
	lw	$t1, 4($sp)
	sw	$t1, 4($v0)
	lw	$t1, 0($sp)
	sw	$t1, 0($v0)
	addiu	$sp, $sp, 24	
	jr	$ra

### EJERCICIO 1 ###
listar_facturas:
	addiu	$sp, $sp, -16
	sw	$ra, 12($sp)
	sw	$s3, 8($sp)
	sw	$s2, 4($sp)
	sw	$s1, 0($sp)
	li	$t0, 0
	lw	$at, numfacturas
	la	$s2, facturas
B2_2:	bge	$t0, $at, B2_3
	la	$a0, str003
	jal	print_string
	addiu	$a0, $t0, 1	
	jal	print_integer
	la	$a0, str004
	jal	print_string
	sll	$s3, $t0, 3
	addu	$s3, $s2, $s3
	lw	$a0, 0($s3)
	jal	print_integer
	la	$a0, str005
	jal	print_string
	lw	$a0, 4($s3)
	jal	print_integer
	li	$a0, '\n'
	jal	print_character
	addiu	$t0, $t0, 1
	j	B2_2
B2_3:	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	lw	$s3, 12($sp)
	addiu	$sp, $sp, 16
	jr	$ra

### EJERCICIO 2 ###
ordenar_articulos_por_valor_total:
	# POR HACER
	break

### EJERCICIO 3 ###
actualiza_precio:
	# POR HACER
	break

	.globl	main
main:
	addiu	$sp, $sp, -248	
	sw	$ra, 244($sp)
	sw	$fp, 240($sp)
	sw	$s7, 236($sp)
	sw	$s6, 232($sp)
	sw	$s5, 228($sp)
	sw	$s4, 224($sp)
	sw	$s3, 220($sp)
	sw	$s2, 216($sp)
	sw	$s1, 212($sp)
	sw	$s0, 208($sp)
	jal	clear_screen	
	la	$s0, str006
	la	$s1, str007
	lui	$s6, 53248
	la	$t1, str013
	sw	$t1, 36($sp)
	la	$t1, str012
	sw	$t1, 32($sp)
	la	$t1, str008
	sw	$t1, 28($sp)
	la	$s5, articulos
	la	$t1, str009
	sw	$t1, 24($sp)
	la	$t1, main.arts
	sw	$t1, 20($sp)
	addiu	$fp, $sp, 40
	la	$s2, str010
	la	$s3, str011
	j	B5_2
B5_1:	lw	$a0, 32($sp)
	jal	print_string
	li	$a0, 0	
	jal	mips_exit
B5_2:	move	$a0, $s0	
	jal	print_string
	jal	read_character	
	move	$s4, $v0
	move	$a0, $s1	
	jal	print_string
	sll	$t1, $s4, 24	
	addu	$t1, $t1, $s6
	srl	$v0, $t1, 24
	sltiu	$t1, $v0, 4
	beqz	$t1, B5_5
	sll	$t1, $v0, 2	
	lw	$t1, jump_table000($t1)
	jr	$t1
B5_4:	jal	listar_facturas
	j	B5_2	
B5_5:	lw	$a0, 36($sp)	
	jal	print_string
	jal	read_character	
	j	B5_2
B5_6:	lw	$a0, 28($sp)
	jal	print_string
	lw	$a1, numarticulos
	move	$a0, $s5
	jal	listar_articulos
	jal	ordenar_articulos_por_valor_total
	lw	$a0, 24($sp)	
	jal	print_string
	lw	$a1, numarticulos	
	move	$a0, $s5
	jal	listar_articulos
	j	B5_2
B5_7:	move	$a0, $fp	
	lw	$a1, 20($sp)
	li	$a2, 168
	jal	memcpy
	move	$a0, $s2	
	jal	print_string
	move	$a0, $fp	
	li	$a1, 7
	jal	listar_articulos
	move	$a0, $fp	
	li	$a1, 7
	li	$a2, 20
	li	$a3, 5
	jal	actualiza_precio
	move	$a0, $s3	
	jal	print_string
	move	$a0, $fp	
	li	$a1, 7
	jal	listar_articulos
	j	B5_2	

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
        jr      $ra
        
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
