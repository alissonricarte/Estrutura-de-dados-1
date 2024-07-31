#include <stdio.h>
#include <stdlib.h>

//função para verificar se tem memoria//
void ver_se_tem_memoria(int **numero, int n);
void ver_se_tem_memoria(int **numero, int n){
    *numero = malloc ( n * sizeof (int));
    if( numero == NULL){
        printf("não existe memoria bastante!");
        exit(1);
    }
}

//função para ler os numeros//
void informar(int *numero, int n);
void informar(int *numero, int n){
    int i;
    printf("===digite os valores:===\n");
    for(i = 0; i < n; i++){
        printf("digite o numero %d:\n",i + 1);
        scanf("%d",&numero[i]);
    }
}

//mostrar os numeros digitados inveros//
void mostrar(int *numero, int n);
void mostrar(int *numero, int n){
    int i;
    printf("===mostrar o valor inverso===\n");
    for( i = n-1;i >= 0; i--){
        printf("%d ",numero[i]);
    }
    printf("\n");
}

int main(void){
    int *numero;
    int n;
    printf("digite o valor do vetor: ");
    scanf("%d",&n);
    ver_se_tem_memoria(&numero,n);
    informar(numero,n);
    mostrar(numero,n);
    free(numero);
    return 0;
}