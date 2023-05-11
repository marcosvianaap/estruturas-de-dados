#include <iostream>
#include "Arvore.h"
#include "NoArvore.h"

using namespace std;

Arvore::Arvore() {
    raiz = NULL;
}

Arvore::~Arvore() {
    delete raiz;
}

NoArvore* Arvore::get_Raiz() { 
    return raiz; 
}

NoArvore* criaNo(int info){
    NoArvore* novo = new NoArvore(info);
    novo->set_Prim(nullptr);
    novo->set_Prox(nullptr);
    return novo;
}

void Arvore::insereFilho(NoArvore* no, NoArvore* sa) {
    if (no->get_Prim() == nullptr) {
        no->set_Prim(sa);
    }
    else {
        NoArvore* aux = no->get_Prim();
        while (aux->get_Prox() != nullptr) {
            aux = aux->get_Prox();
        }
        aux->set_Prox(sa);
    }
}

int Arvore::imprime(NoArvore* no) {
    if (no == nullptr) {
        return 0;
    }
    cout << no->get_Info() << " ";
    int cont = 1;
    NoArvore* aux = no->get_Prim();
    while (aux != nullptr) {
        cont += imprime(aux);
        aux = aux->get_Prox();
    }
    return cont;
}

bool Arvore::pertence(int info) {
    return pertence(raiz, info);
}

bool Arvore::pertence(NoArvore* no, int info) {
    if (no == nullptr) {
        return false;
    }
    if (no->get_Info() == info) {
        return true;
    }
    NoArvore* aux = no->get_Prim();
    while (aux != nullptr) {
        if (pertence(aux, info)) {
            return true;
        }
        aux = aux->get_Prox();
    }
    return false;
}

int Arvore::altura() {
    return altura(raiz);
}

int Arvore::altura(NoArvore* no) {
    if (no == nullptr) {
        return -1;
    }
    int hmax = -1;
    NoArvore* aux = no->get_Prim();
    while (aux != nullptr) {
        int h = altura(aux);
        if (h > hmax) {
            hmax = h;
        }
        aux = aux->get_Prox();
    }
    return hmax + 1;
}

int Arvore::pares() {
    return pares(raiz);
}

int Arvore::pares(NoArvore* no) {
    if (no == nullptr) {
        return 0;
    }
    int cont = 0;
    if (no->get_Info() % 2 == 0) {
        cont++;
    }
    NoArvore* aux = no->get_Prim();
    while (aux != nullptr) {
        cont += pares(aux);
        aux = aux->get_Prox();
    }
    return cont;
}

int Arvore::folha() {
    return folha(raiz);
}

int Arvore::folha(NoArvore* no) {
    if (no == nullptr) {
        return 0;
    }
    if (no->get_Prim() == nullptr) {
        return 1;
    }
    int cont = 0;
    NoArvore* aux = no->get_Prim();
    while (aux != nullptr) {
        cont += folha(aux);
        aux = aux->get_Prox();
    }
    return cont;
}

bool Arvore::igual(Arvore& a) {
    return igual(raiz, a.raiz);
}

bool Arvore::igual(NoArvore* n1, NoArvore* n2) {
    if (n1 == NULL && n2 == NULL) {
        return true;
    } else if (n1 == NULL || n2 == NULL) {
        return false;
    } else if (n1->get_Info() != n2->get_Info()) {
        return false;
    } else {
        NoArvore* filho1 = n1->get_Prim();
        NoArvore* filho2 = n2->get_Prim();

        while (filho1 != NULL && filho2 != NULL) {
            if (!igual(filho1, filho2)) {
                return false;
            }
            filho1 = filho1->get_Prox();
            filho2 = filho2->get_Prox();
        }

        if (filho1 != NULL || filho2 != NULL) {
            return false;
        }

        return true;
    }
}

Arvore Arvore::copia() {
    Arvore nova_arvore;
    nova_arvore.raiz = copia(raiz);
    return nova_arvore;
}

NoArvore* Arvore::copia(NoArvore* no) {
    if (no == NULL) {
        return NULL;
    } else {
        NoArvore* novo_no = new NoArvore(no->get_Info());
        NoArvore* filho = no->get_Prim();

        while (filho != NULL) {
            novo_no->set_Prim(copia(filho));
            filho = filho->get_Prox();
        }

        return novo_no;
    }
}
