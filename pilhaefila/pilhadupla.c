#include "pilhadupla.h"

#include <stdio.h>
#include <stdlib.h>

PilhaDupla* PilhaDuplaCria() {
    PilhaDupla *pilhaDupla =  malloc (sizeof(PilhaDupla));
    pilhaDupla->tamP1=0;
    pilhaDupla->tamP2=0;

    return pilhaDupla;
}

PilhaDupla* PilhaDuplaDestroi(PilhaDupla* pPilhas) {
    free(pPilhas);
    pPilhas = NULL;
    return pPilhas;
}

bool PilhaEhVazia(PilhaDupla* pPilhas, int id) {
    
    return (pPilhas->tamP1 == 0) && (pPilhas->tamP2 == 0);
}

bool PilhaEhCheia(PilhaDupla* pPilhas, int id) {
    
   return (pPilhas->tamP1 + pPilhas->tamP2) == MAX_TAM;
   
}

bool PilhaPush(PilhaDupla* pPilhas, int id, Item item) {//colocar
    
    if(PilhaEhCheia(pPilhas,id)){
        return false;
    }
    else if( id == 0){
        pPilhas->itens[pPilhas->tamP1] = item;
        pPilhas->tamP1++;
        return true;
    }
    else if(id ==1){
        pPilhas->itens[MAX_TAM - pPilhas->tamP2 - 1 ] = item;
        pPilhas->tamP2++;
        return true;
    }
    return false;
}

bool PilhaPop(PilhaDupla* pPilhas, int id, Item* pItem) {//remove
    if(PilhaEhVazia(pPilhas,id)){
        return false;
    }
    else if(id == 0){
        *pItem =  pPilhas->itens[pPilhas->tamP1 - 1];
        pPilhas->tamP1--;
        return true;
    }
    else if(id == 1){
        *pItem = pPilhas->itens[MAX_TAM - 1 - pPilhas->tamP2];
        pPilhas->tamP2--;
        return true;
    }

    return false;

}

int PilhaTamanho(PilhaDupla* pPilhas, int id) {
     return (pPilhas->tamP1 + pPilhas->tamP2);
}

void PilhaImprime(PilhaDupla* pPilhas, int id) {
    printf("Fila: [");
    if(id== 0){
        for(int i=0; i<pPilhas->tamP1; i++){
            printf( "(%d)", pPilhas->itens[i].chave);
        }
    }
    else{
        for(int i=0; i<pPilhas->tamP2; i++){
            printf("(%d)", pPilhas->itens[MAX_TAM - 1- i].chave);
        }
    }
    printf("]\n");
}
