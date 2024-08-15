#include <stdio.h>
#include <stdlib.h>

char **mapa;  // Ponteiro para ponteiro que armazenará o mapa dinamicamente
int M, N;     // Dimensões do mapa: M linhas e N colunas

int is_coast(int x, int y) {
    if (mapa[x][y] != '#') return 0;
    // Verifica se há água ao redor
    if (x > 0 && mapa[x-1][y] == '.') return 1;       // acima
    if (x < M-1 && mapa[x+1][y] == '.') return 1;     // abaixo
    if (y > 0 && mapa[x][y-1] == '.') return 1;       // esquerda
    if (y < N-1 && mapa[x][y+1] == '.') return 1;     // direita
    // Verifica se há água nas bordas do mapa (considerando fora do mapa como água)
    if (x == 0 || x == M-1 || y == 0 || y == N-1) return 1;
    return 0;
}

int main() {
    printf("Informe a quantidade de linha e colunas:");
    scanf("%d %d", &M, &N);
    
    // Aloca memória para as linhas do mapa
    mapa = (char **)malloc(M * sizeof(char *));
    if (mapa == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    
    // Aloca memória para cada linha do mapa
    for (int i = 0; i < M; i++) {
        mapa[i] = (char *)malloc((N + 1) * sizeof(char)); // N+1 para incluir o caractere nulo
        if (mapa[i] == NULL) {
            printf("Erro ao alocar memória\n");
            exit(1);
        }
    }

    for (int i = 0; i < M; i++) {
        printf("Marca linhas e colunas do mapa:\n");
        scanf("%s", mapa[i]);
    }

    int coast_length = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (is_coast(i, j)) {
                coast_length++;
            }
        }
    }

    printf("%d\n", coast_length);

    // Libera a memória alocada
    for (int i = 0; i < M; i++) {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}
