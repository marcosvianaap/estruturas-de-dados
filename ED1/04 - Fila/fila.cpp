#include <iostream>
#include "fila.h"

using namespace std;

    FilaVet::FilaVet(){
        ini = 0;
        n = 0;
        vet = new TipoItem[tam];
    }

    FilaVet::~FilaVet(){
        delete [] vet;
    }

    bool FilaVet::isEmpty(){
        return (ini == n);
    }

    bool FilaVet::isFull(){// Serve para verificar a quantidade de elementos e para inserir ao fim
        return (n-ini == tam);
    }

    void FilaVet::enqueue(TipoItem v){
        if (isFull()){
            cout << "A FilaVet esta cheia\n";
            cout << "Esse elemento nao pode ser inserido\n";
        } else{
            vet[n % tam] = v;
            n++;
        }
    }

    TipoItem FilaVet::dequeue(){
        if (isEmpty()){
            cout << "A FilaVet esta vazia!\n";
            cout << "Nenhum elemento foi removido!\n";
            return 0;
        } else{
            ini++;            
            return vet[(ini-1) % tam];
        }
    }
    void FilaVet::concatena(FilaVet f2) {
        FilaVet f;
        f.ini = 0;
        f.n = n;

        for (int i = ini; i < n; i++) {
            f.enqueue(vet[i % tam]);
        }
        for (int i = f2.ini; i < f2.n; i++) {
            f.enqueue(f2.vet[i % f2.tam]);
        }
        return f;
    }


FilaVet FilaVet::merge(FilaVet f2) {
    FilaVet f;
    f.reset();
    int i = ini;
    int j = f2.ini;
    while (i < n && j < f2.n) {
        f.enqueue(vet[i % tam]);
        i++;
        f.enqueue(f2.vet[j % f2.tam]);
        j++;
    }
    while (i < n) {
        f.enqueue(vet[i % tam]);
        i++;
    }
    while (j < f2.n) {
        f.enqueue(f2.vet[j % f2.tam]);
        j++;
    }
    return f;
}



    void FilaVet::reset() {
    ini = 0;
    n = 0;
    }



    void FilaVet::print(){
        cout << "Fila Atual: [ ";
        for (int i=ini ; i<n ; i++){
            cout << vet[i % tam] << " ";
        }
        cout << "]\n";
    }
