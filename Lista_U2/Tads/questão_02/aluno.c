#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "diciplina.h"

typedef struct aluno {
    char nome[50];
    int matricula;
    Diciplina *disciplina[10];
    int num_disciplina;
} Aluno;

Aluno *criar_aluno(char nome[], int matricula) {
    Aluno *alu = (Aluno*)malloc(sizeof(Aluno));
    if (alu == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    strcpy(alu->nome, nome);
    alu->matricula = matricula;
    alu->num_disciplina = 0; 
    return alu;
}


void excluir_aluno(Aluno *aluno) {
    if (aluno != NULL) {
        free(aluno);
    }
}
