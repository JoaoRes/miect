#include <detpic32.h>

#define numSamples 16;

volatile char freq;
static char displayFlag = 0;

void configUART(unsigned int baudrate, unsigned char parity, unsigned int stop){
    U1BRG =((PBCLK+8*baudrate)/(16*baudrate))-1;

    U1MODEbits.BRGH = 0;
    
    if(parity == 'N') U1MODEbits.PDSEL = 00;
    if(parity == 'O') U1MODEbits.PDSEL =10;
    if(parity == 'E') U1MODEbits.PDSEL= 01;

    if(stop =='1') U1MODEbits.STSEL = 0;
    if(stop =='2') U1MODEbits.STSEL = 1;

    U1STAbits.UTXEN = 1;
    U1STAbits.URXEN = 1;

    U1MODEbits.ON = 1;

}

void send2displays(unsigned char value) {
    char display7Scodes[] = {0x3F, 0x06, 0x5B, 0X4F, 0x66, 0xBF, 0x86, 0xDB, 0XCF, 0xE6};

    unsigned int dl, dh;

    TRISB = TRISB & 0x00FF;
    LATB = LATB & 0x00FF;

    dl = value & 0x0F;
    dh = value >> 4;

    if(displayFlag == 0) {
        LATB = (LATB & 0x00FF) | display7Scodes[dl+4] << 8;
        LATDbits.LATD5 = 0;
        LATDbits.LATD6 = 1;
    } else {
        LATB = (LATB & 0x00FF) | display7Scodes[dh] << 8;
        LATDbits.LATD5 = 1;
        LATDbits.LATD6 = 0;
    }

    displayFlag = !displayFlag;
}

void _int_(8) isr_T2(void) {
    
    send2displays(freq);

    IFS0bits.T2IF = 0;
}

void _int_(27) isr_adc(void) {
    int VAL_AD = 0;

    int *p = (int*) (&ADC1BUF0);    
    int i;
    for(i = 0; i < 16; i++) {
        VAL_AD += p[i*4];
    } 
    VAL_AD = VAL_AD / numSamples;

    freq = 1 + (VAL_AD/255);

    AD1CON1bits.ASAM = 1;

    IFS1bits.AD1IF = 0; // Reset AD1IF flag
}

void delay(unsigned int ms) {
    for(; ms > 0; ms--) {
        resetCoreTimer();
        while(readCoreTimer() < 20000);
    }
}

void putc(char byte2send){
    while(U1STAbits.UTXBF ==1);
    U1TXREG = byte2send;
}

void puts(char* str){
    while(*str){
        putc(*str);
        *str++;
    }
}


void _int_(24) _isr_uart1(void){
    if(IFS0bits.U1TXIF==1){   
        puts("RB0: ");
        if(PORTBbits.RB0 == 1) {
            putc('1');
        } else {
            putc('0');
        }
        puts(", RB1: ");
        if(PORTBbits.RB1 == 1) {
            putc('1');
        } else {
            putc('0');
        }
        puts(", RB2: ");
        if(PORTBbits.RB2 == 1) {
            putc('1');
        } else {
            putc('0');
        }
        puts(", RB3: ");
        if(PORTBbits.RB3 == 1) {
            putc('1');
        } else {
            putc('0');
        }
        putc('\n');
    }
    IFS0bits.U1TXIF =0;
} 

int main(void) {
    configUART(9600, 'N', 1);

    TRISB = TRISB & 0x00FF;
    PORTB = PORTB & 0xFFF0;

    TRISD = TRISD & 0xFF9F;

    LATDbits.LATD5 = 0;
    LATDbits.LATD6 = 0;

    //digital output disconnected
    TRISBbits.TRISB4 = 1;
    //configured RB4 as analog input (AN4)
    AD1PCFGbits.PCFG4 = 0;
    AD1CON1bits.SSRC = 7;

    AD1CON1bits.CLRASAM = 1;

    AD1CON3bits.SAMC = 16;
    AD1CON2bits.SMPI = 15;

    AD1CHSbits.CH0SA = 4;

    AD1CON1bits.ON = 1;
    
    //configure interrupt priority
    IPC6bits.AD1IP = 2;
    //enable a/d interrupts
    IEC1bits.AD1IE = 1;
    //reset da flag
    IFS1bits.AD1IF = 0;

    EnableInterrupts();
    //start conversion
    
    AD1CON1bits.ASAM = 1;
    
    //TIMER CONFIG
    T2CONbits.TCKPS = 2;
    PR2 = 49999;  
    TMR2 = 0;
    T2CONbits.TON = 1;

    IPC2bits.T2IP = 3;
    IEC0bits.T2IE = 1;
    IFS0bits.T2IF = 0;
    
    unsigned int d;
    while(1) {

        d = (1/freq)*1000;

        delay(d);
    }

}
