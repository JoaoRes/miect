#include <detpic32.h>

void delay(int ms)
{
    for(; ms > 0; ms--)
    {
        resetCoreTimer();
        while(readCoreTimer() < 20000);
    }
}

int main(void)
{

    LATE = LATE & 0XFFF0;

    TRISEbits.TRISE0 = 0; // RD0 configured as output
    TRISEbits.TRISE1 = 0;
    TRISEbits.TRISE2 = 0;
    TRISEbits.TRISE3 = 0;

    int cons=0;

    while(1)
    {
        LATE = (LATE & 0xFFF0) | cons;
        cons++;
        cons= cons & 0x000F;
        delay(500); // half period = 0.5s
    }
    return 1;
}
