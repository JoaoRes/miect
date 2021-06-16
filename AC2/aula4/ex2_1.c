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
   TRISE = TRISE & 0XFFF0; //configure as output
   LATE = LATE & 0XFFF0;

   int cons=0;

   while(1)
   {
       LATE = (LATE = LATE & 0XFFF0) | cons;
       cons++;
       cons = cons & 0X000F;
       delay(500);
    }

return 1;
}