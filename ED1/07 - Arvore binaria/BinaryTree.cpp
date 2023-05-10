#include <iostream>
#include <cstddef>
#include "BinaryTree.h"
#include "NoBinaryTree.h"


using namespace std;

BinaryTree::BinaryTree() { //construtor
    raiz = NULL;
}

BinaryTree::~BinaryTree() { //destrutor

}

    No* BinaryTree::obterRaiz() {
        return raiz;
    }

bool BinaryTree::vazia() {
    return (raiz == NULL);
}

bool BinaryTree::isFull() {
    try {
        No* temp = new No;
        delete temp;
        return false;
    } catch(const bad_alloc& exception) {
        return true;
    }
}

void BinaryTree::imprimeEmOrdem(No* Noatual, ostream& os){
    if (Noatual != NULL){
        imprimeEmOrdem(Noatual->sae, os);

        os << Noatual->info.obterInfo() << " ";

        imprimeEmOrdem(Noatual->sad, os);            
    }
}

bool BinaryTree::pertence(int valor, No* Noatual) {
    if (Noatual == NULL) { // se chegou em um nó folha sem encontrar o valor
        return false;
    } else if (Noatual->info.obterInfo() == valor) { // se encontrou o valor
        return true;
    } else if (valor < Noatual->info.obterInfo()) { // se o valor é menor que o valor do nó atual
        return pertence(valor, Noatual->sae); // busca na subárvore esquerda
    } else { // se o valor é maior que o valor do nó atual
        return pertence(valor, Noatual->sad); // busca na subárvore direita
    }
}

int BinaryTree::pares(No* Noatual) {
    if (Noatual == NULL) { // se chegou em um nó folha
        return 0;
    } else {
        int qtde_pares = 0;
        if (Noatual->info.obterInfo() % 2 == 0) { // se o valor do nó atual é par
            qtde_pares++;
        }
        qtde_pares += pares(Noatual->sae); // busca na subárvore esquerda
        qtde_pares += pares(Noatual->sad); // busca na subárvore direita
        return qtde_pares;
    }
}

int BinaryTree::folhas(No* Noatual) {
    if (Noatual == NULL) { // se chegou em um nó nulo
        return 0;
    } else if (Noatual->sae == NULL && Noatual->sad == NULL) { // se o nó atual é uma folha
        return 1;
    } else { // se o nó atual possui filhos
        return folhas(Noatual->sae) + folhas(Noatual->sad);
    }
}



void BinaryTree::insere(NoBinaryTree info) {
    if (isFull()) {
        cout << "A Arvore esta cheia!\n";
        cout << "Nao foi possivel inserir este elemento!\n";
    } else {
        No* NoNovo = new No;
        NoNovo->info = info;
        NoNovo->sad = NULL;
        NoNovo->sae = NULL;
        if (raiz == NULL) {
            raiz = NoNovo;
        } else {
            No* temp = raiz;
            while (temp != NULL) {
                if (info.obterInfo() < temp->info.obterInfo()) {
                    if (temp->sae == NULL) {
                        temp->sae = NoNovo;
                        break;
                    } else {
                        temp = temp->sae;
                    }
                } else {
                    if (temp->sad == NULL) {
                        temp->sad = NoNovo;
                        break;
                    } else {
                        temp = temp->sad;
                    }
                }
            }
        }
    }
}

void BinaryTree::imprimePre(No* Noatual) {
    if (Noatual != NULL) {
        cout << Noatual->info.obterInfo() << endl;
        imprimePre(Noatual->sae);
        imprimePre(Noatual->sad);
    }
}

void BinaryTree::imprimeSim(No* Noatual) {
    if (Noatual != NULL) {
        imprimeSim(Noatual->sae);
        cout << Noatual->info.obterInfo() << endl;
        imprimeSim(Noatual->sad);            
    }
}

void BinaryTree::imprimePos(No* Noatual) {
    if (Noatual != NULL) {
        imprimePos(Noatual->sae);
        imprimePos(Noatual->sad);
        cout << Noatual->info.obterInfo() << endl;            
    }
}

int BinaryTree::numNos(No* Noatual) {
    if (Noatual == NULL) { 
        return 0;
    } else {
        return 1 + numNos(Noatual->sae) + numNos(Noatual->sad);
    }
}

int BinaryTree::altura(No* Noatual) {
    if (Noatual == NULL) {
        return 0;
    } else {
        int altura_esquerda = altura(Noatual->sae);
        int altura_direita = altura(Noatual->sad);
        return 1 + max(altura_esquerda, altura_direita);
    }
}

bool BinaryTree::igual(No* raiz1, No* raiz2) {
    if (raiz1 == NULL && raiz2 == NULL) { // se ambos são nós nulos
        return true;
    } else if (raiz1 == NULL || raiz2 == NULL) { // se apenas um é nulo
        return false;
    } else if (raiz1->info.obterInfo() != raiz2->info.obterInfo()) { // se os valores dos nós são diferentes
        return false;
    } else { // se os valores dos nós são iguais
        return igual(raiz1->sae, raiz2->sae) && igual(raiz1->sad, raiz2->sad);
    }
}
