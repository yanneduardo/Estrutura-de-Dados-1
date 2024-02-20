#include "ordenacao.h"
#include <stdio.h>

int main () {

	int* vetor;
	int i, n, movimentos;
	while(scanf("%d", &n), n) {
		// atualizar movimentos
		movimentos = 0;
		// alocar o vetor
		vetor = alocaVetor (n);
		// preencher o vetor
		for(i = 0; i<n;i++){
			scanf("%d ", &vetor[i]);
		}
		// ordenar o vetor e determinar o número de movimentos
		ordenacao(vetor,n,&movimentos);
		// imprimir o resultado
		if(movimentos %2==0){
			printf("Carlos\n");
		}
		else{
			printf("Marcelo\n");
		}
		// desalocar o vetor
		desalocaVetor(vetor);
	}

	return 0;
}
