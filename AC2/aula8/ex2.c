#include<detpic32.h>

void delay(int ms){

    for(;ms>0;ms--){
        resetCoreTimer();
        while(readCoreTimer() < 20000 );
    }

}

void configUART(int baud, char parity, unsigned int stopbits)
{
 U1MODEbits.BRGH= 0;
 U1BRG= (int)((PBCLK + 8 * baud) / (16 * baud)) - 1;

    if(parity == 'N') U1MODEbits.PDSEL= 0;
    else if(parity == 'O') U1MODEbits.PDSEL= 2;
    else if(parity =='E') U1MODEbits.PDSEL= 1;

    if(stopbits == 1 ) U1MODEbits.STSEL= 0;
    else if(stopbits == 2) U1MODEbits.STSEL= 1;

 U1STAbits.UTXEN= 1;
 U1STAbits.URXEN=1; 

 U1MODEbits.ON=1;
}

void putc(char byte2send)
{
    while (U1STAbits.UTXBF==1);
    U1TXREG = byte2send;
}

int main(void)
 {
     configUART(115200, 'N' , 1);
     while(1)
     {
         putc('+');
         delay(1000);
     }
 } 