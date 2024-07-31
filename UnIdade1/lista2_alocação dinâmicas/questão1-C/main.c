#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num_pessoa;
    printf("Informe a quantidade de pessoas:\t");
    scanf("%d",&num_pessoa);
    char *sexo =(char*)malloc(num_pessoa * sizeof(char));
    char *opniao = (char*)malloc(num_pessoa * sizeof(char));
    if ( sexo == NULL || opniao == NULL){
        printf("não existe memoria sufuciente!");
        exit(1);
    }
    int total_feminino = 0, total_masculino = 0;
    int gostaram_feminino = 0,nao_gostaram_masculino = 0;
    for( int i = 0; i < num_pessoa; i++){
        printf("%d-Informe seu sexo[M/F]:\t",i + 1);
        scanf(" %c",&sexo[i]);
        printf("%d-Informe se gostaram[S/N]:\t",i + 1);
        scanf(" %c",&opniao[i]);
        if (sexo[i] == 'F' || sexo[i] == 'f'){
            total_feminino++;
            if(opniao[i] == 'S' || opniao[i] == 's'){
                gostaram_feminino++;
            }
        }
        else if (sexo[i] == 'M' || sexo[i] == 'm'){
            total_masculino++;
            if(opniao[i] == 'N' || opniao[i] == 'n'){
                nao_gostaram_masculino++;
            }
        }
        printf("===================================\n");
    }
    float porcentagem_gostaram_f = 0;
    float porcentagem_nao_gostaram_m = 0;
    if(total_feminino > 0){
        porcentagem_gostaram_f = (gostaram_feminino / (float)total_feminino) * 100;
    }
    if(total_masculino > 0){
        porcentagem_nao_gostaram_m = (nao_gostaram_masculino / (float)total_masculino) * 100;
    }
    printf("porcetagem de sexo feminino que gostaram: %.2f\n",porcentagem_gostaram_f);
    printf("porcetagem de sexo masculino que não gostaram: %.2f\n",porcentagem_nao_gostaram_m);;
    free(sexo);
    free(opniao);
    return 0;
}