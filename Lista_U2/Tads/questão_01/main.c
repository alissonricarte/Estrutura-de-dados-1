#include <stdio.h>
#include "contabancaria.h"

int main() {
    
    Contabancaria *conta1 = criar_conta("Alisson", 12345, 1000.0);
    Contabancaria *conta2 = criar_conta("joão", 67890, 500.0);

    depositar(conta1, 200.0);
    printf("Saldo de Alisson após depósito: %.2f\n", cosultar_saldo(conta1));

    if (sacar(conta2, 100.0)) {
        printf("joão sacou 100. Saldo atual: %.2f\n", cosultar_saldo(conta2));
    } else {
        printf("joão tentou sacar 100, mas o saldo era insuficiente.\n");
    }

    // Transferir dinheiro de Alice para Bob
    if (traferir(conta1, conta2, 300.0)) {
        printf("Transferência de Alisson para joão concluída.\n");
        printf("Saldo de Alisson: %.2f\n", cosultar_saldo(conta1));
        printf("Saldo de joão: %.2f\n", cosultar_saldo(conta2));
    } else {
        printf("Falha na transferência de Alice para joão.\n");
    }

    // Excluir as contas
    excluir_conta(conta1);
    excluir_conta(conta2);

    return 0;
}
