#include "sort.h"

#include <stdio.h>

int main()
{
    Upa upa;

    // Ler o numero de pacientes na UPA (upa.n)
    scanf("%d", &upa.n);
    // Alocar pacientes
    alocarPacientes(&upa, upa.n);
    // Ler os pacientes
    lePacientes(&upa);
    // Ordenar o vetor de pacientes
    ordena(&upa);
    // Imprimir os pacientes da UPA
    imprimeUpa(&upa);
    // Desalocar os pacientes da UPA
    desalocarPacientes(&upa);

    return 0;
}