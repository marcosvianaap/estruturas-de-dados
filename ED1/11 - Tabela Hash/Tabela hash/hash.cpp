#include <iostream>
#include "hash.h"
#include "ehPrimo.h"



Hash::Hash(int tam_vetor, int max) {
    quant_itens = 0;
    max_itens = max;
    max_posicoes = proximoPrimo(tam_vetor);
    estrutura = new Node*[max_posicoes];
    for (int i = 0; i < max_posicoes; i++) {
        estrutura[i] = nullptr;
    }
}

Hash::~Hash() {
    for (int i = 0; i < max_posicoes; i++) {
        Node* atual = estrutura[i];
        while (atual != nullptr) {
            Node* proximo = atual->obterProximo();
            delete atual;
            atual = proximo;
        }
    }
    delete[] estrutura;
}

int Hash::FuncaoHash(Aluno aluno) {
    int ra = aluno.obterRa();
    int posicao = ra % max_posicoes;
    if (posicao < 0) {
        posicao += max_posicoes;
    }
    return posicao;
}

void Hash::inserir(Aluno aluno) {
    int local = FuncaoHash(aluno);
    Node* novoNo = new Node(aluno);
    if (estrutura[local] == nullptr) {
        estrutura[local] = novoNo;
    } else {
        Node* atual = estrutura[local];
        while (atual->obterProximo() != nullptr) {
            atual = atual->obterProximo();
        }
        atual->definirProximo(novoNo);
    }
    quant_itens++;
}

void Hash::deletar(Aluno aluno) {
    int local = FuncaoHash(aluno);
    Node* atual = estrutura[local];
    Node* anterior = nullptr;
    while (atual != nullptr) {
        if (atual->obterAluno().obterRa() == aluno.obterRa()) {
            if (anterior == nullptr) {
                estrutura[local] = atual->obterProximo();
            } else {
                anterior->definirProximo(atual->obterProximo());
            }
            delete atual;
            quant_itens--;
            return;
        }
        anterior = atual;
        atual = atual->obterProximo();
    }
}

void Hash::buscar(Aluno& aluno, bool& busca) {
    int local = FuncaoHash(aluno);
    Node* atual = estrutura[local];
    while (atual != nullptr) {
        if (atual->obterAluno().obterRa() == aluno.obterRa()) {
            busca = true;
            aluno = atual->obterAluno();
            return;
        }
        atual = atual->obterProximo();
    }
    busca = false;
}

void Hash::imprimir() {
    std::cout << "Tabela Hash:\n";
    for (int i = 0; i < max_posicoes; i++) {
        Node* atual = estrutura[i];
        while (atual != nullptr) {
            std::cout << i << ":" << atual->obterAluno().obterRa() << " ";
            std::cout << atual->obterAluno().obterNome() << std::endl;
            atual = atual->obterProximo();
        }
    }
}
