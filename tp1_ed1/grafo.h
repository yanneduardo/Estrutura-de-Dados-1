#ifndef grafo_h
#define grafo_h


typedef struct grafoponderado{
    int numero_de_cidades;// variável que armazena a quantidade de cidades
    int **matriz_cidades;// variável que armazena as cidades vizinhas e a distância
}GrafoPonderado;

//alocar variavel
GrafoPonderado* alocarGrafo(int numero_de_cidade);
//desalocar variavel
void desalocaGrafo(GrafoPonderado **grafo,int **caminho,int **melhor_caminho,int **cidades_visitadas);
//inicializa o TAD GrafoPonderado a parti de dado do terminal
void leGrafo(GrafoPonderado *grafo); 
//função recursiva que retorna o menor caminho
void encontraCaminho(int cidade_atual, int comprimento_caminho,GrafoPonderado *grafo, int caminho[], int cidades_visitadas[], int *menor_distancia,int *melhor_caminho);
//imprime o menor caminho e a distancia percorrida
void imprimeCaminho(int n, int *melhor_caminho, int menor_distancia);
void copiaCaminho(int *caminho, int *melhorCaminho, int n);


#endif