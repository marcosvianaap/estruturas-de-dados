#include <iostream>
#include "NoArvore.h"
#include "Arvore.h"
#include "Arvore.cpp"


using namespace std;

int main() {
    Arvore arvore, copia;
    int opcao, info;
    do {
        cout << "Escolha uma opcao:" << endl;
        cout << "1 - Inserir no na arvore" << endl;
        cout << "2 - Imprimir a arvore" << endl;
        cout << "3 - Verificar se um no esta na arvore" << endl;
        cout << "4 - Calcular a altura da arvore" << endl;
        cout << "5 - Contar o numero de nos pares na arvore" << endl;
        cout << "6 - Contar o numero de folhas na arvore" << endl;
        cout << "7 - Copiar a arvore" << endl;
        cout << "8 - Verificar se duas arvores sao iguais" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;
        switch (opcao) {
            case 1:
                cout << "Digite o valor do no raiz: ";
                cin >> info;
                arvore.set_Raiz(new NoArvore(info));
                do {
                    cout << "Digite a informacao do no filho (ou -1 para sair): ";
                    cin >> info;
                    if (info != -1) {
                        arvore.insereFilho(arvore.get_Raiz(), new NoArvore(info));
                    }
                } while (info != -1);
                break;
            case 2:
                arvore.imprime(arvore.get_Raiz());
                cout << endl;
                break;
            case 3:
                cout << "Digite a informacao do no: ";
                cin >> info;
                if (arvore.pertence(info)) {
                    cout << "O no pertence a arvore." << endl;
                } else {
                    cout << "O no nao pertence a arvore." << endl;
                }
                break;
            case 4:
                cout << "A altura da arvore e: " << arvore.altura() << endl;
                break;
            case 5:
                cout << "A arvore possui " << arvore.pares() << " nos pares." << endl;
                break;
            case 6:
                cout << "A arvore possui " << arvore.folha() << " folhas." << endl;
                break;
             case 7:
                copia.set_Raiz(arvore.copia(arvore.get_Raiz()));
                cout << "Arvore original:" << endl;
                arvore.imprime(arvore.get_Raiz());
                cout << "Arvore copiada:" << endl;
                copia.imprime(copia.get_Raiz());
                break;
            case 8:
                cout << "Arvore original:" << endl;
                arvore.imprime(arvore.get_Raiz());
                cout << "Arvore copiada:" << endl;
                copia.imprime(copia.get_Raiz());
                break;
            default:
                cout << "Programa encerrado." << endl;
                break;
        }
    } while (opcao != 0);
    return 0;
}