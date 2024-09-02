#include "aluno.h"

int main(){
    Aluno *aluno1 = criarAluno(777, "pedro" , 7.5);
    salvarAlunoEmArquivo("aluno.txt",aluno1);
    exibirAlunos("aluno.txt");
    return 0;
}