#include<detpic32.h>
#include<string.h>

int tbit;

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

void putstring(char* test)
{
    int i;
    int size = strlen(test);
    for(i=0 ; i < size ; i++)
    {
        putc(test[i]);
    }
}

int main(void)
{
    configUART(115200,'N',1); //default "pterm" parameters (8 data bits)
    // config RB6 as output
    TRISBbits.TRISB6=0;
    LATB = (LATB && 0x0040);

    while(1)
    {
        //while(U1STAbits.TRMT==0);// Wait until TRMT == 1
        LATBbits.LATB6=1;// Set RB6
        resetCoreTimer();
        puts("123456789");
        LATBbits.LATB6=0;// Reset RB6
        tbit = readCoreTimer();
        printf("Tempo de bit (nseg): %d\n",tbit);
        getChar();
    }
} 