#include <stdio.h>
#include "funcionario.h"
int main(void){
    
    Funcionario *funcionario;
    int opcao;
    printf("==========================\n");
    printf("ESCOLHA!\n");
    printf("==========================\n");
    printf("1-adicionar funcionario\n");
    printf("2-remove funcionario\n");
    printf("3-buscar funcionario\n");
    printf("4-exibir todos funcionario\n");
    printf("==========================\n");
    printf("digite um valor:");
    scanf("%d",&opcao);
    switch (opcao)
    {
    case 1:
        adicionar_funcionario(&funcionario);
        break;
    case 2:
        int id_remove;
        printf("digite o id que quer remover:");
        scanf("%d",&id_remove);
        break;
    case 3:
        printf("a");
        break;
    case 4:
        printf("a");
        break;
    
    default:
        printf("valor não existente!\n");
        break;
    }
    return 0;
}