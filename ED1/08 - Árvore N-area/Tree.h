#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <NoTree.h>

using namespace std;

class Arvore{

    private:
        NoArvore* raiz;
        int imprime(NoArvore* no);
        bool pertence(NoArvore*, int info);
        int altura(NoArvore* no);

    public:
        Arvore();
        ~Arvore();
        void Arvore();
        NoArvore* criaNo(int info);
        void insereFilho(NoArvore* no, NoArvore* sa);
        bool pertence(int info);
        int altura();
        int pares();
        int folha();
        bool igual(Arvore a);
        Arvore copia();

}

#endif