#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno1 Aluno;

Aluno * criarAluno( int matricula, char nome[], float media);

void salvarAlunoEmArquivo( char nome_do_arquivo[], Aluno *aluno1);

void exibirAlunos(char nome_do_arquivo[]);
