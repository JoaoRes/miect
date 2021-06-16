#include<detpic32.h>

void delay(unsigned int ms){
    for(; ms>0 ;ms--){
        resetCoreTimer();
        while(readCoreTimer()<20000);
    }
}


int main(void){
    int counter = 0;
    char x=0;
    char ms=100;

    while(1){
        x= inkey();
        switch(x){
            case '0':
                ms=100;
                break;
            case '1':
                ms= 50;
                break;

            case '2':
                ms=33;
                break;

            case '3':
                ms=25;
                break;

            case '4':
                ms=20;
                break;

            case '\n':
                printStr(">>");
                printInt(counter, 10|2<<16);
                break;
        }

        delay(ms);
        counter++;
        if(counter ==99) counter = 0;
        putChar('\r');
        printInt(counter, 10|2<<16);
    }
}
