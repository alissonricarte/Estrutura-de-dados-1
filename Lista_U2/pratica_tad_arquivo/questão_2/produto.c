#include "produto.h"


typedef struct produto{
    int codigo;
    char descricao[100];
    int quantidade;
} Produto;

Produto *criarProduto(int codigo, const char* descricao, int quantidade) {
    Produto* p;
    p->codigo = codigo;
    strncpy(p->descricao, descricao, sizeof(p->descricao) - 1);
    p->descricao[sizeof(p->descricao) - 1] = '\0'; 
    p->quantidade = quantidade;
    return p;
}

void adicionarProdutoAoEstoque(const char* nomeArquivo, Produto* produto) {
    FILE* arquivo = fopen(nomeArquivo, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fwrite(&produto, sizeof(Produto), 1, arquivo);
    fclose(arquivo);
}

void removerProdutoDoEstoque(const char* nomeArquivo, int codigo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    FILE* temp = fopen("temp.bin", "wb");
    Produto p;
    int encontrado = 0;

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(&p, sizeof(Produto), 1, arquivo)) {
        if (p.codigo == codigo) {
            encontrado = 1;
        } else {
            fwrite(&p, sizeof(Produto), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(nomeArquivo);
    rename("temp.bin", nomeArquivo);

    if (encontrado) {
        printf("Produto removido com sucesso.\n");
    } else {
        printf("Produto com código %d não encontrado.\n", codigo);
    }
}

void atualizarQuantidadeNoEstoque(const char* nomeArquivo, int codigo, int novaQuantidade) {
    FILE* arquivo = fopen(nomeArquivo, "r+b");
    Produto p;
    int encontrado = 0;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(&p, sizeof(Produto), 1, arquivo)) {
        if (p.codigo == codigo) {
            p.quantidade = novaQuantidade;
            fseek(arquivo, -sizeof(Produto), SEEK_CUR);
            fwrite(&p, sizeof(Produto), 1, arquivo);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (encontrado) {
        printf("Quantidade atualizada com sucesso.\n");
    } else {
        printf("Produto com código %d não encontrado.\n", codigo);
    }
}

void exibirEstoque(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    Produto p;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Estoque:\n");
    printf("------------------------------------------\n");
    printf("Código | Descrição              | Quantidade\n");
    printf("------------------------------------------\n");

    while (fread(&p, sizeof(Produto), 1, arquivo)) {
        printf("%6d | %-20s | %10d\n", p.codigo, p.descricao, p.quantidade);
    }

    fclose(arquivo);
}
