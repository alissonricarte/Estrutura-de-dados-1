#include <stdio.h>

typedef enum genero{
    masculino=1,
    feminino,
    neutro
}Genero;

typedef struct pessoa{
    char nome[25];
    int idade;
    Genero genero;
}Pessoa;

void preenche_dados( Pessoa * pessoa){
    printf("Informe seu nome:\t");
    scanf(" %[^\n]",pessoa->nome);
    printf("Informe sua idade:\t");
    scanf("%d",&(pessoa->idade));
    printf("Informe seu sexo:\n1-Masculino 2-Feminino 3-Neutro\n:");
    scanf("%d",&(pessoa->genero));
}
void mostrar_dados( Pessoa * pessoa){
    printf("NOME:\t%s\n",pessoa->nome);
    printf("IDADE:\t%d\n",pessoa->idade);
    switch (pessoa->genero){
    case masculino:
       printf("Gênero:\tmasculino\n");
       break;
    case feminino:
       printf("Gênero:\tfeminino\n");
       break;
    case neutro:
       printf("Gênero:\tneutro\n");
       break;
    default:
       printf("Gênero invalido!\n");
        break;
    }
}

int main(void){
    Pessoa pessoa;
    preenche_dados(&pessoa);
    mostrar_dados(&pessoa);
    return 0;
}