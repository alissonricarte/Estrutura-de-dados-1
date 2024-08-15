#include <stdio.h>
#include <stdlib.h>

//verificar a matriz//
void verificar(int linhas,int colunas,int **matriz);
void verificar(int linhas,int colunas,int **matriz){
    for( int count = 0; count < linhas; count++){
        matriz[count] = (int *) malloc (colunas * sizeof(int));
        if( matriz[count] == NULL){
            exit(1);
        }
    }
}
//ler os elementos//
void lerelementos(int linha, int linhas,int coluna,int colunas,int **matriz);
void lerelementos(int linha, int linhas,int coluna,int colunas,int **matriz){
    printf("informa os elementos:\n");
    for( linha = 0;linha < linhas;linha++){
        for (coluna = 0; coluna < colunas;coluna++){
            scanf("%d",&matriz[linha][coluna]);
        }
    }
}
//imprimir os valores original//
void imprimir_org(int linha, int linhas,int coluna, int colunas, int **matriz);
void imprimir_org(int linha, int linhas,int coluna, int colunas, int **matriz){
    printf("mostrar os valores original");
    for (linha = 0; linha < linhas; linha++){
        printf("\n");
        for( coluna = 0; coluna < colunas;coluna++){
            printf("%d\t",matriz[linha][coluna]);
        }
    }
    printf("\n");

}
//imprimir matriz transposta// 
void imprimir_trans(int linha, int linhas,int coluna,int colunas, int **matriz);
void imprimir_trans(int linha, int linhas,int coluna,int colunas, int **matriz){
    printf("mostrar os valores transposta");
    for (linha = 0; linha < linhas; linha++){
        printf("\n");
        for( coluna = 0; coluna < colunas;coluna++){
            printf("%d\t",matriz[coluna][linha]);
        }
    }
    printf("\n");

}
//liberar matriz da memoria//
void liberar_memoria(int linha, int colunas, int **matriz);
void liberar_memoria(int linha, int linhas, int **matriz){
    for(linha = 0; linha < linhas; linha++){
        free(matriz[linha]);
    }
    free(matriz);
}
int main(void){

    int linhas, colunas;
    int linha,coluna;

    printf("informe a quantidade de linhas e colunas da matriz:\n");
    scanf("%d%d",&linhas,&colunas);
    int ** matriz = ( int **) malloc(linhas * sizeof (int));
    if ( matriz == NULL){
        exit(1);
    }
    //verificar a matriz//
    verificar(linhas,colunas,matriz);
    //ler os elementos//
    lerelementos(linha,linhas,coluna,colunas,matriz);
    //imprimir matriz original//
    imprimir_org(linha,linhas,coluna,colunas,matriz);
    //imprimir matriz transposta// 
    imprimir_trans(linha,linhas,coluna,colunas,matriz);
    //liberar matriz da memoria//
    liberar_memoria(linha,linhas,matriz);

    return 0;
}
