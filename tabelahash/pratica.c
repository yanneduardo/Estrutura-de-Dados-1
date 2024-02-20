#include <stdio.h>

#include "hash.h"

int main()
{
    Hash hash;
    Chave chave;
    int n, tamDaString, resposta;
    // Ler a quantidade de casos
    scanf("%d", &n);
    while (n-- > 0)
    {
        // Lendo tamanho da tabela e quantidade de pesos
        scanf("%d%d", &hash.m, &hash.p);
        // Iniciar Hash
        inicia(&hash, hash.m, hash.p);
        // Lendo pesos
        for (int i = 0; i < hash.p; i++)
        {
            scanf("%d", &hash.pesos[i]);
        }
        // Lendo quantidade de chaves
        scanf("%d", &tamDaString);
        // Lendo chaves
        for (int j = 0; j < tamDaString; j++)
        {
            scanf("%s", chave);
            resposta = insere(&hash, chave);
        }
        // Imprimir resposta
        printf("%d\n", resposta);
        // Liberar Hash
        libera(&hash);
    }

    return 0;
}