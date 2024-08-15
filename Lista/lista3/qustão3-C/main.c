#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int numero;
    int linhas, colunas;
    int linha, coluna;

    srand(time(0));

    printf("digite um valor X:");
    scanf("%d",&numero);
    colunas = numero;
    linhas = numero;
    int **matriz = (int**) malloc(linhas * sizeof(int));
    if( matriz == NULL){
        printf("memoria insuficente!");
        exit(1);
    }

    for ( int cont = 0; cont < linhas; cont++){
        matriz[cont] = (int *) malloc(colunas * sizeof(int));
        if (matriz[cont] == NULL){
            printf("memoria insufucente!");
            exit(1);
        }
    }

    for(linha = 0; linha < linhas; linha++){
        for( coluna = 0; coluna < colunas; coluna++){
            matriz[linha][coluna] = rand() % 100 + 1;
        }
    }

    for( linha = 0; linha < linhas; linha++){
        for( coluna = 0; coluna < colunas; coluna++){
            printf("%d\t",matriz[linha][coluna]);
        }
        printf("\n");
    }
    return 0;
}