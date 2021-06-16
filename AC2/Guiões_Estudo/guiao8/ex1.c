#include<detpic32.h>

int main (void){
    U1MODEbits.BRGH=0;
    U1BRG = ((20E6 + 8 * 115200)/(16*115200))-1;

    U1MODEbits.PDSEL =00;
    U1MODEbits.STSEL =0;

    U1STAbits.UTXEN =1;
    U1STAbits.URXEN = 1;
    
    U1MODEbits.ON = 1;
}