#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TURMAS 10
#define MAX_VAGAS 30

struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma {
    char id; 
    int vagas; 
    Aluno* alunos[MAX_VAGAS];
};
typedef struct turma Turma;

Turma* turmas[MAX_TURMAS] = {NULL}; 

Turma* cria_turma(char id) {
    Turma *t = (Turma*) malloc(sizeof(Turma));
    t->id = id;
    t->vagas = MAX_VAGAS;
    for (int i = 0; i < MAX_VAGAS; i++) {
        t->alunos[i] = NULL;
    }
    return t;
}

void matricula_aluno(Turma* turma, int mat, char* nome) {
    if (turma->vagas > 0) {
        Aluno *a = (Aluno*) malloc(sizeof(Aluno));
        a->mat = mat;
        strcpy(a->nome, nome);
        for (int i = 0; i < 3; i++) {
            a->notas[i] = 0.0;
        }
        a->media = 0.0;
        for (int i = 0; i < MAX_VAGAS; i++) {
            if (turma->alunos[i] == NULL) {
                turma->alunos[i] = a;
                turma->vagas--;
                break;
            }
        }
        printf("Aluno matriculado com sucesso!\n");
    } else {
        printf("Não há vagas disponíveis nesta turma.\n");
    }
}

void lanca_notas(Turma* turma) {
    if (turma == NULL) {
        printf("Turma inexistente!\n");
        return;
    }
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("Matricula: %d Aluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
            for (int j = 0; j < 3; j++) {
                printf("Digite a nota %d: ", j + 1);
                scanf("%f", &(turma->alunos[i]->notas[j]));
            }
            turma->alunos[i]->media = (turma->alunos[i]->notas[0] + turma->alunos[i]->notas[1] + turma->alunos[i]->notas[2]) / 3;
        }
    }
}

void imprime_alunos(Turma* turma) {
    if (turma == NULL) {
        printf("Turma inexistente!\n");
        return;
    }
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("Matricula: %d\nNome: %s\nMedia: %.2f\n", turma->alunos[i]->mat, turma->alunos[i]->nome, turma->alunos[i]->media);
        }
    }
}

void imprime_turmas(Turma** turmas, int n) {
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL) {
            printf("Turma %c - %d vagas disponíveis\n", turmas[i]->id, turmas[i]->vagas);
        }
    }
}

Turma* procura_turma(Turma** turmas, int n, char id) {
    for (int i = 0; i < n; i++) {
        if (turmas[i] != NULL && turmas[i]->id == id) {
            return turmas[i];
        }
    }
    return NULL;
}

int main() {
    char opcao;
    int num_turmas = 0;

    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as\n");
    printf("funcionalidades de matricula, lancamento de notas e listagem de\n");
    printf("alunos.\n");
    printf("Autor: Ada Lovelace Versao: 1.0\n");

    do {
        printf("MENU:\n");
        printf("1 – Criar turma\n");
        printf("2 – Listar turmas\n");
        printf("3 – Matricular aluno\n");
        printf("4 – Lancar notas\n");
        printf("5 – Listar alunos\n");
        printf("6 – Sair\n");
        printf("Digite sua opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1': {
                if (num_turmas < MAX_TURMAS) {
                    char id;
                    printf("Criando nova turma...\n");
                    printf("Digite um id: ");
                    scanf(" %c", &id);
                    turmas[num_turmas++] = cria_turma(id);
                    printf("Turma %c criada com sucesso!\n", id);
                } else {
                    printf("Número máximo de turmas atingido.\n");
                }
                break;
            }
            case '2':
                printf("Listando turmas...\n");
                imprime_turmas(turmas, num_turmas);
                break;
            case '3': {
                char id;
                int mat;
                char nome[81];
                printf("Matriculando aluno...\n");
                printf("Digite o id da turma: ");
                scanf(" %c", &id);
                Turma *turma = procura_turma(turmas, num_turmas, id);
                if (turma != NULL) {
                    printf("Digite a matricula: ");
                    scanf("%d", &mat);
                    printf("Digite o nome: ");
                    scanf(" %[^\n]", nome);
                    matricula_aluno(turma, mat, nome);
                } else {
                    printf("Turma inexistente!\n");
                }
                break;
            }
            case '4': {
                char id;
                printf("Lancando notas...\n");
                printf("Digite o id da turma: ");
                scanf(" %c", &id);
                Turma *turma = procura_turma(turmas, num_turmas, id);
                lanca_notas(turma);
                break;
            }
            case '5': {
                char id;
                printf("Listando alunos...\n");
                printf("Digite o id da turma: ");
                scanf(" %c", &id);
                Turma *turma = procura_turma(turmas, num_turmas, id);
                imprime_alunos(turma);
                break;
            }
            case '6':
                printf("Obrigado por usar este programa!\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != '6');

    for (int i = 0; i < num_turmas; i++) {
        if (turmas[i] != NULL) {
            for (int j = 0; j < MAX_VAGAS; j++) {
                if (turmas[i]->alunos[j] != NULL) {
                    free(turmas[i]->alunos[j]);
                }
            }
            free(turmas[i]);
        }
    }

    return 0;
}
