#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct pilha Pilha;

Pilha *PilhaCria();
Pilha *PilhaDestroi(Pilha *);
bool PilhaEhVazia(Pilha *);
bool PilhaPush(Pilha *, int, int);
bool PilhaPop(Pilha *, int *, int *);
int PilhaTamanho(Pilha *);

#endif // PILHA_H