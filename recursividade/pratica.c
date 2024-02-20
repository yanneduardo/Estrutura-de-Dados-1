#include "josephus.h"
#include<stdio.h>

int main()
{
    int n, k, resultado;

    scanf("%d %d",&n, &k);
    resultado = josephus(n, k);
    printf("%d\n", resultado);

    return 0;
}
