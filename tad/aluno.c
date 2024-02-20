#include <stdlib.h>
#include <stdio.h>

#include "aluno.h"

// Manter como especificado
Aluno* AlunoAlocar(int n) {
    // preencher conforme a necessidade
    Aluno *vetor = malloc( n * sizeof (Aluno));
    return vetor;
}

// Manter como especificado
void AlunoDesalocar(Aluno** alunos) {
    free(*alunos);
    // preencher conforme a necessidade
}

// Manter como especificado
void AlunoImprimeIndicesMaiorMedia(Aluno* alunos, int n, int maiorMedia) {
    for(int i=0;i<n;i++){
        if(alunos[i].media==maiorMedia)
            printf("%d ", alunos[i].matricula);
    }
    // preencher conforme a necessidade
    // imprimir um espaço apos todos os codigos impressos
}
