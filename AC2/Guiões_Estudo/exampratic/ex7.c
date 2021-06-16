#include<detpic32.h>

void delay(unsigned int ms){
    for(;ms>0;ms--){
        resetCoreTimer();
        while(readCoreTimer()<20000);
    }
}

int main(void){
    TRISB = TRISB | 0x000F;

    TRISBbits.TRISB4 =1;
    AD1PCFGbits.PCFG4 =0;
    AD1CON1bits.SSRC =7;

    AD1CON1bits.CLRASAM =1;

    AD1CON3bits.SAMC =16;
    AD1CON2bits.SMPI = 4-1;

    AD1CHSbits.CH0SA = 4;

    AD1CON1bits.ON = 1;

    int RB3, RB2, RB1, RB0;

    while(1){
        AD1CON1bits.ASAM=1;

        while(IFS1bits.AD1IF == 0);

        RB0 = PORTBbits.RB0;
        RB1 = PORTBbits.RB1;
        RB2 = PORTBbits.RB2;
        RB3 = PORTBbits.RB3;

        printStr("RB0: ");
        printInt10(RB0);
        printStr("\tRB1: ");
        printInt10(RB1);
        printStr("\tRB2: ");
        printInt10(RB2);
        printStr("\tRB3: ");
        printInt10(RB3);
        printStr("\n"); 

        int *p = (int *) (&ADC1BUF0);
        int i=0;
        int sum=0;
        for(i=0 ; i<16 ; i++){
            sum+=p[i*4];
        }
        int value;
        value = sum/4;

        int freq;
        freq = 1 +(value/255);
        printInt10(freq);
        delay(1000/freq);
    }
}