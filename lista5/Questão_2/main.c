#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    char nome[25];
    long int documento;
    int idade;
}Pessoa;

void preencher( Pessoa * pessoa);
void preencher( Pessoa * pessoa){
    printf("digite seu nome:\t");
    scanf(" %[^\n]",pessoa->nome);
    printf("digite seu documento:\t");
    scanf("%ld",&pessoa->documento);
    printf("digite sua idade:\t");
    scanf("%d",&pessoa->idade);
}

void mostrar( Pessoa * pessoa);
void mostrar( Pessoa * pessoa){
    printf("=======================\n");  
    printf("NOME:\t%s\n",pessoa->nome);
    printf("DOCUMENTO:\t%ld\n",pessoa->documento);
    printf("IDADE:\t%d\n",pessoa->idade);
    printf("=======================\n");  
}

void atualizar_idade( Pessoa * pessoa);
void atualizar_idade( Pessoa * pessoa){
    printf("digite a nova idade:\t");
    scanf("%d",&pessoa->idade);
}

void mostrar_idade_atualizada( Pessoa * pessoa);
void mostrar_idade_atualizada( Pessoa * pessoa){
    printf("\nIDADE ATUALIZADA:\n");
    printf("NOME:\t%s\n",pessoa->nome);
    printf("DOCUMENTO:\t%ld\n",pessoa->documento);
    printf("IDADE:\t%d\n",pessoa->idade);
}

void maior_menor( Pessoa * pessoa, int quant);
void maior_menor( Pessoa * pessoa, int quant){
    if ( quant ==  0) return;
    Pessoa *maior = &pessoa[0];
    Pessoa *menor = &pessoa[0];
    for (int i = 1; i < quant; i++) {
        if (pessoa[i].idade > maior->idade) {
            maior = &pessoa[i];
        }
        if (pessoa[i].idade < menor->idade) {
            menor = &pessoa[i];
        }
    }

    printf("Maior idade:\n");
    mostrar(maior);

    printf("Menor idade:\n");
    mostrar(menor);
}

int main(void){
    int cont,quant_pessoa;
    Pessoa *pessoa;
    printf("quantas pessoas são:\t");
    scanf("%d",&quant_pessoa);
    pessoa = malloc( quant_pessoa * sizeof(Pessoa));
    if(pessoa == NULL){
        printf("menoria insuficente!");
        exit(1);
    }
    for(cont = 0; cont < quant_pessoa; cont++){
        preencher(&pessoa[cont]);
        mostrar(&pessoa[cont]);
        atualizar_idade(&pessoa[cont]);
        mostrar_idade_atualizada(&pessoa[cont]);
    }
    maior_menor(pessoa,quant_pessoa);
    return 0;
}