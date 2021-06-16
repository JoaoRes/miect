	.data
	.text
	.globl main
main: 
while:	
while1:	li $v0, 1
	syscall
	#move $a1, $v0
	#li $a0 , 'A'
	#li $v0, 3
	#syscall 
	#move $v0, $a1
	beq $v0, 0, while1
if:	
	beq $v0, '\n', endw
	move $a0, $v0
	li $v0, 3
	syscall
	j while
endw:
	ori $v0, $0, 0
	jr $ra 
	
