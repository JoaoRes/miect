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
    TRISB = TRISB & 0x00FF;
    LATB = LATB & 0X00FF;

    TRISD = TRISD & 0xFFCF;
    LATDbits.LATD5 = 1;
    LATDbits.LATD6= 1;

    while(1)
    {
        char in = getChar();

        switch(in)
        {
            case 'a':
              LATB = LATB & 0X00FF; 
              LATBbits.LATB8 =1 ;
              break;  
            case 'b':
              LATB = LATB & 0X00FF; 
              LATBbits.LATB9 =1 ;
              break; 
            case 'c':
              LATB = LATB & 0X00FF; 
              LATBbits.LATB10 =1 ;
              break; 
            case 'd':
              LATB = LATB & 0X00FF; 
              LATBbits.LATB11 =1 ;
              break;
            case 'e':
              LATB = LATB & 0X00FF; 
              LATBbits.LATB12 =1 ;
              break;
            case 'f':
              LATB = LATB & 0X00FF; 
              LATBbits.LATB13 =1 ;
              break; 
            case 'g':
              LATB = LATB & 0X00FF; 
              LATBbits.LATB14 =1 ;
              break;     
        }
    }
return 0;
}