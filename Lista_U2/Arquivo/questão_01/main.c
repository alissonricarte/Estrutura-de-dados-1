#include <stdio.h>
#include <stdlib.h>

FILE * open_file(char * nome,char * modo){
    FILE * arquivo = fopen(nome,modo);
    if(arquivo == NULL){
        printf("can't open the file\n");
        exit(1);
    }
    else{
        printf("file open!\n");
    }
    return arquivo;
}

int main(void){
    FILE * arq_entrada,  * arq_saida;
    arq_entrada = open_file("entrada_q3.txt","r");
    arq_saida = open_file("saida_q3.txt","w");
    char nome_aluno[30];
    float nota1,nota2,nota3,media;

    while(fscanf(arq_entrada, " %[^,] %f %f %f",&nome_aluno,&nota1,&nota2,&nota3) == 4){
        media = (nota1 + nota2 + nota3)/ 3;
        if(media >= 7){
            fprintf(arq_saida, "%s\t%.1f\tAprovado\n",nome_aluno,media);
        }
        else{
            fprintf(arq_saida, "%s\t%.1f\tAprovado\n",nome_aluno,media);
        }
    }
    fclose(arq_entrada);
    fclose(arq_saida);
    return 0;
}