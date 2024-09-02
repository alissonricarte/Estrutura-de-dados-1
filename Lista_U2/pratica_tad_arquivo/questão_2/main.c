#include "produto.h"

int main() {
    Produto * produto;

    Produto*produto1 = criarProduto(101, "Cadeira", 15);
    adicionarProdutoAoEstoque("estoque.bin",produto1);
    

    Produto* produto2 = criarProduto(102, "Mesa", 8);
    adicionarProdutoAoEstoque("estoque.bin", produto2);

    exibirEstoque("estoque.bin");

    atualizarQuantidadeNoEstoque("estoque.bin", 101, 20);

    exibirEstoque("estoque.bin");

    removerProdutoDoEstoque("estoque.bin", 102);

    exibirEstoque("estoque.bin");

    return 0;
}