#ifndef arvore_h
#define arvore_h
#define RED 1
#define BLACK 0
#include <stdio.h>

typedef struct{
    int idade;
    char nome[20];
} TItem;

typedef struct RBtree{
    TItem item;
    struct RBtree *pEsq;
    struct RBtree *pDir;
    struct RBtree *pai;
    int cor;
} RBtree;

typedef struct {
    RBtree *raiz;
}Tree;

void inicia(Tree* );
Tree* alocarArvore();
RBtree *criaNo( );
void desalocarNO(RBtree*);
void desalocarArvore(Tree**);
void rotacaoEsquerda( Tree **, RBtree *);
void rotacaoDireita(Tree **, RBtree *);
void insercao( Tree *,RBtree *);
void balanceamento( Tree **,RBtree *);
void leArvore(Tree *);
void printInOrder(RBtree *);

# endif

