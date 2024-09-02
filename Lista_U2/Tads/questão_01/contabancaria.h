#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

//estrutura da conta//
typedef struct contabancaria Contabancaria;

//criar conta//
Contabancaria * criar_conta( const char * titular, long int numero, double saldo_incial);

//fazer o deposito//
void depositar(Contabancaria * conta, double valor);

//fazer o saque//
int sacar(Contabancaria * conta, double valor);

//fazer transfereção//
int traferir(Contabancaria *conta_origem, Contabancaria *conta_destino, double valor);

//vendo o saldo da conta//
double cosultar_saldo( const Contabancaria *conta);

//excluir a conta//
void excluir_conta(Contabancaria * conta);

#endif
