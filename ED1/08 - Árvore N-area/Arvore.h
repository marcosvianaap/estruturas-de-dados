#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "NoArvore.h"

using namespace std;

class Arvore{
private:
    NoArvore* raiz;
    int imprime(NoArvore* no);
    bool pertence(NoArvore* no, int info);
    int altura(NoArvore* no);
    int pares(NoArvore* no);
    int folha(NoArvore* no);
    bool igual(NoArvore* n1, NoArvore* n2);
    NoArvore* copia(NoArvore* no);

public:
    Arvore();
    ~Arvore();
    NoArvore* get_Raiz();
    void insereFilho(NoArvore* no, NoArvore* sa);
    bool pertence(int info);
    int altura();
    int pares();
    int folha();
    bool igual(Arvore& a);
    Arvore copia();
    void imprime();
};

#endif
