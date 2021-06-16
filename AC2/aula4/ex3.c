#include <detpic32.h>

void delay(int ms)
{
    for(; ms > 0; ms--)
    {
        resetCoreTimer();
        while(readCoreTimer() < 20000);
    }
}

int main (void)
{
    TRISB = (TRISB & 0X00FF);

    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;

    LATB =  (LATB & 0x00FF);

    LATDbits.LATD5= 1;
    LATDbits.LATD6= 0;

    while(1)
    {
        char in = getChar();

        switch (in)
        {
            case 'a':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB8 = 1;
                break;
            case 'b':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB9 = 1;
                break;
            case 'c':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB10 = 1;
                break;
            case 'd':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB11 = 1;
                break;
            case 'e':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB12 = 1;
                break;
            case 'f':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB13 = 1;
                break;
            case 'g':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB14 = 1;
                break;
            case '.':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB15 = 1;
                break;
        }

        delay(250);
    }

    return 0;

}