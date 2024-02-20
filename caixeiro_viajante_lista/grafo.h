#ifndef grafo_h
#define grafo_h

typedef struct {
    int cidade_destino;
    int distancia;
}TItem;

typedef struct cel{
    struct cel* pProx;
    TItem item;
}TCelula;

typedef struct{
    TCelula *pPrimeiro,*pUltimo;
} NoListaAdjacencia;

typedef struct grafoponderado{
    int numero_de_cidades;// variável que armazena a quantidade de cidades
    NoListaAdjacencia* lista_adjancente;
}GrafoPonderado;



GrafoPonderado* alocarGrafo(int numero_de_cidade);//alocar variavel

NoListaAdjacencia* alocarLista( int numero_de_cidade);

int insereLista(NoListaAdjacencia *pLista, TItem x );

int listaEhvazia(NoListaAdjacencia *pLista);
    
void bubbleSort( NoListaAdjacencia *pLista);

void ordenaEImprimeLista(GrafoPonderado **grafo);

void desalocarLista(NoListaAdjacencia *pLista);

void desalocaGrafo(GrafoPonderado **grafo,int **caminho,int **melhor_caminho,int **cidades_visitadas);//desalocar variavel

void leGrafo(GrafoPonderado **grafo); //inicializa o TAD GrafoPonderado a parti de dado do terminal

void encontraCaminho(int cidade_atual, int comprimento_caminho,GrafoPonderado **grafo, int caminho[], int cidades_visitadas[], int *menor_distancia,int *melhor_caminho);//função recursiva que retorna o menor caminho

void imprimeCaminho(int n, int *melhor_caminho, int menor_distancia);//imprime o menor caminho e a distancia percorrida

void copiaCaminho(int *caminho, int *melhorCaminho, int n);


#endif