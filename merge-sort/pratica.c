#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main()
{
    int *v, n, c;
    // ler a quantidade de números
    scanf("%d", &n);
    // alocar o vetor
    v = (int *)malloc(n * sizeof(int));
    // ler os valores
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    // ordenar o vetor
    c = sort(v, n);
    // imprimir o numero de vezes que o InsertionSort foi chamado

    printf("%d", c);
    // imprimir os cinco primeiros valores
    for (int i = 0; i < 5; i++)
        printf("%d ", v[i]);
    // liberar o vetor
    free(v);
    return 0;
}