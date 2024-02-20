#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "grafo.h"

//função que aloca a lista e o grafo
GrafoPonderado *alocarGrafo(int numero_de_cidades) {
    //alocando a struct
    GrafoPonderado *grafo = (GrafoPonderado *)malloc(sizeof(GrafoPonderado));
    //se não der para alocar, vai mostrar mensagem de erro e returnar
    if (grafo == NULL) {
        printf("Erro ao alocar grafo");
        return NULL;
    }
    //numero de cidades que tem
    grafo->numero_de_cidades =numero_de_cidades;
    //alocando o vetor de lista
    grafo->lista_adjancente = alocarLista(numero_de_cidades);

    return grafo;
}
//função que aloca a lista
NoListaAdjacencia *alocarLista(int numero_de_cidades) {
    // Alocando vetor de lista
    NoListaAdjacencia *lista_adjacente = (NoListaAdjacencia *)malloc(numero_de_cidades * sizeof(NoListaAdjacencia ));
    
    // Alocar a cabeça para cada lista
    for (int i = 0; i < numero_de_cidades; i++) {
        
        lista_adjacente[i].pPrimeiro = (TCelula*) malloc (sizeof(TCelula));
        lista_adjacente[i].pUltimo = lista_adjacente[i].pPrimeiro;
        lista_adjacente[i].pPrimeiro->pProx= NULL;

    }
    return lista_adjacente;
}
//verificando se a lista é vazia
int listaEhVazia( NoListaAdjacencia *pLista){
    return(pLista->pPrimeiro == pLista->pUltimo);
}
//desalocando a lista
void desalocarLista(NoListaAdjacencia *pLista){    
    //criando duas variéveis auxiliares, a pAux vai armazenar a cabeça e a segunda vai armazenar o proximo que a pAux aponta 
    TCelula *pAux = pLista->pPrimeiro, *pAux1;
    //enquanto a lista não ficar vazia, o while vai ser executado
    while(pAux !=  NULL){
        pAux1 = pAux->pProx;
        free(pAux);
        pAux = pAux1;

    }  

}

//função que desaloca o grafo
void desalocaGrafo(GrafoPonderado **grafo, int **caminho,int **melhor_caminho,int **cidades_visitadas){
    //desalocando o vetor de lista
    for (int i = 0; i < (*grafo)->numero_de_cidades; i++) {
        desalocarLista(&(*grafo)->lista_adjancente[i]);
    }

    free((*grafo)->lista_adjancente);
    free(*grafo);
    free(*caminho);
    free(*melhor_caminho);
    free(*cidades_visitadas);
}
//criando uma nova celula que vai conter as informações e que vai ser inserida
int insereLista(NoListaAdjacencia *pLista, TItem x ){
    
    pLista->pUltimo->pProx = (TCelula*) malloc (sizeof(TCelula));    
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = x;
    pLista->pUltimo->pProx = NULL;
    return 1;

}

//função que irá ler os dados do arquivo
void leGrafo(GrafoPonderado **grafo) {
    
    int i,n;
    TItem item;
   
    n=(*grafo)->numero_de_cidades * (*grafo)->numero_de_cidades;//n vai ser n² numero de cidades, pois vai ler linha por linha
    //percorrendo as entradas
    for(int j=0 ; j<n ; j++){
        scanf("%d%d", &i, &item.cidade_destino);
        scanf("%d",&item.distancia);
        insereLista(&(*grafo)->lista_adjancente[i], item);
    }

}

//função que ordena a lista 
void bubbleSort( NoListaAdjacencia *pLista) {

    TCelula *pj;
    TCelula *pi;
    pLista->pUltimo = NULL;
    //verificando se alista não é vazia
    if(listaEhVazia(pLista)){
        return;
    }
    //ordenando a lista
    for( pi = pLista->pPrimeiro->pProx; pi->pProx != NULL ; pi = pi->pProx){
        for(pj = pLista->pPrimeiro->pProx; pj->pProx != pLista->pUltimo; pj = pj->pProx){
            if(pj->item.distancia > pj->pProx->item.distancia){
                TItem temp =  pj->item;
                pj->item = pj->pProx->item;
                pj->pProx->item = temp;
            }
        }
    }
    

}
//vai imprimir a lista ordenada
void ordenaEImprimeLista(GrafoPonderado **grafo) {
    printf("\n");
    for (int i = 0; i < (*grafo)->numero_de_cidades; i++) {
        bubbleSort(&(*grafo)->lista_adjancente[i]);
        
        // Imprime a lista de adjacência ordenada
        printf("Adjacencias do vertice %d: ", i);
        // Começa do primeiro elemento da lista, ignorando a cabeça
        NoListaAdjacencia* pLista = &(*grafo)->lista_adjancente[i]; 
        TCelula *pAux = pLista->pPrimeiro->pProx;
       //enquanto não for vazia continuara imprimindo  
        while (pAux != NULL) {
            printf("(%d, %d) -> ", pAux->item.cidade_destino, pAux->item.distancia);
            pAux = pAux->pProx;
        }
        printf("NULL\n");
    }
}




