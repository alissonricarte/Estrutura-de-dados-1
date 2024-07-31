#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario{
    char nome[20];
    float salario;
    long int indetificador;
    char cargo[20];
}Funcionario;

//preenche os dados do fucionario//
void preenche( Funcionario * servidor);
void preenche( Funcionario * servidor){
    printf("digite o nome:\t");
    scanf(" %[^\n]", servidor -> nome);
    printf("digite o valor do seu salario: \t");
    scanf("%f",&servidor -> salario);
    printf("digite seu indetificador:\t");
    scanf("%ld",&servidor -> indetificador);
    printf("digite seu  cargo: \t");
    scanf(" %[^\n]",servidor -> cargo);
    printf("============================\n");
}

void mostrar( Funcionario * servidor);
void mostrar( Funcionario * servidor){
    printf("mostrar os valores\n");
    printf("nome: %s\n",servidor -> nome);
    printf("salario:%.2f\n",servidor -> salario);
    printf("indetificador: %ld\n",servidor -> indetificador);
    printf("cargo: %s\n", servidor -> cargo);
    printf("============================\n");
}
void atualizar_salario( Funcionario * funcionario);
void atualizar_salario( Funcionario * funcionario){
    printf("Informe o novo salario:\n");
    scanf("%f",&funcionario->salario);
    printf("============================\n");

}
int main(void){
    int cont, quantidade_fucionario;
    Funcionario *funcionario;
    printf("Quantos funcionario tem na empresa:");
    scanf("%d",&quantidade_fucionario);

    funcionario = malloc(quantidade_fucionario * sizeof(int));
    if( funcionario == NULL){
        printf("memoria insuficiente!");
        exit(1);
    }
    for( cont = 0; cont < quantidade_fucionario;cont++){
        preenche(&funcionario[cont]);
        atualizar_salario(&funcionario[cont]);
        mostrar(&funcionario[cont]);
    }
    
    return 0;
}