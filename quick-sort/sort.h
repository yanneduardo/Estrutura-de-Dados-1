#ifndef HEAP_H
#define HEAP_H

typedef struct paciente Paciente;

typedef struct
{
    Paciente *pacientes;
    int n;
} Upa;

void alocarPacientes(Upa *, int);
void desalocarPacientes(Upa *);
void lePacientes(Upa *);
void imprimeUpa(Upa *);
void ordena(Upa *);

#endif // HEAP_H