#include <stdio.h>

int main()
{
    int a[5] = {1,2,3,4,5};
    int *pa;
    pa = a;
    *pa = 27;
    pa[2] = 45;
    *(pa + 3) = 200;

    for(int i = 0; i < sizeof(pa)/sizeof(int*); i++)
    {
        printf("a[%d] = %d ",i, a[i]);
    }
    printf("\n");

    //int a[5] = {0}; inicializa todos a 0
    //Se puede omitir el valor del tamaño del arreglo
    return 0;
}