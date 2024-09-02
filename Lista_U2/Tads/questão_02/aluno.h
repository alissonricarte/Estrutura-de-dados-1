#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno *criar_aluno(char nome[], int matricula);
void excluir_aluno(Aluno *aluno);

#endif
