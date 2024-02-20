#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista) {
    pLista->pPrimeiro = (TCelula*) malloc (sizeof (TCelula));
    pLista->pUltimo = pLista->pPrimeiro;
    pLista->pPrimeiro->pProx = NULL;
    pLista->tam=0;
}
//Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista) {
    return(pLista->pPrimeiro == pLista->pUltimo);
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x) {
    
    pLista->pUltimo->pProx = (TCelula*) malloc (sizeof(TCelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx= NULL;
    pLista->tam++;
    return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX) {
    
    if(TLista_EhVazia(pLista)){
        printf("Lista vazia");
        return 0;
    }
    TCelula *pAux;
    pAux = pLista->pPrimeiro->pProx;
    *pX = pAux->item;
    pLista->pPrimeiro->pProx = pAux->pProx;
    free(pAux);
    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista) {
    TCelula *aux=pLista->pPrimeiro->pProx;

    for(int i =0; i < pLista->tam; i++){
        printf("%s ", aux->item.nome);
        aux = aux->pProx;
    }
    printf("\n");
}

//Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista) {
    TItem trash;
    while(TLista_RetiraPrimeiro(pLista, &trash));

}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2){
    pLista1->pUltimo->pProx = pLista2->pPrimeiro->pProx;
    pLista1->pUltimo = pLista2->pUltimo;
    pLista1->tam += pLista2->tam;

    pLista2->pPrimeiro->pProx = NULL;
    pLista2->pUltimo = pLista2->pPrimeiro;
    pLista2->tam = 0;

}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str){
    TCelula *pAux, *pAnte;
    pAux = pLista1->pPrimeiro->pProx;
    pAnte = pLista1->pPrimeiro;
    for(int i=0;i<pLista1->tam;i++){
        if(strcmp(str, pAux->item.nome)==0){
            break;
        }
        pAux= pAux->pProx;
        pAnte = pAnte->pProx;
    }

    pAnte->pProx = pLista2->pPrimeiro->pProx;
    pLista2->pUltimo->pProx = pAux;
    pLista1->tam += pLista2->tam;

    pLista2->pPrimeiro->pProx = NULL;
    pLista2->pUltimo = pLista2->pPrimeiro;
    pLista2->tam = 0;
}
