#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto Produto;

Produto * criarProduto(int codigo, const char* descricao, int quantidade);

void adicionarProdutoAoEstoque(const char* nomeArquivo, Produto * produto);

void removerProdutoDoEstoque(const char* nomeArquivo, int codigo);

void atualizarQuantidadeNoEstoque(const char* nomeArquivo, int codigo, int novaQuantidade);

void exibirEstoque(const char* nomeArquivo);