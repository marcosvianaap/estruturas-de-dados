#ifndef NOARVORE_H
#define NOARVORE_H

#include <iostream>

using namespace std;


class NoArvore{
private:
    int info;
    NoArvore* prim;
    NoArvore* prox;

public:
    NoArvore(int info){
        this->info = info;
        prim = nullptr;
        prox = nullptr;
    }

    void set_Info(int v){
        info = v;
    }

    int get_Info(){
        return info;
    }

    void set_Prim(NoArvore* p){
        prim = p;
    }

    NoArvore* get_Prim(){
        return prim;
    }

    void set_Prox(NoArvore* b){
        prox = b;
    }

    NoArvore* get_Prox(){
        return prox;
    }
};

#endif
