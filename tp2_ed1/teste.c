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
    //alocando vetor de lista
    grafo->lista_adjancente = (No_Lista_Adjacencia **) malloc (numero_de_cidades * sizeof(No_Lista_Adjacencia*));
    //se não der para alocar, vai desalocar e mostrar mensagem de erro e retornar
    if(grafo->lista_adjancente == NULL){
        printf("Erro ao alocar vetor de lista");
        free(grafo);
        return NULL;
    }
    //vai alocar a cabeça para cada lista
    for(int i=0;i<numero_de_cidades;i++){
        //alocando a cabeça para cada lista
        grafo->lista_adjancente[i] = (No_Lista_Adjacencia*) malloc (numero_de_cidades * sizeof(No_Lista_Adjacencia));
        //se não for possivel alocar ira liberar memória e desalocar 
        if(grafo->lista_adjancente[i]==NULL){
            printf("Erro ao alocar a cabeça para cada lista");
            free(grafo->lista_adjancente);
            free(grafo);
            return NULL;
        }
    }
}

//função que desaloca
void desalocaGrafo(GrafoPonderado **grafo,int **caminho,int **melhor_caminho,int **cidades_visitadas){
    
    for(int i=0;i<(*grafo)->numero_de_cidades; i++){
        //liberando cada nó da lista
        No_Lista_Adjacencia *pAux = (*grafo)->lista_adjancente[i];
        //enquanto não chegar no final da lista, a memoria continuara sendo desalocada
        while( pAux!= NULL){
            No_Lista_Adjacencia *pAux2 = pAux->pProx;
            free(pAux);
            pAux = pAux2;
        }
    }
    free((*grafo)->lista_adjancente);
    free(*grafo);
    free(*caminho);
    free(*melhor_caminho);
    free(*cidades_visitadas);
}
//função que irá ler os dados do arquivo
void leGrafo(GrafoPonderado *grafo) {
    int cidade_origem, cidade_destino, distancia;
    //enquanto tiver entrada para ler ele continuara dentro do while
    while (scanf("%d %d %d",&cidade_origem, &cidade_destino,&distancia)!= EOF)
    {
        // o motivo de estar alocando novo_no dentro do while, é pq a cada interação do loop, ira criar um nó novo, desse modo, vai criando a lista, isto é, vai criando a aresta.
        No_Lista_Adjacencia *novo_no = (No_Lista_Adjacencia*) malloc (sizeof(No_Lista_Adjacencia));
        // caso não seja possível alocar, ira mostra mensagem de erro
        if(novo_no == NULL){
            printf("Erro ao alocar o novo nó para cada interação");
            break;
        }
        // atribuindo o valor de cidade_destino na celula/lista 
        novo_no->cidade_destino = cidade_destino;
        //atribuindo o valor da distancia na celula/lista
        novo_no->distancia = distancia;
        //agora vamos adiscionar um novo nó no inicio da lista, ou seja, estamos fazendo como que o novo_no->pProx aponta para onde o grafo->lista_adjancente está apontando
        novo_no->pProx = grafo->lista_adjancente[cidade_origem];
        //agora estou atualizando para onde que lista_ajancente vai apontar, ou seja, ela vai apontar para o valor que acabou de ser inserido
        grafo->lista_adjancente[cidade_origem] = novo_no;
    }
    
}


