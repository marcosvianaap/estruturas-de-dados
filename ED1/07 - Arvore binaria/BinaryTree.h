#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <cstddef>
#include "NoBinaryTree.h"

using namespace std;

class No {
public:
    NoBinaryTree info;
    No* sad;
    No* sae;
};

class BinaryTree {
private:
    No* raiz;
    
public:
    BinaryTree();
    ~BinaryTree();
    No* obterRaiz();
    bool vazia();
    bool isFull();
    void imprimeEmOrdem(No* Noatual, ostream& os);
    bool pertence(int valor, No* Noatual);
    int pares(No* Noatual);
    int folhas(No* Noatual);
    void insere(NoBinaryTree info);
    void imprimePre(No* Noatual);
    void imprimeSim(No* Noatual);
    void imprimePos(No* Noatual);
    int numNos(No* Noatual);
    int altura(No* Noatual);
    bool igual(NoBinaryTree* no_atual, BinaryTree& a);
    bool igual(No* raiz1, No* raiz2);
    
};

#endif /* BINARYTREE_H */
