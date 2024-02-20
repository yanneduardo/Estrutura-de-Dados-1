
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