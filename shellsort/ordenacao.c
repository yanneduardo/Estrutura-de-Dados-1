#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n) {
	
    int h,j;
    Aluno aux;

    for( h = 1;h<n;h++){
        h = 3 * h + 1;
    }

    do
    {
        h = (h-1)/3;

        for( int i = h ; i<n ; i++ ){
            
            strcpy(aux.nome,alunos[i].nome);
            j = i;
            
            while( j>=h &&  compare( alunos[j-h].nome,aux.nome) > 0)
            {
                    strcpy(alunos[j].nome, alunos[j - h].nome);
                    j = j - h;
                if( j < h ){
                    break;
                }
            }
            alunos[j] = aux;  
        }
    } while (h!=1);


}

// Manter como especificado
int compare(const char* aluno1, const char* aluno2) {
    int aluno = (strcmp(aluno1,aluno2));
    
   if(aluno < 0){
        return -1;
    }
    else if( aluno > 0){
        return 1;
    }
    else{
        return 0;
    }
    
}

/* Manter como especificado */
void imprimeResposta(Aluno* alunos, int n, int k) {
    Aluno aux;
   
    //invertendo o vetor
   
     
    for(int i = 0; i < n/2;i++){
        strcpy(aux.nome,alunos[i].nome);
        strcpy(alunos[i].nome, alunos[n-1-i].nome);
        strcpy(alunos[n-1-i].nome,aux.nome);
    }

    
    //printando
    printf("%s\n",alunos[k-1].nome);  
      
}

/* Manter como especificado */
Aluno* alocaAlunos(int n) {
    
    Aluno *vetaluno = (Aluno*) malloc (n*sizeof(Aluno));
    
    if (vetaluno == NULL) 
        printf("\nnão foi possivel alocar o vetor de alunos\n");
    
    return vetaluno;

}

/* Manter como especificado */
void liberaAlunos(Aluno** alunos) {
   
    free(*alunos);

}

/* Manter como especificado */
void leAlunos(Aluno* alunos, int n) {
  
    for(int i=0; i<n ; i++ ){
        scanf("%s",alunos[i].nome);
    }

}

/* Manter como especificado */
void leQuantidades(int* n, int* k) {
    scanf("%d%d", n,k);
}

