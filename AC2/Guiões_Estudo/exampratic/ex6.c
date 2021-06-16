#include<detpic32.h>

volatile char counter=0;
volatile char thisDisplay=0;

void delay(unsigned int ms){
    for(;ms>0 ; ms--){
        resetCoreTimer();
        while(readCoreTimer()< 20000);
    }
}

void _int_(12) isr_T3(void){
     if(counter ==99) counter = 0;    
    putChar('\r');
    printInt(counter, 10 | 2 << 16);       
    counter++;
    IFS0bits.T3IF = 0;
}

unsigned char toBCD(unsigned char value) {   
    return ((value / 10) << 4) + (value % 10);
}

void sendToDisplays(unsigned char value){
    unsigned char display7codes[] =  {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
    
    TRISB = TRISB & 0x00FF;
    LATB = LATB & 0x00FF;
    
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;     

    LATDbits.LATD5 = 0;
    LATDbits.LATD6 = 0;
    unsigned char disp_high = value >> 4;
    unsigned char disp_low = value & 0x0F;

    if(thisDisplay==1){
        LATDbits.LATD6 = 1;
        LATDbits.LATD5 = 0;

        LATB = (LATB & 0x00FF) |  display7codes[disp_high] << 8;
    }else{
        LATDbits.LATD6 = 0;
        LATDbits.LATD5 = 1;

        LATB = (LATB & 0x00FF) |  display7codes[disp_low] << 8;        
    }

    thisDisplay = !thisDisplay;
}

int main(void){


    //timer config
    T3CONbits.TCKPS = 5;
    PR3 = 62499;
    TMR3 = 0;
    //timer interrupt config
    IPC3bits.T3IP = 2;
    IEC0bits.T3IE = 1;
    IFS0bits.T3IF = 0;
    
    T3CONbits.TON = 1;

    EnableInterrupts();

    char b; 
    int value;

    while(1){
    char x =inkey();            
        switch(x){
            case '0':
                T3CONbits.TCKPS= 5;
                PR3 = 62499;
                TMR3= 0;
                break;                
            case '1':
                T3CONbits.TCKPS= 4;
                PR3 = 62499;
                TMR3= 0;
                break;
            case '2':
                T3CONbits.TCKPS=4;
                PR3 = 41666;
                TMR3= 0;
                break;
            case '3':
                T3CONbits.TCKPS=3;
                PR3 = 62499;
                TMR3= 0;
                break;
            case '4':
                T3CONbits.TCKPS =3;
                PR3 = 49999;
                TMR3 =0;
                break;
            case '\n':
                printStr(" » ");
                printInt(counter, 10|2<<16);
                b =1;
                value = counter;
                break;
        }
        if(b==1){
            sendToDisplays(toBCD(value));
        }

        delay(20);
    }

    
    
    return 0;
}