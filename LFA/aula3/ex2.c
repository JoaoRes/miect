#include <stdio.h>
#include <assert.h>

int Comp=0;

int oper2(int b[], int n)
{
    assert(n>1);

    int nElemMen=0;
    int maior=0;
    int index=0;

    for(int i=1 ; i<n ; i++)
    {

        for(int j= 0 ; j < i ; j++)
        {
            if(b[j]<b[i])
            {
                nElemMen++;
            }
            Comp++;
        }
        if(nElemMen>maior)
        {
            maior=nElemMen;
            index=i;
        }
        nElemMen=0;
    }

    if(maior==0)
    {
        return -1;
    }
    else
    {
        return index;
    }

}

int main(void)
{
    //int b[10]= {1,  9,  2,  8,  3,  4,  5,  3,  7,  2};
    //int b[10]= {1,  7,  4,  6,  5,  2,  3,  2,  1,  0};
    //int b[10]= {2,  2,  2,  2,  2,  2,  2,  2,  2,  2};
    //int b[5]= {1,  9,  2,  8,  3};
    int b[20]={1,  9,  2,  8,  3,  4,  5,  3,  7,  2, 1,  7,  4,  6,  5,  2,  3,  2,  1,  0};

            int imm = oper2(b, 20);

    printf("b[%d]= %d , Nº comparações: %d\n" , imm, b[imm], Comp);

    return 0;

}