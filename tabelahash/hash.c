#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicia(Hash *hash, int m, int p)
{
    hash->pesos = (int *)malloc(p * sizeof(int));
    hash->chaves = (Chave *)malloc(m * sizeof(Chave));
    hash->p = p;
    hash->m = m;
    for (int i = 0; i < m; i++)
    {
        strcpy(hash->chaves[i], VAZIO);
    }
}

void libera(Hash *hash)
{
    free(hash->pesos);
    free(hash->chaves);
}

int H(Hash *hash, Chave chave)
{
    unsigned int soma = 0;
    int i, tamDaString = strlen(chave);

    for (i = 0; i < tamDaString; i++)
    {
        soma += (unsigned int)chave[i] * hash->pesos[i % hash->p];
    }
    return (soma % hash->m);
}
int pesquisa(Hash *hash, Chave chave)
{
    int j = 0;
    int ini = H(hash, chave);

    while (strcmp(hash->chaves[(ini + j) % hash->m], VAZIO) != 0 && strcmp(hash->chaves[(ini + j) % hash->m], chave) != 0 && j < hash->m)
    {
        j++;
    }

    if (strcmp(hash->chaves[(ini + j) % hash->m], chave) == 0)
    {
        return (ini + j) % hash->m;
    }
    return -1;
}
int insere(Hash *hash, Chave chave)
{
    if (pesquisa(hash, chave) >= 0)
    {
        return -1;
    }

    int j = 0;
    int ini = H(hash, chave);
    while (strcmp(hash->chaves[(ini + j) % hash->m], VAZIO) != 0 && j < hash->m)
    {
        j++;
    }
    if (j < hash->m)
    {
        strcpy(hash->chaves[(ini + j) % hash->m], chave);
        return (ini + j) % hash->m;
    }

    return -1;
}
