#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


int main() {
    int num_cidades;

    scanf("%d", &num_cidades);
    
    GrafoPonderado *grafo = alocarGrafo(num_cidades);

    leGrafo(&grafo);
    //NoListaAdjacencia **lista = alocarLista(  num_cidades);
    
    ordenaEImprimeLista(&grafo);
    
    int *caminho = (int*)malloc(grafo->numero_de_cidades * sizeof(int));
    int *melhor_caminho = (int*) malloc(grafo->numero_de_cidades  * sizeof(int));
    int *cidades_visitadas = (int*) calloc(grafo->numero_de_cidades,sizeof(int));
    int menor_distancia = __INT_MAX__;
    
    encontraCaminho(0,0,&grafo, caminho,cidades_visitadas,&menor_distancia,melhor_caminho);


    printf("\nMelhor caminho: ");
    imprimeCaminho(num_cidades, melhor_caminho,menor_distancia);
    
    desalocaGrafo(&grafo,&caminho,&melhor_caminho,&cidades_visitadas);

    return 0;
}
