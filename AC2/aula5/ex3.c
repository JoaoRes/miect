#include<detpic32.h>

int main(void)
{
    TRISBbits.TRISB4 = 1; //RB4 dig output disconnected
    AD1PCFGbits.PCFG4 = 0; // RB4 configured as analog input
    AD1CON1bits.SSRC = 7; //conversion trigger selection bits

    AD1CON1bits.CLRASAM = 1; //stop conversion if interrupt generated

    AD1CON3bits.SAMC = 16; //sample time is 16
    AD1CON2bits.SMPI= 3; // interrupt generetad after 1 sample

    AD1CHSbits.CH0SA = 4; // desired input

    AD1CON1bits.ON = 1; //Enable A/D converter

    while(1)
    {
        AD1CON1bits.ASAM = 1; //start conversion

        while(IFS1bits.AD1IF==0); //wait while conversion not done
        int i;
        int *p= (int *) (&ADC1BUF0);
        for(i=0; i<16; i++)
        {
            printInt(p[i*4], 16 | 4 << 16);
            printf(" ");
        }
        printf("\n");

        IFS1bits.AD1IF = 0; //reset AD1IF
    }

    return 0;
}