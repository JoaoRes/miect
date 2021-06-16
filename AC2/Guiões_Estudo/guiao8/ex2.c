#include<detpic32.h>

void delay(int ms)
{
    for(; ms > 0; ms--)
    {
        resetCoreTimer();
        while(readCoreTimer() < 20000);
    }
}

void putc(char byte2send)
{
    while(U1STAbits.UTXBF ==1);// wait while UTXBF == 1
    U1TXREG = byte2send;// Copy byte2send to the UxTXREG register
}

int main (void){
    U1MODEbits.BRGH=0;
    U1BRG = ((20E6 + 8 * 115200)/(16*115200))-1;

    U1MODEbits.PDSEL =00;
    U1MODEbits.STSEL =0;

    U1STAbits.UTXEN =1;
    U1STAbits.URXEN = 1;
    
    U1MODEbits.ON = 1;

    // Configure UART1 (115200, N, 8, 1)
    while(1)
    {
        putc('-');
        delay(500);// wait 1 s
    }
}