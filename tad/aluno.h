# ifndef aluno_h
# define aluno_h

typedef struct aluno Aluno;

struct aluno{
    int matricula;
    int media;
    // preencher conforme a sua necessidade
};

// Manter como especificado
Aluno* AlunoAlocar(int);

// Manter como especificado
void AlunoDesalocar(Aluno**);

// Manter como especificado
void AlunoImprimeIndicesMaiorMedia(Aluno*, int, int);

# endif // aluno_h
