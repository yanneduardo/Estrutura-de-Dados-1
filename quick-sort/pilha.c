#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 1000

struct pilha
{
    int p[MAX_TAM];
    int r[MAX_TAM];
    int tam;
};

Pilha *PilhaCria()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->tam = 0;
    return pilha;
}

Pilha *PilhaDestroi(Pilha *pPilha)
{
    free(pPilha);
    pPilha = NULL;
    return pPilha;
}

bool PilhaEhVazia(Pilha *pPilha)
{
    return pPilha->tam == 0;
}

bool PilhaPush(Pilha *pPilha, int p, int r)
{
    if (pPilha->tam == MAX_TAM)
        return false;
    pPilha->p[pPilha->tam] = p;
    pPilha->r[pPilha->tam++] = r;

    return true;
}

bool PilhaPop(Pilha *pPilha, int *pP, int *pR)
{
    if (PilhaEhVazia(pPilha))
        return false;
    *pP = pPilha->p[--pPilha->tam];
    *pR = pPilha->r[pPilha->tam];
    return true;
}

int PilhaTamanho(Pilha *pPilha)
{
    return pPilha->tam;
}
