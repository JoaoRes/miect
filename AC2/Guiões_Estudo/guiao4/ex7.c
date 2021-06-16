#include<detpic32.h>

void delay(int ms){
 for(; ms > 0; ms--){
 resetCoreTimer();
 while(readCoreTimer() < 20000);
 }
}

int main(void)
{
    int display7codes[] =  {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
    LATDbits.LATD6 = 1;                             // display high active
    LATDbits.LATD5 = 0;                             // display low inactive
    TRISB = TRISB & 0x00FF;                         // configure RB8-RB14 as outputs
    TRISD = TRISD & 0xFF9F;                         // configure RD5-RD6 as outputs
    while(1)
    {
        LATDbits.LATD6 = !LATDbits.LATD6; //
        LATDbits.LATD5 = !LATDbits.LATD5; // toggle display selection
        int i;
        for(i=0; i < 17; i++)
        {
            LATB = (LATB & 0x00FF) | (display7codes[i]<<8); // send "segment" value to display
            delay(500); // wait 0.5 second
        }
    }
    return 0;
 }