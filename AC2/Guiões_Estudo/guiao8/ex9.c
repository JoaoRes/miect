 #include<detpic32.h>
int x;
 int configUart(int baudrate, char parity, int stb){
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

void putc(char byte2send)
{
    while (U1STAbits.UTXBF==1);
    U1TXREG = byte2send;
}

char getc(void)
{
    if(U1STAbits.OERR==1) U1STAbits.OERR=0;// If OERR == 1 then reset OERR
    while(U1STAbits.URXDA==0);// Wait while URXDA == 0
    if(U1STAbits.FERR==1 || U1STAbits.PERR==1){// If FERR or PERR then
    int x= U1RXREG;// read UxRXREG (to discard the character) and return 0
    return 0;
    }
    else return U1RXREG;// Return U1RXREG
}

int main(void)
{
    configUart(115200,'N',1); // default "pterm" parameters
    while(1)
    {
    putc( getc() );
    }
} 