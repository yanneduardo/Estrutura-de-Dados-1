/*
------------------------------------  Manipulação de Matrizes --------------------------------------------------------------

Crie um programa que leia um caractere maiúsculo, que indica uma operação que deve ser realizada em uma
matriz de números reais M[12][12]. As operações são: S para soma e M para média. Em seguida, calcule e mostre
a soma, multiplicação ou a média considerando somente aqueles elementos que estão na área superior da matriz,
conforme ilustrado abaixo (área verde).
O código-fonte deve ser modularizado corretamente conforme os arquivos de protótipo fornecidos

----------------------------------- Especificação da Entrada e da saída ---------------------------------------------

A primeira linha de entrada contém um único caractere Maiúsculo O (‘S’ ou ‘M’), indicando a operação (Soma
ou Média, respectivamente) que deverá ser realizada com os elementos da matriz. Seguem 144 valores com ponto
flutuante de dupla precisão que compõem a matriz. A saída é a impressão do resultado solicitado (a soma ou média),
com 1 casa após o ponto decimal.

*/
#include<stdio.h>
#include<ctype.h>
#define TAM 12
int main(){
    char op;
    int contador=0;
    float matriz[TAM][TAM],soma=0,media=0;
  
    scanf(" %c", &op);

    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            scanf(" %f", &matriz[i][j]);
        }
    }
    op= toupper(op);
        for(int i=0;i<5; i++){
            for(int j=1 + i;j<TAM-(i+1);j++){
                soma+= matriz[i][j];
                contador++;
            }
        }

    media= soma/(float)contador;

    if(op == 'S' ){
        printf("\n%.1f", soma);
    }    
    if( op == 'M' ){
        printf("\n%.1f\n", media);
    }
          
    return 0;
}