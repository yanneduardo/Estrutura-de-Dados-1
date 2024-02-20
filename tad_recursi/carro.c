#include "carro.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct funcionario {
   char nome[20];
   int matricula;
};


struct carro {
    int chassi;
    char marca[20];
    int lugares;
    int ano_fabricacao;
    Funcionario* func;
};

Funcionario* FuncionarioAloca() {
    Funcionario *funcionario = malloc (1* sizeof(Funcionario));
    return funcionario;
}

void FuncionarioDesaloca(Funcionario** func) {
    free(*func);
}

Carro* CarroAloca(int n) {
    Carro *carros = malloc(n * sizeof(Carro));
    for (int i =0;i<n;i++){
        carros[i].func = FuncionarioAloca();
    }

    return carros;
}

void CarroDesaloca(Carro** carros, int n) {
    for (int i=0;i< n;i++){
        FuncionarioDesaloca(&(*carros)[i].func);
    }
    free(*carros);
}

void le(Carro* carros, int n) {
    for(int i =0;i<n;i++){
        scanf("%d %s %d %d %s %d", &carros[i].chassi,carros[i].marca,&carros[i].lugares, &carros[i].ano_fabricacao,carros[i].func->nome, &carros[i].func->matricula);
    }
}

int conta(Carro* carros, int n, const int ano, const int lugares) {
    int cont=0;
    if(n==0){
        return 0;
    }
    else{
        if(carros[n-1].ano_fabricacao>ano && carros[n-1].lugares>lugares){
            cont ++;
        }
        return cont + conta(carros,n-1,ano,lugares);

    }
     
}

void imprime(Carro* carros, int n, const char* nome) {
    if(n==0){
        return;
    }
    else{
        if(strcmp(carros[n-1].func->nome,nome)==0){
            printf("%s [%d|%d|%d]", carros[n-1].marca,carros[n-1].ano_fabricacao, carros[n-1].lugares,carros[n-1].chassi);
        }
        imprime(carros,n-1,nome);
    }
}
