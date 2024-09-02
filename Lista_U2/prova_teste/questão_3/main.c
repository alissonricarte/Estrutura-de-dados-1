#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE * arq;
    arq = fopen("resultados.txt","w");
    if(arq == NULL){
        printf("arquivo não encontrado\n");
        exit(1);
    }
    
    return 0;
}