void encontraCaminho(int cidade_atual, int comprimento_caminho,GrafoPonderado *grafo, No_Lista_Adjacencia **adjacente, int caminho[], int cidades_visitadas[], int *menor_distancia,int *melhor_caminho) {
    //comprimento_caminho vai incrementando um a cada vez que a chamada recursiva é chamada,ou seja, ela vai rastrear o número de cidades visitadas
    cidades_visitadas[cidade_atual] = 1;//vai rastreando cada cidade individaulmente, e vai colocando 1 para pode indicar que foi visitada
    caminho[comprimento_caminho] = cidade_atual;//vai adiscionando a cidades que foram visitadas no array caminho
    
    No_Lista_Adjacencia *pAux;
    if (comprimento_caminho == grafo->numero_de_cidades-1) {

        int distancia = 0;
        //nesse trecho, o for está percorrendo todo o caminho e somando a distancia na variavel distancia
        for (int i = 0; i < grafo->numero_de_cidades-1; i++) {
            
            int cidade_origem= caminho[i];
            int cidade_destino= caminho[i+1];
            
            pAux = adjacente[cidade_origem];
            //o while vai percorrendo até achar a aresta correta, por exemplo, vamos supor que temos um caminho que seja, {0,1,2,3,0} no primeiro caso, vamos supor que pAux aponta para 1, e a cidade de destino é 1, dessa forma, entrara no loop, resumindo, esse loop serve para encontrar o nó que representa na aresta. 
            while(pAux->cidade_destino != cidade_destino){
                pAux = pAux->pProx;
            }
            
            if(pAux->distancia == 0){
                return; // Sai da função, ignorando essa cidade
            }else {
                distancia += pAux->distancia;   
            }
            
        }
        //nesse trecho, ele vai acrescentar na variavel distancia, a distancia da ultima cidade até a cidade de origem
        int cidade_origem = caminho[grafo->numero_de_cidades-1];
        int cidade_destino = caminho[0];

        pAux = adjacente[cidade_origem];
        //o while vai percorrendo até achar a aresta correta, por exemplo, vamos supor que temos um caminho que seja, {0,1,2,3,0} no primeiro caso, vamos supor que pAux aponta para 1, e a cidade de destino é 1, dessa forma, entrara no loop, resumindo, esse loop serve para encontrar o nó que representa na aresta. 
        while(pAux->cidade_destino != cidade_destino){
            pAux = pAux->pProx;
        }
            
        if(pAux->distancia == 0){
            return;
        } else{
            distancia += pAux->distancia;
        }
        
        if (distancia < *menor_distancia) {
        
            *menor_distancia= distancia;
        
            for(int i=0;i<grafo->numero_de_cidades;i++)
        
                melhor_caminho[i] = caminho[i];
        
        }
    
    } else {
    
        for (int i = 0; i < grafo->numero_de_cidades; i++) {
    
            if (! cidades_visitadas[i]) {
    
                encontraCaminho( i,comprimento_caminho+1,grafo, caminho,adjacente, cidades_visitadas, menor_distancia,melhor_caminho);
                cidades_visitadas[i]=0;
            }
        }
    }
      
}


void insertionSort(No_Lista_Adjacencia **head) {
    if (head == NULL || *head == NULL || (*head)->pProx == NULL) {
        return; // Lista vazia ou com apenas um elemento já está ordenada
    }

    No_Lista_Adjacencia *sorted = NULL;
    No_Lista_Adjacencia *current = *head;

    while (current != NULL) {
        No_Lista_Adjacencia *next = current->pProx;

        if (sorted == NULL || sorted->cidade_destino >= current->cidade_destino) {
            // Insere no início da lista ordenada
            current->pProx = sorted;
            sorted = current;
        } else {
            // Procura o local adequado para inserção
            No_Lista_Adjacencia *search = sorted;
            while (search->pProx != NULL && search->pProx < current->cidade_destino) {
                search = search->pProx;
            }

            // Insere após o nó search
            current->pProx = search->pProx;
            search->pProx = current;
        }

        current = next;
    }

    // Ajusta a cabeça da lista
    *head = sorted;
}

void ordenaEImprimeLista(GrafoPonderado *grafo) {
    for (int i = 0; i < grafo->numero_de_cidades; i++) {
        insertionSort(&(grafo->lista_adjancente[i]));

        // Imprime a lista de adjacência ordenada
        printf("Lista de adjacência ordenada para o vértice %d:\n", i);
        No_Lista_Adjacencia *temp = grafo->lista_adjancente[i];
        while (temp != NULL) {
            printf("(%d, %d) -> ", temp->cidade_destino, temp->distancia);
            temp = temp->pProx;
        }
        printf("NULL\n");
    }
}

void imprimeCaminho(int n, int *melhor_caminho, int menor_distancia) {

    for (int i = 0; i < n; i++) {
        printf("%d ", melhor_caminho[i]);
    }
    printf("%d", melhor_caminho[0]);
    printf("\n");
    printf("%d\n", menor_distancia);
}

void copiaCaminho(int *caminho, int *melhorCaminho, int n) {
    for (int i = 0; i <= n; i++) {
        melhorCaminho[i] = caminho[i];
    }
}
