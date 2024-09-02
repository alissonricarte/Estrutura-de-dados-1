#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

int compare(const void * a, const void * b){
    return (*(int*) a - *(int*)b);
}
void adicionar_funcionario( Funcionario **funcionario){
    char opcao;
    int numpessoa = 0;
    int capacidade = 2;

    *funcionario = (Funcionario*) malloc(capacidade * sizeof(Funcionario));
    if (*funcionario == NULL){
        printf("não existe memoria!\n");
        exit(1);
    }
    
    do{
        if (numpessoa == capacidade)
        {
            capacidade *= 2;
            *funcionario = (Funcionario*)realloc(*funcionario, capacidade * sizeof(Funcionario));
            if(*funcionario == NULL){
              printf("não existe memoria!\n");
              exit(1);
            }
        }
        printf("==========================\n");
        printf("Informe seu nome: ");
        scanf(" %[^\n]",funcionario[numpessoa]->nome);
        printf("informe um id: ");
        scanf("%d",&funcionario[numpessoa]->id);
        printf("informe seu salario: ");
        scanf("%f",&funcionario[numpessoa]->salario);
        printf("==========================\n");

        numpessoa++;
        printf("deseja adicionar mais funcionario(s/n):");
        scanf("%s",&opcao);
    }while(opcao == 's' || opcao == 'S');
}

void remove_funcionario(Funcionario **funcionario, int * num_funcionario, int id){
    int i,j;
    int entrada = 0;

    for(i = 0; i < *num_funcionario;i++){
        if((*funcionario)[i].id == id){
            entrada = 1;
        }
    
    for(j = 0; j < (*num_funcionario)-1;j++){
        (num_funcionario)[j] = (num_funcionario)[j + 1];
    }

        (*num_funcionario)--;
    
    *funcionario = (Funcionario*) realloc(*funcionario,(*num_funcionario)* sizeof(Funcionario));
    if(*funcionario == NULL && *num_funcionario > 0){
        printf("erro!");
        exit(1);
    }
    break;
    }

    if(!entrada){
        printf("usuario com id %d não encontrado!\n",id);
    }
}

Funcionario * buscar_funcionario(Funcionario * funcionario, int baixo, int alto, int id){
    while ( baixo <= alto){
        int meio = baixo + (alto - baixo)/2; 

        if(funcionario[meio].id == id){
            return &funcionario[meio];
        }
        
        else if(funcionario[meio].id < id){
            return &funcionario[meio] + 1;
        }

        else{
            return &funcionario[meio] - 1;
        }

    }
}

void exebir_funcionario(Funcionario * funcionario, int num_funcionario){
    for(int cont = 0; cont < num_funcionario; cont++){
        printf("ID:%d,Nome:%s\n",funcionario[cont].id,funcionario[cont].nome);
    }
}
void liberar_memoria(Funcionario * funcionario){
    free(funcionario);
}
