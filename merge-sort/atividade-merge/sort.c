#include "sort.h"
#include <stdlib.h>

// Cabecalho das funcoes
void InsertionSort(int*v,int n);
void MergeSort(int *v, int esquerda, int direita, int *contador);
void merge(int *v, int esquerda,int m,int direita);

// Manter como especificado
int sort(int* v, int n) {

   int contador = 0;
   MergeSort(v,0,n-1,&contador);
   return contador;

}

void InsertionSort(int *v, int n) {
   
    int vAux ;
    int j;

    for(int i= 1; i<n;i++ ){
        
        vAux = v[i];
        j = i - 1;
        
        while(j>=0 && vAux < v[j]){
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = vAux;
    }

}

void MergeSort(int *v, int esquerda, int direita, int *contador) {
    
    int m;
    
    if( direita - esquerda + 1 <=10){
        InsertionSort(v+esquerda, direita - esquerda +1);
        (*contador)++;

    }

    else {
            if(esquerda<direita){

            m= (esquerda + direita)/2;
            MergeSort(v,esquerda,m,contador);
            MergeSort(v,m+1,direita,contador);
            merge(v,esquerda,m,direita);
        
        }
    }
}

void merge(int *v, int esquerda,int m,int direita) {
   
    int tamanhoEsquerda = ( m - esquerda+1);
    int tamanhoDireita = (direita - m);

    int* vetEsquerda = (int *) malloc (tamanhoEsquerda*sizeof(int));
    int* vetDireita = (int *) malloc (tamanhoDireita*sizeof(int));

  

    for(int i =0; i<tamanhoEsquerda;i++){
    
        vetEsquerda[i] = v[i+ esquerda];
    
    }

    for(int i=0;i<tamanhoDireita;i++){

        vetDireita[i] = v[m+i+1];
    
    }

    int  i=0,j=0;

    for(int k= esquerda; k <= direita; k++){
       
        if( i== tamanhoEsquerda ){
            
            v[k] = vetDireita[j++];

        }
        else if( j == tamanhoDireita ){

            v[k] = vetEsquerda[i++];
        }

        else if(vetEsquerda[i] <= vetDireita[j]){
            v[k] = vetEsquerda[i++];
        }
        else{
            v[k]=vetDireita[j++];
        }
    }

    free(vetDireita);
    free(vetEsquerda);

}
