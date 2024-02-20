#include <stdio.h>
#include <stdlib.h>
#include "busca.h"

int main()
{

    // criar variaveis
    int n, elemento, result, result2; // n = numero de elementos, elemento = o número que tem que ser pesquisado
    int *v;                           // vetor, onde que vai ser armazenado os elementos
    scanf("%d %d", &elemento, &n);
    // aloca vetor
    v = aloca(n);
    // lê a entrada
    le(v, n);
    // busca sequencial
    result = buscaSequencial(v, n, elemento);
    printf("%d ", result);

    // ordena vetor
    ordena(v, n);

    // busca binaria
    result2 = buscaBinaria(v, n, elemento);
    printf("%d ", result2);

    return 0;
}
