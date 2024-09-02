#ifndef DICIPLINA_H
#define DICIPLINA_H

typedef struct diciplina Diciplina;

Diciplina *criar_diciplina(char nome_matricula[], int codigo);
void excluir_diciplina(Diciplina *diciplina);

#endif
