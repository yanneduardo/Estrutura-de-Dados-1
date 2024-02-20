#include <stdio.h>

void cubeporeferencia(int *nPtr);

int main(){
    int n=5;

    printf("\n o valor original do número é: %d\n",n);
    
    cubeporeferencia(&n);

    printf( "O novo valor é, %d\n", n);

    printf("O valor original é: %d", n);

    return 0;
}

void cubeporeferencia (int *nPtr){

    *nPtr =  *nPtr * *nPtr * *nPtr;
}