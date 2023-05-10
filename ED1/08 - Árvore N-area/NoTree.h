#ifndef NOARVORE_H
#define NOARVORE_H

#include <iostream>

using namespace std;


class NoArvore{
    private: 
        int info; //́e o dado armazenado no nó.
        NoArvore* prim; //́e uma refe. para o nó raiz da primeira sub-árvore filha do nó corrente.
        NoArvore* prox; //referência para o nó ra ́ız da sub-árvore “irmã”.


    public:
        NoArvore(int info);

        void set_Info(int v){
            info = v;
        }

        int get_Info(){
            return info;
        }

        void set_Prim(NoArvore* p){
            prim = p;
        }

        int get_Prim(){
            return prim;
        }

        void set_Prox(NoArvore* b);
            prox = b;

        int get_Prox();
            return prox;
};

#endif