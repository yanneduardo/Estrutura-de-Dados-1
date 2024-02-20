#ifndef BUSCA_H
#define BUSCA_H
#include <stddef.h>

int *aloca(int n);
void desaloca(int **vetor);
void le(int *vetor, int n);
int buscaSequencial(int *vetor, int n, int elemento);
int buscaBinaria(int *vetor, int n, int elemento);
void ordena(int *vetor, int n);

#endif
