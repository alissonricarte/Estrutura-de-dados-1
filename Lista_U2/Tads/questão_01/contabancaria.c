#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

typedef struct contabancaria{
    char titular[30];
    long int numero;
    double saldo;
} Contabancaria;

Contabancaria * criar_conta( const char * titular, long int numero, double saldo_incial){
    Contabancaria * conta = (Contabancaria*)malloc(sizeof(Contabancaria));
    if(conta != NULL){
        strncpy(conta->titular,titular,sizeof(conta->titular)-1);
        conta->titular[sizeof(conta->titular)-1] = '\0';
        conta->numero = numero;
        conta->saldo = saldo_incial;
    }
    return conta;
}
void depositar(Contabancaria * conta, double valor){
    if(conta != NULL){
        conta->saldo += valor;
    }
}
int sacar(Contabancaria * conta, double valor){
    if(conta != NULL && conta->saldo >= valor){
        conta->saldo -= valor;
        return 1;
    }
    return 0;
}
int traferir(Contabancaria *conta_origem, Contabancaria *conta_destino, double valor){
    if(conta_origem != NULL && conta_destino != NULL && sacar(conta_origem,valor)){
        depositar(conta_destino,valor);
        return 1;
    }
}
double cosultar_saldo( const Contabancaria *conta){
    if(conta != NULL){
        return conta->saldo;
    }
    return 0.0;
}
void excluir_conta(Contabancaria * conta){
    if(conta != NULL){
        free(conta);
    }
}
