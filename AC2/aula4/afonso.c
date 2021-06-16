#include <detpic32.h>

 int main(void) {

    TRISB = TRISB & 0x00FF;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    LATDbits.LATD5 = 1;
    LATDbits.LATD6 = 0;
    

    while(1){

        char c = getChar();

        switch (c){
            case 'a':
            case 'A':
                LATB = (LATB & 0x00FF);
                LATBbits.LATB8=1;
                break;
            case 'b':
            case 'B':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB9=1;
                break;
            case 'c':
            case 'C':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB10=1;
                break;
            case 'd':
            case 'D':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB11=1;
                break;
            case 'e':
            case 'E':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB12=1;
                break;
            case 'f':
            case 'F':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB13=1;
                break;
            case 'g':
            case 'G':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB14=1;
                break;
            case '.':
                LATB = (LATB & 0X00FF);
                LATBbits.LATB15=1;
                break;
        }

    }
    return 0;

 }