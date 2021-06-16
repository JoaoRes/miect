#include <detpic32.h>

void delay(int ms)
{
    for(; ms > 0; ms--)
    {
        resetCoreTimer();
        while(readCoreTimer() < 20000);
    }
}

int charToBin(char a)
{
    switch (a)
    {
        case '0':
            return 0x7700;
            break;
        case '1':
            return 0x7C00;
            break;

        case '2':
            return 0x3900;
            break;

        case '3':
            return 0x5E00;
            break;

        case '4':
            return 0x7900;
            break;

        case '5':
            return 0x7100;
            break;

        case '6':
            return 0x7D00;
            break;


        default: return 0x0000;
            break;
    }
}

int main(void)
{
    unsigned char segment;
    LATDbits.LATD6 = 1; // display high active
    LATDbits.LATD5 = 0; // display low inactive

    // configure RB8-RB14 as outputs
    // configure RD5-RD6 as outputs

    TRISBbits.TRISB8 = 0; //RB8 configured as output
    TRISBbits.TRISB9 = 0;
    TRISBbits.TRISB10= 0;
    TRISBbits.TRISB11= 0;
    TRISBbits.TRISB12= 0;
    TRISBbits.TRISB13= 0;
    TRISBbits.TRISB14= 0;
    TRISBbits.TRISB15= 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;

    LATB =  (LATB & 0x00FF);

    LATDbits.LATD5= 1;
    LATDbits.LATD6= 1;

    while(1)
    {
        LATDbits.LATD6 = !LATDbits.LATD6; //
        LATDbits.LATD5 = !LATDbits.LATD5; // toggle display selection
        segment = 1;
        int i;
        for(i=0; i < 7; i++)
        {
            // send "segment" value to display
            // wait 0.5 second
            switch (segment)
            {
                case '0':
                    LATB = (LATB & 0X00FF);
                    LATBbits.LATB8 = 1;
                    break;
                case '1':
                    LATB = (LATB & 0X00FF);
                    LATBbits.LATB9 = 1;
                    break;
                case '2':
                    LATB = (LATB & 0X00FF);
                    LATBbits.LATB10 = 1;
                    break;
                case '3':
                    LATB = (LATB & 0X00FF);
                    LATBbits.LATB11 = 1;
                    break;
                case '4':
                    LATB = (LATB & 0X00FF);
                    LATBbits.LATB12 = 1;
                    break;
                case '5':
                    LATB = (LATB & 0X00FF);
                    LATBbits.LATB13 = 1;
                    break;
                case '6':
                    LATB = (LATB & 0X00FF);
                    LATBbits.LATB14 = 1;
                    break;
                case '7':
                    LATB = (LATB & 0X00FF);
                    LATBbits.LATB15 = 1;
                    break;
            }
            delay(250); //0.5s period
            segment = segment << 1;
        }
    }
    return 0;
}

