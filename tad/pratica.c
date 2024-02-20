#include <stdio.h>
#include "aluno.h"

int main() {
    
    int n,maiormedia,contador=1;
    /* adicione as variaveis necessarias */

    Aluno *alunos;

    /* le numero de alunos da primeira turma */
    scanf("%d", &n);
    
    while (n > 0) {
        /* alocar o vetor de alunos conforme a necessidade */
        alunos = AlunoAlocar(n);
        /* le dados dos alunos */
        for(int i=0;i<n;i++){
            scanf("%d%d", &alunos[i].matricula,&alunos[i].media);
        }
        /* procura aluno de maior media */
        maiormedia=alunos[0].media;
        for(int i=0;i<n;i++){
            if(alunos[i].media>=maiormedia){
                maiormedia=alunos[i].media;
            }
        }
        
        /* escreve resposta */
        printf("\nTurma %d\n", contador);
        AlunoImprimeIndicesMaiorMedia(alunos,n,maiormedia);
        /* desalocar o vetor de alunos alocado previamente */
        AlunoDesalocar(&alunos);

        /* le numero de alunos da proxima turma */
        scanf("%d", &n);
        contador++;
    }
    
    return 0;
}
