#include <stdio.h>
#include <stdlib.h>

int main(void){

    int linhas, colunas;
    int linha,coluna;

    printf("informe a quantidade de linhas e colunas da matriz:");
    scanf("%d%d",&linhas,&colunas);
    int ** matriz = ( int **) malloc(linhas * sizeof (int));
    if ( matriz == NULL){
        exit(1);
    }

    //verificar a matriz//
    for( int count = 0; count < linhas; count++){
        matriz[count] = (int *) malloc (colunas * sizeof(int));
        if( matriz[count] == NULL){
            exit(1);
        }
    }

    //ler os elementos//
    printf("infor os elementos:");
    for( linha = 0;linha < linhas;linha++){
        for (coluna = 0; coluna < colunas;coluna++){
            scanf("%d",&matriz[linha][coluna]);
        }
    }
    //imprimir matriz original//

    for (linha = 0; linha < linhas; linha++){
        printf("\n");
        for( coluna = 0; coluna < colunas;coluna++){
            printf("%d\t",matriz[linha][coluna]);
        }
    }
    printf("\n");

    //imprimir matriz transposta// 
    for (linha = 0; linha < linhas; linha++){
        printf("\n");
        for( coluna = 0; coluna < colunas;coluna++){
            printf("%d\t",matriz[coluna][linha]);
        }
    }
    printf("\n");

    //liberar matriz da memoria//
    for(linha = 0; linha < linhas; linha++){
        free(matriz[linha]);
    }
    free(matriz);
    return 0;
}
