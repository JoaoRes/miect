#include <detpic32.h>

void delay(int ms){
    for(; ms > 0; ms--)
    {
        resetCoreTimer();
        while(readCoreTimer() < 20000);
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


void _int_(12)	isr_timer3(void)
{
	U1TXREG = 'U';
	IFS0bits.T3IF=0;
}

int main (void)
{
	int Tbit, i, baudrate, mbaud;

	delay(1000); 		// espera um segundo até envio da mensagem inicial	
	T3CONbits.TCKPS=7;	// Prescaler = 256
	PR3=39064; 		// Freq = 2Hz
	TMR3=0;
	T3CONbits.TON=1;
	IPC3bits.T3IP=2;
	IEC0bits.T3IE=1;
	IFS0bits.T3IF=0;

	//baudrate = 4800;
	baudrate = 57600;
	configUART(baudrate , 'N', 1);
	
	while(1)
	{
		EnableInterrupts();
		while(PORTDbits.RD3 == 1);	// espera que deixe de ser 1 para sincronizar
		while(PORTDbits.RD3 == 0);	// espera pela transição de 0 --> 1
		resetCoreTimer();
		while(PORTDbits.RD3 == 1);	//espera pela transição de 1 --> 0
		Tbit = readCoreTimer()*50; 	//ms
		//while(1);			// comentar para fazer medida
		DisableInterrupts();
		printf("Tempo de bit (nseg): %d\n",Tbit);
		mbaud = (int) (1000000000/Tbit);
		printf("Baudrate: %d\n", mbaud);
		putChar('\n');
		getChar();
	}
}


