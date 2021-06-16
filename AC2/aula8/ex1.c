#include<detpic32.h>

void configUART(int baud, char parity, unsigned int stopbits)
{
    U1MODEbits.BRGH= 0;
    U1BRG= ((fPBCLK + 8 * baudrate) / (16 * baudrate)) – 1;

    if(parity == 'N') U1MODEbits.PDSEL= 00;
    else(parity == '0') U1MODEbits.PDSEL= 10;
    else(parity =='E') U1MODEbits.PDSEL= 01;

    if(stopbits == 1 ) U1MODEbits.STSEL= 0;
    else(stopbits == 2) U1MODEbits.STSEL= 1;

    U1MODEbits.UTXEN= 1;
    U1MODEbits.URXEN=1; 

    U1MODEbits.ON=1;
}

int main(void)
 {
     configUART(115200, N, 1)
 } 