#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.c"
#include "diciplina.c"

int main(void) {
    Aluno *aluno;
    char nome_disciplina[100];
    int codigo;
    int quantidade_aluno;

    printf("Quantidade de aluno: ");
    scanf(" %d",&quantidade_aluno);
    aluno = (Aluno*)malloc(quantidade_aluno * sizeof(int));
    if(aluno == NULL){
        printf("erro de alocação!\n");
        exit(1);
    }
    for(int cont = 0; cont < quantidade_aluno;cont++){
        printf("informe o seu nome:");
        scanf(" %[^\n]",aluno->nome);
        printf("informe sua matricula: ");
        scanf("%d",&aluno->matricula);

        printf("Quantidade de disciplinas: ");
       scanf("%d", &aluno->num_disciplina);

    if (aluno->num_disciplina > 10) {
        printf("O valor máximo de disciplinas é 10!\n");
        excluir_aluno(aluno);
        return 1;
    }
    
    for (int cont = 0; cont < aluno->num_disciplina; cont++) {
        aluno->disciplina[cont] = (Diciplina*)malloc(sizeof(Diciplina));
        if (aluno->disciplina[cont] == NULL) {
            printf("Erro de alocação para disciplina!\n");
            exit(1);
        }

        printf("Informe a %dª disciplina: ", cont + 1);
        scanf(" %[^\n]", nome_disciplina); // Corrigido para ler a string corretamente
        printf("Informe o código: ");
        scanf("%d", &codigo);

        aluno->disciplina[cont] = criar_diciplina(nome_disciplina, codigo);
    }

    for (int cont = 0; cont < aluno->num_disciplina; cont++) {
        excluir_diciplina(aluno->disciplina[cont]);
    }

    }
    excluir_aluno(aluno);

    return 0;
}
