#include<detpic32.h>

int main(void){
    TRISE = TRISE & 0xFFF0;
    
    while(1){
        char x = getChar();
        if(x == '0'){
            LATE = LATE & 0xFFF0;
            LATEbits.LATE0 = 1;
            
        }else if(x == '1'){
            LATE = LATE & 0xFFF0;
            LATEbits.LATE1 = 1;
            
        }else if(x == '2'){
            LATE = LATE & 0xFFF0;
            LATEbits.LATE2 = 1;
            
        }else if(x == '3'){
            LATE = LATE & 0xFFF0;
            LATEbits.LATE3 = 1;
            
        }else{
            LATE = LATE & 0xFFF0;
            LATE = LATE | 0x000F;
        }
    }
}

