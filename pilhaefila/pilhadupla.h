#ifndef PILHA_DUPLA_H
#define PILHA_DUPLA_H

#include <stdbool.h>
#include "item.h"

typedef struct {
    Item itens[MAX_TAM];
    int tamP1;
    int tamP2;
} PilhaDupla;

PilhaDupla* PilhaDuplaCria();
PilhaDupla* PilhaDuplaDestroi(PilhaDupla*);
bool PilhaEhVazia(PilhaDupla*, int);
bool PilhaEhCheia(PilhaDupla*, int);
bool PilhaPush(PilhaDupla*, int, Item);
bool PilhaPop(PilhaDupla*, int, Item*);
int PilhaTamanho(PilhaDupla*, int);
void PilhaImprime(PilhaDupla*, int);

#endif // !PILHA_DUPLA_H