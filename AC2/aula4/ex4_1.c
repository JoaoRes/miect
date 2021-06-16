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
    
    unsigned char segment;
    TRISB = TRISB & 0x00FF;
    LATB = LATB & 0X00FF;

    TRISD = TRISD & 0xFFCF;
    LATDbits.LATD5 = 0;
    LATDbits.LATD6= 1;

    while(1)
    {
        
        LATDbits.LATD6 = !LATDbits.LATD6; //
        LATDbits.LATD5 = !LATDbits.LATD5; // toggle display selection
        segment = 1;
        int i;

        for(i=0; i < 7; i++)
        {
            switch(segment)// send "segment" value to display
            {  
                case 0:
                    LATB = LATB & 0X00FF; 
                    LATBbits.LATB8 =1 ;
                    break;  
                case 1:
                    LATB = LATB & 0X00FF; 
                    LATBbits.LATB9 =1 ;
                    break; 
                case 2:
                    LATB = LATB & 0X00FF; 
                    LATBbits.LATB10 =1 ;
                    break; 
                case 3:
                    LATB = LATB & 0X00FF; 
                    LATBbits.LATB11 =1 ;
                    break;
                case 4:
                    LATB = LATB & 0X00FF; 
                    LATBbits.LATB12 =1 ;
                    break;
                case 5:
                    LATB = LATB & 0X00FF; 
                    LATBbits.LATB13 =1 ;
                    break; 
                case 6:
                    LATB = LATB & 0X00FF; 
                    LATBbits.LATB14 =1 ;
                    break; 
            }
            delay(250);// wait 0.5 second
            segment = segment << 1;
        }
    }
 return 0; 
}    