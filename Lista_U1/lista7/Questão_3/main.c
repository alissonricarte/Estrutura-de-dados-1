#include <stdio.h>

typedef enum mes_ano{
    janeiro=1,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
}Mes;
typedef struct data{
    int dia;
    Mes mes_ano;
    int ano;
}Data;

void preencher_data( Data * data){
    printf("Informe o dia:\t");
    scanf("%d",&data->dia);
    printf("Informe o mes:\t");
    scanf("%d",&data->mes_ano);
    printf("Informe o ano:\t");
    scanf("%d",&data->ano);
}
void mostrar_data( Data * data){
    printf("%s%d/%s%d/%d",data->dia < 10 ? "0" : "", data->dia,data->mes_ano < 10 ? "0" : "",data->mes_ano,data->ano);
}

int main(void){
    Data data;
    preencher_data(&data);
    mostrar_data(&data);
    return 0;
}