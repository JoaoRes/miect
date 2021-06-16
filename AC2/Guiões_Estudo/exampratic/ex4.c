#include<detpic32.h>

volatile int thisDisplay=0;

void delay(unsigned int ms){
    for(;ms>0 ; ms--){
        resetCoreTimer();
        while(readCoreTimer()< 20000);
    }
}

unsigned char toBCD(unsigned char value){
    return (((value/10)<<4) +  (value%10));
}

void sendToDisplays(unsigned char value){
    unsigned char display7codes[] =  {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
    unsigned char disp_high = value >> 4;
    unsigned char disp_low = value & 0x0F;
    
    if(thisDisplay==1){
        LATDbits.LATD6 = 1;
        LATDbits.LATD5 = 0;
        
        LATB = (LATB & 0x00FF) | display7codes[disp_high] << 8;
    }else{
        LATDbits.LATD6 = 0;
        LATDbits.LATD5 = 1;

        LATB = (LATB & 0x00FF) | display7codes[disp_low] << 8;        
    }

    thisDisplay = !thisDisplay;        
}


int main(void){
    TRISB = TRISB & 0x00FF;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;

    LATD = LATD & 0x0000;
    LATB = LATB & 0x0000;

    int aux=0;
    
    while(1){
        unsigned char value = inkey();
        unsigned char send;

        if(value == '0'){
            send = 0;
            aux=1;
            
        }else if(value == '1'){
            send = 1;
            aux=1;
            
        }else if(value == '2'){
            send = 2;
            aux=1;
            
        }else if(value == '3'){
            send = 3;
            aux=1;
            
        }else if(value!=0){
            aux=0;
            LATDbits.LATD5 =1;
            LATDbits.LATD6 =1;
            LATB= LATB & 0x00FF | 0x71<<8;
            delay(1000);
            LATDbits.LATD5 =0;
            LATDbits.LATD6 =0;
        }
        
        if(aux==1) sendToDisplays(toBCD(send));
    }
}
