#include "sort.h"
#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paciente
{
    char nome[51];
    int idade;
    int estado_de_saude;
};

int partition(Paciente *, int, int);
void troca(Paciente *, Paciente *);

void alocarPacientes(Upa *upa, int n)
{
    upa->pacientes = (Paciente *)malloc(n * sizeof(Paciente));

    if (upa->pacientes == NULL)
    {
        printf("Erro ao alocar o vetor.\n");
    }
}

void desalocarPacientes(Upa *upa)
{
    free(upa->pacientes);
}

void lePacientes(Upa *upa)
{

    for (int i = 0; i < upa->n; i++)
    {

        scanf("%s%d%d", upa->pacientes[i].nome, &upa->pacientes[i].idade, &upa->pacientes[i].estado_de_saude);
    }
}

void imprimeUpa(Upa *upa)
{
    for (int i = 0; i < upa->n; i++)
    {
        printf("%s %d %d\n", upa->pacientes[i].nome, upa->pacientes[i].idade, upa->pacientes[i].estado_de_saude);
    }
}

void ordena(Upa *upa)
{
    int p = 0, r = upa->n - 1, j;

    Pilha *pPilha = PilhaCria();

    PilhaPush(pPilha, p, r);

    while (!PilhaEhVazia(pPilha))
    {

        PilhaPop(pPilha, &p, &r);

        if (p < r)
        {
            j = partition(upa->pacientes, p, r);
            PilhaPush(pPilha, p, j - 1);
            PilhaPush(pPilha, j + 1, r);
        }
    }

    PilhaDestroi(pPilha);
}

int partition(Paciente *pacientes, int p, int r)
{
    int i, j;
    Paciente x;

    x = pacientes[r];
    i = p - 1;

    for (j = p; j < r; j++)
    {
        if (pacientes[j].estado_de_saude > x.estado_de_saude)
        {
            i++;
            troca(&pacientes[i], &pacientes[j]);
        }
        else if (pacientes[j].estado_de_saude == x.estado_de_saude && pacientes[j].idade > x.idade)
        {
            i++;
            troca(&pacientes[i], &pacientes[j]);
        }
        else if (pacientes[j].estado_de_saude == x.estado_de_saude && pacientes[j].idade == x.idade && strcmp(pacientes[j].nome, x.nome) < 0)
        {
            i++;
            troca(&pacientes[i], &pacientes[j]);
        }
    }

    troca(&pacientes[i + 1], &pacientes[r]);

    return i + 1;
}

void troca(Paciente *p1, Paciente *p2)
{
    Paciente aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}