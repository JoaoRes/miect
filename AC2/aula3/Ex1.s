    .data
    .equ SFR_BASE_HI, 0xBF88 # 16 MSbits of SFR area
    .equ TRISE, 0x6100 # TRISE address is 0xBF886100
    .equ PORTE, 0x6110 # PORTE address is 0xBF886110
    .equ LATE, 0x6120 # LATE address is 0xBF886120
    
    .equ TRISB, 0x6040
    .equ PORTB, 0x6050
    .equ LATB, 0x6060
    .text
    .globl main

main:   lui $t0,SFR_BASE_HI # $t0=0xBF880000
        lw $t1,TRISE($t0) #
        andi $t2, $t2, 0xFFFE
        sw $t1,TRISE($t0) # 
while0: lw $t1,PORTB($t0) #
        andi $t2,$t1,1 #
        beq $t2,$0,while0 # while(RB0==0);
        lw $t3,LATB($t0) #
        xori $t3,$t3,2 #
        sw $t3,LATB($t0) # LATB1=!LATB1;
while1: lw $t1,PORTB($t0) #
        andi $t1,$t1,1 #
        bne $t1,$0,while1 # while(RB0==1);
        j while0
