#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void leArvore(Tree *arvore)
{
    RBtree *novoNo = criaNo();
    if (novoNo == NULL)
    {
        return;
    }

    if (scanf("%s", novoNo->item.nome) != 1)
    {
        free(novoNo);
        return;
    }
    if (scanf("%d", &novoNo->item.idade) != 1)
    {
        free(novoNo);
        return;
    }
    insercao(arvore, novoNo);
}

void inicia(Tree *arvore)
{
    arvore->raiz = NULL;
}

Tree *alocarArvore()
{
    Tree *arvore = (Tree *)malloc(sizeof(Tree));
    if (arvore != NULL)
    {
        inicia(arvore);
    }
    return arvore;
}

void desalocarArvore(Tree **arvore)
{
    if ((*arvore)->raiz != NULL)
    {
        desalocarNO((*arvore)->raiz);
    }
    free(*arvore);
}

void desalocarNO(RBtree *no)
{
    if (no->pDir != NULL)
    {
        desalocarNO(no->pDir);
    }
    if (no->pEsq != NULL)
    {
        desalocarNO(no->pEsq);
    }
    free(no);
}

RBtree *criaNo()
{
    RBtree *pAux = (RBtree *)malloc(sizeof(RBtree));
    pAux->pEsq = NULL;
    pAux->pDir = NULL;
    pAux->pai = NULL;
    pAux->cor = RED;
    return pAux;
}

void rotacaoEsquerda(Tree **arvore, RBtree *pNo)
{
    //salvando o filho direito de pNo em pAux
    RBtree *pAux = pNo->pDir;
    //atualizando o ponteiro direito de pNo para apontar para o filho esquerdo de pAux
    pNo->pDir = pAux->pEsq;
    // Se o filho esquerdo de pAux não for nulo, atualize seu pai para apontar para pNo
    if (pAux->pEsq != NULL)
    {
        pAux->pEsq->pai = pNo;
    }
    // Atualizando o pai de pAux para apontar para o pai de pNo
    pAux->pai = pNo->pai;
    // Se pNo é a raiz da árvore, atualize a raiz para apontar para pAux
    if (pNo->pai == NULL)
    {
        (*arvore)->raiz = pAux;
    }
    // Se pNo não é a raiz e é o filho esquerdo do seu pai, atualize o filho esquerdo do pai de pNo para apontar para pAux
    else if (pNo == pNo->pai->pEsq)
    {
        pNo->pai->pEsq = pAux;
    }
     // Se pNO não é a raiz e é o filho direito do seu pai, atualize o filho direito do pai de pNo para apontar para pAUx
    else
    {
        pNo->pai->pDir = pAux;
    }
    // Faça o filho esquerdo de pAux apontar para pNo
    pAux->pEsq = pNo;
    // Faça o pai de pNo apontar para pAux
    pNo->pai = pAux;
}
//simetrico a da rotacao esquerda
void rotacaoDireita(Tree **arvore, RBtree *x)
{
    RBtree *pAux = x->pEsq;
    x->pEsq = pAux->pDir;
    if (pAux->pDir != NULL)
    {
        pAux->pDir->pai = x;
    }
    pAux->pai = x->pai;
    if (x->pai == NULL)
    {
        (*arvore)->raiz = pAux;
    }
    else if (x == x->pai->pDir)
    {
        x->pai->pDir = pAux;
    }
    else
    {
        x->pai->pEsq = pAux;
    }
    pAux->pDir = x;
    x->pai = pAux;
}


void insercao(Tree *arvore, RBtree *pNo)
{
    RBtree *y = NULL;
    RBtree *x = arvore->raiz;
    // Procura a posição de inserção na árvore
    while (x != NULL)
    {
        y = x;
        if (pNo->item.idade < x->item.idade)
        {
            x = x->pEsq;
        }
        else
        {
            x = x->pDir;
        }
    }
    // Define o pai do novo nó
    pNo->pai = y;
    // Atualiza a raiz se a árvore estiver vazia
    if (y == NULL)
    {
        arvore->raiz = pNo;
    }
    else if (pNo->item.idade < y->item.idade)
    {
        y->pEsq = pNo;
    }
    else
    {
        y->pDir = pNo;
    }
    // Balanceamento após a inserção
    balanceamento(&arvore, pNo);
}

void balanceamento(Tree **arvore, RBtree *pNo)
{
    RBtree *pAux;
    // Loop de balanceamento, enquanto o nó pNo não é a raiz e o pai de de pNo é vermelhor
    while (pNo != (*arvore)->raiz && pNo->pai->cor == RED)
    {
        // se o pai de pNo é o filho esquerdo do avô de pNo
        if (pNo->pai == pNo->pai->pai->pEsq)
        {
            // define pAux como o tio de pNo
            pAux = pNo->pai->pai->pDir;
            // Caso 1: Se o tio de pNo é vermelho
            if (pAux != NULL && pAux->cor == RED)
            {
                // Recoloração
                pNo->pai->cor = BLACK;
                pAux->cor = BLACK;
                pNo->pai->pai->cor = RED;
                pNo = pNo->pai->pai; // Move pNo para o avô de pNo
            }
            // Caso 2: Se o tio de pNo é preto e pNo é o filho direito de seu pai
            else
            {
                if (pNo == pNo->pai->pDir)
                {
                    pNo = pNo->pai;                 // Move pNo para o pai
                    rotacaoEsquerda(arvore, pNo); // Rotaciona à esquerda em torno de pNo
                // Caso 3: Se o tio de pNo é preto e pNo é o filho esquerdo de seu pai
                }
                pNo->pai->cor = BLACK;                 // Recolora o pai de pNo para preto
                pNo->pai->pai->cor = RED;              // Recolora o avô de pNo para vermelho
                rotacaoDireita(arvore, pNo->pai->pai); // Rotaciona à direita em torno do avô de pNo
            }
        }
        else
        {
            // Caso simétricos para o pai de pNo sendo o filho direito do avô de pNo
            pAux = pNo->pai->pai->pEsq;
            if (pAux != NULL && pAux->cor == RED)
            {
                pNo->pai->cor = BLACK;
                pAux->cor = BLACK;
                pNo->pai->pai->cor = RED;
                pNo = pNo->pai->pai;
            }
            else
            {
                if (pNo == pNo->pai->pEsq)
                {
                    pNo = pNo->pai;
                    rotacaoDireita(arvore, pNo);
                }
                pNo->pai->cor = BLACK;
                pNo->pai->pai->cor = RED;
                rotacaoEsquerda(arvore, pNo->pai->pai);
            }
        }
    }
    (*arvore)->raiz->cor = BLACK;
}

void printInOrder(RBtree *no)
{
    if (no == NULL)
    {
        return;
    }

    printInOrder(no->pEsq);
    printf("Nome: %s\nIdade: %d\n", no->item.nome, no->item.idade);
    printInOrder(no->pDir);
}
