#include <stdio.h>

typedef union tipo{
    char alimento[20];
    char bebida[20];
    char eletronico[20];
}Tipo;

typedef struct produto{
    char nome[20];
    int tipo_produto;
    float preco;
    Tipo tipo;
}Produto;

void preencher_produto( Produto * produto){
    printf("Informe seu nome: \t");
    scanf(" %[^\n]");
    printf("Informe o tipo do produto:\n1-Alimento 2-Bebida 3-Eletrônico\n:");
    scanf("%d",&produto->tipo_produto);
    switch (produto->tipo_produto){
    case 1:
        printf("Qual foi o Alimento:\t\n");
        scanf(" %[^\n]",produto->tipo.alimento);
        break;
    case 2:
        printf("Qual foi a Bebida:\t\n");
        scanf(" %[^\n]",produto->tipo.bebida);
        break;
    case 3:
        printf("Qual foi o Eletrônico:\t\n");
        scanf(" %[^\n]",produto->tipo.eletronico);
        break;
    default:
        printf("Não existe esse produto na loja!\n");
        break;
    }
    printf("Informe o valor do produto:\t");
    scanf("%f",&produto->preco);

}

void mostrar_produto( Produto * produto){
    printf("NOME:%s",produto->nome);
    switch (produto->tipo_produto){
    case 1:
        printf("ALIMENTO:\t%s\n",produto->tipo.alimento);
        break;
    case 2:
        printf("BEBIDA:\t%s\n",produto->tipo.bebida);
        break;
    case 3:
        printf("ELETRÔNICO:\t%s\n",produto->tipo.eletronico);
        break;
    default:
        printf("Não existe esse produto na loja!\n");
        break;
    }
    printf("VALOR:\t%.2f\n",produto->preco);
}

int main(void){
    Produto produto;
    preencher_produto(&produto);
    mostrar_produto(&produto);
    return 0;
}