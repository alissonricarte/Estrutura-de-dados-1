#include "aluno.h"

struct aluno1{
    int matricula;
    char nome[20];
    float media;
};

Aluno * criarAluno( int matricula, char nome[], float media){
    Aluno *aluno1 = malloc(sizeof(Aluno));
    aluno1->matricula = matricula;
    aluno1->media = media;
    strcpy(aluno1->nome, nome);
    return aluno1;
}

void salvarAlunoEmArquivo( char nome_do_arquivo[], Aluno* aluno1){
    FILE *arq = fopen(nome_do_arquivo, "a");
    if (arq == NULL){
        printf("erro ao abrir o arquivo\n");
        return;
    }
    fprintf(arq, "%d\t%s\t%f\n",aluno1->matricula,aluno1->nome,aluno1->media);
    fclose(arq);
}

void exibirAlunos(char nome_do_arquivo[]){
    Aluno aluno1;
    int cont = 1;
    FILE *arq = fopen(nome_do_arquivo, "r");
    if( arq == NULL){
        printf("erro ao abrir o arquivo");
        return;
    }
    while( fscanf(arq, "%d\t%[^\t]\t%f\n",&aluno1.matricula,aluno1.nome,&aluno1.media) != EOF){
        printf("Aluno %d: %d\t%s\t%.2f\n",cont,aluno1.matricula,aluno1.nome,aluno1.media);
        cont++;
    }
    fclose(arq);
}