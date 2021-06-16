#include<detpic32.h>

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

void _int_(24) isr_uart1(void)
 {
 putc(U1RXREG);
 // Clear UART1 rx interrupt flag
 IFS0bits.U1RXIF=0;
 } 

int main(void)
{
    configUART(115200,'N',1); // default "pterm" parameters
    // with RX interrupt enabled
    U1STAbits.U1RXISEL=00;
    U1MODEbits.U1RXIE=1;
    IPC3bits.T3IP=2; //priority(range[1..6])
    IEC0bits.T3IE=1; //Enalbe timer T2
    IFS0bits.T3IF=0; //Reset timer t2 interrupt flag
    EnableInterrupts();
    while(1);
} 

