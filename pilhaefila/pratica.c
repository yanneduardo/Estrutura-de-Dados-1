#include <stdio.h>

#include "pilhadupla.h"
#include "fila.h"

int main() {

    Item item;
    Fila *fila;
    PilhaDupla *pilhas;
    // Criar (alocar) a fila e a pilha dupla
    fila = FilaCria();
    pilhas = PilhaDuplaCria();


    while(scanf("%d", &item.chave) && item.chave != 0) {
        //Inserir item lidoo na respectiva pilha, valores pares na lista 0 e impares, na lista 1
        if(item.chave % 2 == 0){
            PilhaPush(pilhas,0,item);
        }
        else{
            PilhaPush(pilhas,1,item);
        }
    }
   

    while( !PilhaEhVazia(pilhas,0) && !PilhaEhVazia(pilhas,1)){
        if(pilhas->tamP1 != 0){
            if(pilhas->itens[pilhas->tamP1-1].chave < 0){
                FilaDesenfileira(fila, &item);
                PilhaPop(pilhas,0,&item);
            }
            else{
                    FilaEnfileira(fila, pilhas->itens[pilhas->tamP1-1]);
                    PilhaPop(pilhas,0,&item);
            }
        }

        if(pilhas->tamP2 != 0){
            if(pilhas->itens[MAX_TAM - pilhas->tamP2].chave < 0){
                FilaDesenfileira(fila, &item);
                PilhaPop(pilhas,1,&item);
            }
            else{              
                FilaEnfileira(fila, pilhas->itens[MAX_TAM - pilhas->tamP2]);
                PilhaPop(pilhas,1,&item);               
            }
        }
    }

    // Imprimir fila
    
    FilaImprime(fila);
    
    // Destruir a fila e a pilha dupla
    FilaDestroi(fila);
    PilhaDuplaDestroi(pilhas);
    
    return 0;
}
