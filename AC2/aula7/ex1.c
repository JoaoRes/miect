#include<detpic32.h>

int main(void){
    // Configure Timer T3 (2 Hz with interrupts disabled)
    T3CONbits.TCKPS = 7;
    PR3 = 39062,5;
    TMR3 = 0;
    T3CONbits.TON = 1;
    IEC0bits.T3IE = 0; 
    int i=0;
    while(1) {
    // Wait until T3IF = 1
    // Reset T3IF
    while(IFS0bits.T3IF ==0);
    IFS0bits.T3IF =0;
    printInt10(i);
    printStr("\n");
    i++;
    if(i>120) i=0;
    }
return 0;    
}