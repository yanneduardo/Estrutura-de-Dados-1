#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    int op,n;
    Tree *arvore=NULL;

    arvore = alocarArvore();
    do
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%d", &n);
            for(int i = 0;i<n;i++){
                leArvore(arvore);
            }
            break;
        case 2:
            printf("Dados inOrder:\n");
            printInOrder(arvore->raiz);
            break;
        
        default:
            break;
        } 
    } while (op!= 0 );
        printf("Dados inOrder:\n");
        printInOrder(arvore->raiz);
    desalocarArvore(&arvore);
    return 0;
}