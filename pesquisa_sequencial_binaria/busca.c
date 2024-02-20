#include "busca.h"

#include <stdio.h>
#include <stdlib.h>

int *aloca(int n)
{
    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL)
    {
        printf("não foi possível alocar o vetor");
    }
    return vetor;
}

void desaloca(int **vetor)
{
    free(*vetor);
}

void le(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

int buscaSequencial(int *vetor, int n, int elemento)
{
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        if (vetor[i] == elemento)
        {
            return i;
        }
    }
    // retorna -1 caso o número não for encontrado
    return -1;
}

int buscaBinaria(int *vetor, int n, int elemento)
{
    int i, dir, esq;
    if (n == 0)
    {
        return -1;
    }
    esq = 0;
    dir = n - 1;
    do
    {
        i = (esq + dir) / 2;
        if (elemento > vetor[i])
        {
            esq = i + 1;
        }
        else
        {
            dir = i - 1;
        }
    } while (elemento != vetor[i] && esq <= dir);
    if (elemento == vetor[i])
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void ordena(int *vetor, int n)
{
    int h, j, aux;
    for (h = 1; h < n; h++)
    {
        h = 3 * h + 1;
    }
    do
    {
        h = (h - 1) / 3;
        for (int i = h; i < n; i++)
        {
            aux = vetor[i];
            j = i;
            while (vetor[j - h] > aux)
            {
                vetor[j] = vetor[j - h];
                j = j - h;
                if (j < h)
                {
                    break;
                }
            }
            vetor[j] = aux;
        }
    } while (h != 1);
}
