#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAMANHO 999999

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int busca_linear(int *entrada, int tamanho)
{
    int maior = entrada[0];
    int cont;
    for (cont = 0; cont < tamanho; cont++)
    {
        if (maior < entrada[cont])
        {
            maior = entrada[cont];
        }
    }
    return maior;
}
int busca_binaria(int vet[], int maior, int tamanho)
{

    int inicio = 0, final = tamanho - 1;
    while (inicio <= final)
    {
        int meio = inicio + (final -inicio) / 2;
        if (vet[meio] == maior)
        {
            return vet[meio];
        }
        else if (vet[meio] < maior)
        {
            inicio = meio + 1;
        }
        else
        {
            final = meio - 1;
        }
    }
    return -1;
}
int main(void)
{
    int entrada[TAMANHO];
    int cont;
    for (cont = 0; cont < TAMANHO; cont++)
    {
        entrada[cont] = rand();
    }
    clock_t tempo_inicial = clock();

    int maior = busca_linear(entrada, TAMANHO);
    double tempo_final = (double)(clock() - tempo_inicial) / CLOCKS_PER_SEC;
    tempo_final = tempo_final * 1000;
    printf("maior elemento: %d\n tempo de exec: %.4f (ms)\n\n", maior, tempo_final);


    qsort(entrada, TAMANHO, sizeof(int), compare);
    clock_t tempo_inicial2 = clock();

    int maior2 = busca_binaria(entrada, maior, TAMANHO);
    double tempo_final2 = (double)(clock() - tempo_inicial2) / CLOCKS_PER_SEC;
    tempo_final = tempo_final * 1000;
    printf("maior elemento: %d\n tempo de exec: %.6f (ms)\n", maior2, tempo_final2);
    return 0;
}