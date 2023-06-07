#ifndef HASH_H
#define HASH_H

#include "aluno.h"
#include "node.h"

class Hash {
private:
    int max_itens;
    int max_posicoes;
    int quant_itens;
    Node** estrutura;

    int FuncaoHash(Aluno aluno);

public:
    Hash(int tam_vetor, int max);
    ~Hash();
    bool estacheio();
    int obterTamanhoAtual();
    void inserir(Aluno aluno);
    void deletar(Aluno aluno);
    void buscar(Aluno& aluno, bool& busca);
    void imprimir();
};

#endif  // HASH_H
