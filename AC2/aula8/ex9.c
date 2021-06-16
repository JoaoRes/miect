#include<detpic32.h>
#include<string.h>
char buff;

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

char getc(void)
 {
    if(U1STAbits.OERR==1) U1STAbits.OERR=0; // If OERR == 1 then reset OERR
    while(U1STAbits.URXDA==0);// Wait while URXDA == 0
    if(U1STAbits.FERR==1 || U1STAbits.PERR==1)// If FERR or PERR then
    {
        buff=U1RXREG;
        return 0;    // read UxRXREG (to discard the character) and return 0        
    }
    else return (U1RXREG); // else Return U1RXREG
 }

void putc(char byte2send)
{
    while (U1STAbits.UTXBF==1);
    U1TXREG = byte2send;
}
 
int main(void)
{
   configUART(115200,'N',1); // default "pterm" parameters
   while(1)
   {
   putc( getc() );
   }
} 

