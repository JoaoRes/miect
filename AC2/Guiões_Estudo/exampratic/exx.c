#include <detpic32.h>

static char i = 0;
static char displayFlag = 0;

unsigned char toBcd(unsigned char value) {   
    return ((value / 10) << 4) + (value % 10);
}

void _int_(12) isr_T3(void) {
    if (i >= 100) {
        resetCoreTimer();
        i = 0;
    }
    putChar('\r');
    printInt(i, 10 | 2 << 16);       
    i++;
    IFS0bits.T3IF = 0; 
}

void delay(unsigned int ms) {
    for (; ms > 0; ms--) {
        resetCoreTimer();
        while (readCoreTimer() < 20000);      
    }
}

void send2Displays(unsigned char value) {
    char display7Scodes[] = {0x3F, 0x06, 0x5B, 0X4F, 0x66, 0x6D, 0x7D, 0x07, 
                             0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

    unsigned int dl, dh;

    TRISB = TRISB & 0x00FF;
    LATB = LATB & 0x00FF;
    
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;     

    LATDbits.LATD5 = 0;
    LATDbits.LATD6 = 0;

    dl = value & 0x0F;
    dh = value >> 4;

    if (displayFlag == 0) {
        LATB = (LATB & 0x00FF) | (display7Scodes[dh] << 8);
        LATDbits.LATD5 = 0;
        LATDbits.LATD6 = 1;

    }
    if (displayFlag == 1) {
        LATB = (LATB & 0x00FF) | (display7Scodes[dl] << 8);
        LATDbits.LATD5 = 1;
        LATDbits.LATD6 = 0;
    }
    

    displayFlag = !displayFlag;
}

int main(void) {

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
    
    unsigned int coreT = 0;
    coreT = 0;
    char mod;
    char lastKey = ' ';
    unsigned char currentI = 0;
    while(1) {
        mod = inkey();
        switch (mod) {
        case '0':
            T3CONbits.TCKPS = 5;
            PR3 = 62499;
            lastKey = '0';
            break;
        case '1':
            T3CONbits.TCKPS = 4;
            PR3 = 62499;
            lastKey = '1';
            break;
        case '2':
            T3CONbits.TCKPS = 4;
            PR3 = 41665.6666;
            lastKey = '2';
            break;
        case '3':
            T3CONbits.TCKPS = 3;
            PR3 = 62499;
            lastKey = '3';
        break;
        case '4':
            T3CONbits.TCKPS = 3;
            PR3 = 49999;
            lastKey = '4';
            break;
        case '\n':
            coreT = readCoreTimer();
            // printStr(str);
            // printInt10(coreT);
            // putChar('\n');
            lastKey = '\n';
            currentI = i;
            break;
        }

        if (lastKey == '\n') {
            send2Displays(toBcd(currentI));
        }
        delay(2000);
    }
}