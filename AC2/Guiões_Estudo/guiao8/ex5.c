#include<detpic32.h>

int configUART(int baudrate, char parity, int stb){
    U1MODEbits.BRGH =0 ;
    U1BRG= ((PBCLK+8*baudrate)/(16*baudrate))-1;

    if(parity == 'N') U1MODEbits.PDSEL = 00;
    if(parity == 'O') U1MODEbits.PDSEL =10;
    if(parity == 'E') U1MODEbits.PDSEL =01;

    if(stb == 1) U1MODEbits.STSEL = 0;
    if(stb == 2) U1MODEbits.STSEL =1;

    U1STAbits.UTXEN =1 ;
    U1STAbits.URXEN =1;

    U1MODEbits.ON=1;
}

int main(void){
    configUART(600, 'N', 1);
}