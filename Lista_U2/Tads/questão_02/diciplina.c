#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diciplina.h"

typedef struct diciplina {
    char nome_matricula[100];
    int codigo;
} Diciplina;

Diciplina *criar_diciplina(char nome_matricula[], int codigo) {
    Diciplina *dicp = (Diciplina*)malloc(sizeof(Diciplina));
    if (dicp == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    strcpy(dicp->nome_matricula, nome_matricula);
    dicp->codigo = codigo;
    return dicp;
}

void excluir_diciplina(Diciplina *diciplina) {
    if (diciplina != NULL) {
        free(diciplina);
    }
}
