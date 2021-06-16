#include<detpic32.h>


int main(void)
 {
    int display7codes[] =  {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
    TRISB = TRISB | 0x000F; // configure RB0 to RB3 as inputs
    LATDbits.LATD6 = 0;                             // display high active 
    LATDbits.LATD5 = 1;                             // display low inactive // Select display low
    TRISB = TRISB & 0x00FF;                         // configure RB8-RB14 as outputs
    TRISD = TRISD & 0xFF9F;     // configure RB8 to RB14 and RD5 to RD6 as outputs
    
    while(1)
    {
    int select = PORTB & 0x000F;// read dip-switch
    LATB = (LATB & 0x00FF) | (display7codes[select]<<8); // send to display // convert to 7 segments code
    }
 return 0;
 }  