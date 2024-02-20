#include<stdio.h>

int main(){
    int i=1;
    float soma = 0,troco,n,dinh;
    printf("loja tabajara\n");
    printf (" Digite o valor do produto %d (ou zero para terminar): ",i);
    scanf("%f",&n);
    while(n!=0){
        float soma =0;
        soma+= n;
        i++;
        printf (" Digite o valor do produto %d (ou zero para terminar): ",i);
        scanf("%f",&n);
       
    }
    printf("Total: R$%.2f", soma);
    printf("\nDigite o dinheiro: ");
    scanf("%f", &dinh);
    troco= dinh - soma;
    printf("troco R$: %.2f", troco);

}