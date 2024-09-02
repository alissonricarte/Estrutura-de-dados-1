// funcionario.h
#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[30];
    int id;
    float salario;
} Funcionario;

void adicionar_funcionario(Funcionario **funcionario);

void remove_funcionario(Funcionario **funcionario, int * num_funcionario, int id);

Funcionario * buscar_funcionario(Funcionario * funcionario, int baixo, int alto, int id);

void exebir_funcionario(Funcionario * funcionario, int num_funcionario);

void liberar_memoria(Funcionario * funcionario);

