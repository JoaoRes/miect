 #include<detpic32.h>

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

void puts(char *str)
{
    while(*str){
        putc(*str);
        *str++;
    }
} 
 
 int main(void)
 {
    configUart(115200,'N',1); //default "pterm" parameters (8 data bits)
    TRISBbits.TRISB6= 0;// config RB6 as output
    while(1)
    {
    while(U1STAbits.TRMT==1);// Wait until TRMT == 1
    LATBbits.LATB6=1; // Set RB6
    resetCoreTimer();
    int tbit;
    puts("");
    tbit= readCoreTimer();
    printf("tempo de bit %d", tbit);
    LATBbits.LATB6=0;// Reset RB6
    }
 }