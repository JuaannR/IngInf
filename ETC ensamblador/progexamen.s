montanas:
	.asciiz		"Dhaulagiri"	# 10 +1
	.space	9			# 9
	.word	8167			# 4		total: 24
	.asciiz		"Cho Oyu"
	.space	12
	.word	8188
	.asciiz		"Lhotse"
	.space	13
	.word	8516
	.asciiz		"Makalu"
	.space	13
	.word	8485
	.asciiz		"Annapurna"
	.space	10
	.word	8091
	.asciiz		"Nanga Parbat"
	.space	7
	.word	8126
	.asciiz		"K2"
	.space	17
	.word	8611
	.asciiz		"Everest"
	.space	12
	.word	8848
	.asciiz		"Manaslu"
	.space	12
	.word	8163
	.asciiz		"Kangchenjunga"
	.space	6
	.word	8586
	.space	240
	.align	2






# EJERCICIO 1
buscar_montana_mas_alta:
#en en apilado se resta, no se suma. Apilado incorrecto. Faltan registros
	addiu	$sp, $sp, -20 
	sw	$ra, 0($sp)	
	sw	$s0, 4($sp)	
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s3, 16($sp)

	lw	$s1, nmontanas	#$s1 = nmontanas
	blez	$s1, B0_6	
	la	$s0, montanas   # Montana *candidata = &montanas[0];
        li      $s2, 1          # i=1

B0_1:   bge     $s2, $s1, B0_7
        lw      $t0, 20($s0)	#t0 = candidata->altura
        mul     $t1, $s2, 24	###$t1 = i*24, no i*22. Se salta 2 de padding
        la      $t2, montanas 
        addu    $s3, $t1, $t2   # &montanas[i]
        lw      $t1, 20($s3)	#####montanas[i]. altura // altura empieza en +20
        bge     $t0, $t1, B0_2
        move    $a0, $s3	#montanas[i].nombre
        jal     print_string
        la      $a0, str000
        jal     print_string
        move    $a0, $s0	#candidata->nombre
        jal     print_string
        li      $a0, '\n'
        jal     print_character
        move    $s0, $s3
B0_2:   addiu   $s2, $s2, 1	#i++
        j       B0_1
        
B0_6:	li	$s0, 0          # NULL
		
B0_7:	move	$v0, $s0	#return candidata
	
	lw	$ra, 0($sp)	#faltan registros por incluir
	lw	$s0, 4($sp)	# mal desapilado
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	lw	$s3, 16($sp)
	addiu	$sp, $sp, 20 # en el desapilado se suma, no se resta
	jr	$ra