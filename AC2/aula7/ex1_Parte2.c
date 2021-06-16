#include<detpic32.h>

int main(void)
{
    T3CONbits.TCKPS = 3;
    PR3 = 50000;
    TMR3= 0;
    T3CONbits.TON= 1;
    IEC0bits.T3IE = 0;

    OC1CONbits.OCM=6;
    OC1CONbits.OCTSEL=1;
    OC1RS=45000;
    OC1CONbits.ON=1;

    TRISBbits.TRISB4 = 1;
    int clock;

    while(1)
    {
        while(PORTBbits.RB4==0);
        resetCoreTimer();
        while(PORTBbits.RB4==1);
        clock= readCoreTimer()/20000;
        printInt10(clock);
    }
return 0;
}