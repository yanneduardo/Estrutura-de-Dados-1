#ifndef hash_h
#define hash_h
#define VAZIO "!!!!!!!!!!\0"

typedef char Chave[11]; // A chave tem até 10 chars

typedef struct
{
    Chave *chaves; // Vetor para armazenar até m chaves
    int *pesos;    // Vetor de pesos
    int m;         // Tamanho do vetor de chaves
    int p;         // Tamanho do vetor de pesos
} Hash;

void inicia(Hash *, int, int);
void libera(Hash *);
int insere(Hash *, Chave);
int pesquisa(Hash *, Chave);

#endif
