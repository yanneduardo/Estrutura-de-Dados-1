#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

int* alocaVetor(int n){
    int *vetor = malloc (n * sizeof(int));
    return vetor;
}

int* desalocaVetor(int* v){
    free(v);
    v = NULL;
    return v;
}

void ordenacao(int* v, int n, int* movimentos){
    int j;
    for (int i= 1; i < n; i++){
        int aux = v[i];
        j = i-1;
        while (j>=0 && aux < v[j])
        {
            v[j+1]=v[j];
            j--;
            (*movimentos)++;
        
        }

        v[j+1] = aux;

    }
}
