#include<detpic32.h>

int main(void){
    TRISB = TRISB & 0x000F;
    TRISE = TRISE & 0xFFF0;

    while(1){
        LATE = PORTB;
        LATE = LATE & 0xFFF0;
        PORTB = PORTB & 0x000F;
    }
}