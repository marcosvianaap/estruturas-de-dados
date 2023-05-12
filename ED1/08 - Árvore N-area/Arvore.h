#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "NoArvore.h"

using namespace std;

class Arvore{
private:
    NoArvore* raiz;
    bool pertence(NoArvore* no, int info);
    int altura(NoArvore* no);
    int pares(NoArvore* no);
    int folha(NoArvore* no);

public:
    Arvore();
    ~Arvore();
    NoArvore* get_Raiz();
    void set_Raiz(NoArvore* novo);
    NoArvore* criaNo(int info);
    void insereFilho(NoArvore* no, NoArvore* sa);
    bool pertence(int info);
    int altura();
    int pares();
    int folha();
    bool igual(NoArvore* n1, NoArvore* n2);
    NoArvore* copia(NoArvore* no);
    int imprime(NoArvore* no);
};

#endif
