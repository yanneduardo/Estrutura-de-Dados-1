#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "grafo.h"

GrafoPonderado *alocarGrafo(int numero_de_cidades)
{
    GrafoPonderado *grafo = (GrafoPonderado *)malloc(sizeof(GrafoPonderado));
    if (grafo == NULL)
    {
        printf("Erro ao alocar grafo");
        return NULL;
    }
    grafo->numero_de_cidades = numero_de_cidades;

    grafo->matriz_cidades = malloc(grafo->numero_de_cidades * sizeof(int *));

    for (int i = 0; i < grafo->numero_de_cidades; i++)
    {
        grafo->matriz_cidades[i] = malloc(grafo->numero_de_cidades * sizeof(int));
    }

    return grafo;
}

void desalocaGrafo(GrafoPonderado **grafo, int **caminho, int **melhor_caminho, int **cidades_visitadas)
{ // desalocando a struct e a matriz
    for (int i = 0; i < (*grafo)->numero_de_cidades; i++)
    {
        free((*grafo)->matriz_cidades[i]);
    }
    free((*grafo)->matriz_cidades);
    free(*grafo);
    free(*caminho);
    free(*melhor_caminho);
    free(*cidades_visitadas);
}

void leGrafo(GrafoPonderado *grafo)
{
    for (int i = 0; i < grafo->numero_de_cidades; i++)
    {
        for (int j = 0; j < grafo->numero_de_cidades; j++)
        {
            scanf("%d%d", &i, &j);
            scanf("%d", &grafo->matriz_cidades[i][j]);
        }
    }
}

void encontraCaminho(int cidade_atual, int comprimento_caminho, GrafoPonderado *grafo, int caminho[], int cidades_visitadas[], int *menor_distancia, int *melhor_caminho)
{
    // comprimento_caminho vai incrementando um a cada vez que a chamada recursiva é chamada,ou seja, ela vai rastrear o número de cidades visitadas
    cidades_visitadas[cidade_atual] = 1;         // vai rastreando cada cidade individaulmente, e vai colocando 1 para pode indicar que foi visitada
    caminho[comprimento_caminho] = cidade_atual; // vai adiscionando a cidades que foram visitadas no array caminho

    if (comprimento_caminho == grafo->numero_de_cidades - 1)
    {

        int distancia = 0;
        // nesse trecho, o for está percorrendo todo o caminho e somando a distancia na variavel distancia
        for (int i = 0; i < grafo->numero_de_cidades - 1; i++)
        {

            int cidade_origem = caminho[i];
            int cidade_destino = caminho[i + 1];

            if (grafo->matriz_cidades[cidade_origem][cidade_destino] > 0)
            {

                distancia += grafo->matriz_cidades[cidade_origem][cidade_destino];
            }
            else
            {
                // Se a distância é zero, interrompe o loop e a recursão
                distancia = 0;
                return; // Sai da função, ignorando essa cidade
            }
        }
        // nesse trecho, ele vai acrescentar na variavel distancia, a distancia da ultima cidade até a cidade de origem
        int cidade_origem = caminho[grafo->numero_de_cidades - 1];
        int cidade_destino = caminho[0];

        if (grafo->matriz_cidades[cidade_origem][cidade_destino] > 0)
        {

            distancia += grafo->matriz_cidades[cidade_origem][cidade_destino];
        }
        else
        {

            distancia = 0;
            return;
        }

        if (distancia < *menor_distancia)
        {

            *menor_distancia = distancia;

            for (int i = 0; i < grafo->numero_de_cidades; i++)

                melhor_caminho[i] = caminho[i];
        }
    }
    else
    {

        for (int i = 0; i < grafo->numero_de_cidades; i++)
        {

            if (!cidades_visitadas[i])
            {

                encontraCaminho(i, comprimento_caminho + 1, grafo, caminho, cidades_visitadas, menor_distancia, melhor_caminho);
                cidades_visitadas[i] = 0;
            }
        }
    }
}

void imprimeCaminho(int n, int *melhor_caminho, int menor_distancia)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", melhor_caminho[i]);
    }
    printf("%d", melhor_caminho[0]);
    printf("\n");
    printf("%d\n", menor_distancia);
}

void copiaCaminho(int *caminho, int *melhorCaminho, int n)
{
    for (int i = 0; i <= n; i++)
    {
        melhorCaminho[i] = caminho[i];
    }
}
