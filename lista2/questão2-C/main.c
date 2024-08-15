#include <stdio.h>
#include <stdlib.h>

#define NUM_ALUNO 10
#define NOTA_MININA_APROVACAO   6.0

int main(void){
    int quant_questoes;
    char *gabarito;
    char *respostas;
    float *notas;
    int i, j;
    int quant_aprovados = 0;
    float pontuacao_questao;

    printf("Informe a quantidade de questão:\t");
    scanf("%d",&quant_questoes);
    gabarito = (char *)malloc(quant_questoes * sizeof(char));
    if(gabarito == NULL){
        printf("memoria insuficiente!");
        exit(1);
    }

    printf("Informe o gabarito:");
    for(i = 0; i < quant_questoes; i++){
        scanf(" %c",&gabarito[i]);
    }
    respostas = (char *) malloc(NUM_ALUNO * quant_questoes * sizeof(char));
    if( respostas == NULL){
        printf("mmemoria insuficiente!");
        free(gabarito);
        exit(1);
    }
    for (i = 0; i < NUM_ALUNO; i++) {
        printf("Digite as respostas do aluno %d:\n", i + 1);
        for (j = 0; j < quant_questoes; j++) {
            scanf(" %c", &respostas[i * quant_questoes + j]);
        }
    }
    notas = (float *)malloc(NUM_ALUNO * sizeof(float));
    if (notas == NULL) {
        printf("Erro ao alocar memória para as notas.\n");
        free(respostas);
        free(gabarito);
        return 1;
    }
    pontuacao_questao = 10.0 / quant_questoes;
    for (i = 0; i < NUM_ALUNO; i++) {
        notas[i] = 0;
        for (j = 0; j < quant_questoes; j++) {
            if (respostas[i * quant_questoes + j] == gabarito[j]) {
                notas[i] += pontuacao_questao;
            }
        }
        if (notas[i] >= NOTA_MININA_APROVACAO) {
            quant_aprovados++;
        }
    }
    for (i = 0; i < NUM_ALUNO; i++) {
        printf("Nota do aluno %d: %.2f\n", i + 1, notas[i]);
    }
    printf("Porcentagem de aprovação: %.2f%%\n", (quant_aprovados / (float)NUM_ALUNO) * 100);
    free(respostas);
    free(gabarito);
    free(notas);

    return 0;
}