void encontraCaminho(int cidade_atual, int comprimento_caminho,GrafoPonderado **grafo, int caminho[],   int cidades_visitadas[], int *menor_distancia,int *melhor_caminho) {
    
    //comprimento_caminho vai incrementando um a cada vez que a chamada recursiva é chamada,ou seja, ela vai rastrear o número de cidades visitadas
    cidades_visitadas[cidade_atual] = 1;//vai rastreando cada cidade individaulmente, e vai colocando 1 para pode indicar que foi visitada
    caminho[comprimento_caminho] = cidade_atual;//vai adiscionando a cidades que foram visitadas no array caminho
   

    //descontando o caminho inicial
    if (comprimento_caminho == (*grafo)->numero_de_cidades-1) {

        int distancia = 0;
        // Para as cidades no caminho
        for (int i = 0; i < (*grafo)->numero_de_cidades - 1; i++) {
            NoListaAdjacencia* pLista = &(*grafo)->lista_adjancente[caminho[i]];
            TCelula* pAux = pLista->pPrimeiro->pProx;

            int cidade_destino = caminho[i + 1];
            //enquanto não for vazia continuara dentro do while
            while (pAux != NULL) {
                if (pAux->item.cidade_destino == cidade_destino) {
                    // Verifica se a distância é diferente de zero
                    if (pAux->item.distancia != 0) {
                        // Soma a distância
                        distancia += pAux->item.distancia;
                    }
                    else{//se a distancia for = 0 entra aqui, desse modo vai ser desconsiderado e a distancia vai ser reiniciada 
                        return;
                        distancia = 0;
                    }
                    break;  // Sai do loop quando a cidade de destino é encontrada
                
                }
                pAux = pAux->pProx;  // Move para o próximo elemento na lista
            }
        }

        // Para a última cidade até a cidade de origem (ciclo)
        int cidade_origem = caminho[(*grafo)->numero_de_cidades - 1];
        int cidade_destino = caminho[0];

        NoListaAdjacencia* pLista = &(*grafo)->lista_adjancente[cidade_origem];
        TCelula* pAux = pLista->pPrimeiro->pProx;

        while (pAux != NULL) {
            if (pAux->item.cidade_destino == cidade_destino) {
                // Verifica se a distância é diferente de zero
                if (pAux->item.distancia != 0) {
                    // Soma a distância
                    distancia += pAux->item.distancia;
                }
                else{
                    return;
                    distancia =0;
                }
                break;  // Sai do loop quando a cidade de destino é encontrada
            }
            pAux = pAux->pProx;  // Move para o próximo elemento na lista
        }


        //verifica se aquela distância realmente é a menor, se for substitui e armazena aquela distancia
        if (distancia < *menor_distancia) {
        
            *menor_distancia= distancia;
        
            for(int i=0;i<(*grafo)->numero_de_cidades;i++)
        
                melhor_caminho[i] = caminho[i];
        
        }
    
    } 
    else {
        
        for (int i = 0; i < (*grafo)->numero_de_cidades; i++) {
    
            if (! cidades_visitadas[i]) {
    
                encontraCaminho( i,comprimento_caminho+1,grafo, caminho, cidades_visitadas, menor_distancia,melhor_caminho);
                cidades_visitadas[i]=0;
            }
        }
    }
      
}
//imprimindo o caminho
void imprimeCaminho(int n, int *melhor_caminho, int menor_distancia) {

    for (int i = 0; i < n; i++) {
        printf("%d ", melhor_caminho[i]);
    }
    printf("%d", melhor_caminho[0]);
    printf("\n");
    printf("Melhor distancia: ");
    printf("%d\n", menor_distancia);
}
//copiando o caminho menor
void copiaCaminho(int *caminho, int *melhorCaminho, int n) {
    for (int i = 0; i <= n; i++) {
        melhorCaminho[i] = caminho[i];
    }
}


