#include <stdio.h>
#include <assert.h>
int Comp=0;


int oper(int a[], int n)
{
    assert(n>1);
    int Nelem1=0;

    for(int i=1 ; i<n ; i++)
    {
        if(a[i] != a[i-1])
        {
            Nelem1++;
        }
        Comp++;
    }

    return Nelem1;
}

int main(void)
{
    int nELem=0;

    //int array[10]={3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    //int array[10]={4, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    //int array[10]={4, 5, 3, 3, 3, 3, 3, 3, 3, 3};
    //int array[10]={4, 5, 1, 3, 3, 3, 3, 3, 3, 3};
    //int array[10]={4, 5, 1, 2, 3, 3, 3, 3, 3, 3};
    //int array[10]={4, 5, 1, 2, 6, 3, 3, 3, 3, 3};
    //int array[10]={4, 5, 1, 2, 6, 8, 3, 3, 3, 3};
    //int array[10]={4, 5, 1, 2, 6, 8, 7, 3, 3, 3};
    //int array[10]={4, 5, 1, 2, 6, 8, 7, 9, 3, 3};
    int array[10]={4, 5, 1, 2, 6, 8, 7, 9, 3, 0};

    nELem= oper(array, 10);

    printf("Nº de elementos dif: %d , Nº Operaçoes: %d\n", nELem , Comp);
}

