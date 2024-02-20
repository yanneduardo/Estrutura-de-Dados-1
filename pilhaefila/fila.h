#ifndef FILA_H
#define FILA_H

#include <stdbool.h>
#include "item.h"

typedef struct fila {
    Item itens[MAX_TAM];
    int ini;
    int fim;
} Fila;

Fila* FilaCria();
Fila* FilaDestroi(Fila*);
bool FilaEhVazia(Fila*);
bool FilaEnfileira(Fila*, Item);
bool FilaDesenfileira(Fila*, Item*);
int FilaTamanho(Fila*);
void FilaImprime(Fila*);

#endif // FILA_H