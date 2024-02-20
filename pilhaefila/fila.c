#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

Fila* FilaCria() {
    Fila *fila = (Fila*) malloc (sizeof(Fila));
    fila->ini = 0;
    fila->fim = 0; 
    return fila;
}

Fila* FilaDestroi(Fila* pFila) {
    free(pFila);
    pFila = NULL;
    return pFila;
}

bool FilaEhVazia(Fila* pFila) {
    return pFila->fim - pFila->ini == 0;
}

bool FilaEhCheia(Fila* pFila) {
     return pFila->fim == MAX_TAM;
}

bool FilaEnfileira(Fila* pFila, Item item) {
    if(FilaEhCheia(pFila)){
        return false;
    }
    pFila->itens[pFila->fim] = item;
    pFila->fim++;
    return true;
}

bool FilaDesenfileira(Fila* pFila, Item* pItem) {
    if(FilaEhVazia(pFila)){
        return false;
    }

    *pItem = pFila->itens[pFila->ini];
    pFila->ini++;
    return true;
    
}

int FilaTamanho(Fila* pFila) {
    if(FilaEhVazia(pFila))
        return 0;
    return pFila->fim - pFila->ini ;
    
}

void FilaImprime(Fila* pFila) {
    printf("Fila: [");
        for (int i=0;i<FilaTamanho(pFila);i++)
            printf("(%d) ", pFila->itens[(pFila->ini + i) % MAX_TAM].chave);
    printf("]\n");
}
