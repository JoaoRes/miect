	.data
	.text
	.globl main
main:	
while:	ori $v0 , $0, 0x0002
	syscall
	beq $v0, '\n', endw
	move $a0, $v0
	ori $v0, $0, 0x0003
	syscall
	j while
endw:
	ori $v0, $0, 0
	jr $ra 
	
	