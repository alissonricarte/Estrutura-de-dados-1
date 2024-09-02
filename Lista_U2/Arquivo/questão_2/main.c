#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_VETOR 10

void ler_vetor(FILE *arquivo, int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (fscanf(arquivo, "%d", &vetor[i]) != 1) {
            fprintf(stderr, "Erro ao ler o número %d do arquivo\n", i);
            exit(EXIT_FAILURE);
        }
    }
}

void escrever_resultados(FILE *arquivo, int menor, int maior, float media) {
    fprintf(arquivo, "Menor elemento: %d\n", menor);
    fprintf(arquivo, "Maior elemento: %d\n", maior);
    fprintf(arquivo, "Média dos elementos: %.2f\n", media);
}

int main(void) {
    FILE *arquivo_entrada = fopen("arquivo_entrada.txt", "r");
    if (arquivo_entrada == NULL) {
        perror("Erro ao abrir arquivo_entrada.txt");
        exit(EXIT_FAILURE);
    }

    FILE *arquivo_saida = fopen("arquivo_saida.txt", "w");
    if (arquivo_saida == NULL) {
        perror("Erro ao abrir arquivo_saida.txt");
        fclose(arquivo_entrada);
        exit(EXIT_FAILURE);
    }

    int vetor[TAMANHO_VETOR];
    ler_vetor(arquivo_entrada, vetor, TAMANHO_VETOR);

    fclose(arquivo_entrada);

    // Encontrar o menor e o maior elemento
    int menor = vetor[0];
    int maior = vetor[0];
    int soma = 0;

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        soma += vetor[i];
    }

    float media = (float)soma / TAMANHO_VETOR;

    escrever_resultados(arquivo_saida, menor, maior, media);

    fclose(arquivo_saida);

    return 0;
}
