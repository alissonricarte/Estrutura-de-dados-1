#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

int main(void){
    int quant_pessoa;
    int *idade;
    char **nomes;

    printf("Informe o total de pessoas:\t");
    scanf("%d",&quant_pessoa);
    getchar(); 
    nomes = (char **)malloc(quant_pessoa * sizeof(char *));
    for (int i = 0; i < quant_pessoa; i++) {
        nomes[i] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    }
    idade = (int *)malloc(quant_pessoa * sizeof(int));
    for (int i = 0; i < quant_pessoa; i++) {
        printf("Digite o nome completo da pessoa %d: ", i + 1);
        fgets(nomes[i], MAX_NAME_LENGTH, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = 0;

        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &idade[i]);
        getchar(); 
    }
    printf("\nNomes armazenados:\n");
    for (int i = 0; i < quant_pessoa; i++) {
        printf("Pessoa %d: %s\n", i + 1, nomes[i]);
    }

    // Libera a memória alocada
    for (int i = 0; i < quant_pessoa; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idade);

    return 0;
}