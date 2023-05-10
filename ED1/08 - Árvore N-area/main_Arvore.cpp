#include <iostream>
#include "Arvore.h"
#include "NoArvore.h"

using namespace std;

int main() {
    Arvore arvore;
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
                cout << "Digite a informacao do no: ";
                cin >> info;
                arvore.insereFilho(new NoArvore(info));
                break;

            case 2:
                arvore.imprime();
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
                Arvore copia = arvore.copia();
                cout << "Arvore original:" << endl;
                arvore.imprime();
                cout << "Arvore copiada:" << endl;
                copia.imprime();
                break;
            case 8:{
                    Arvore arvore2;
                    cout << "Digite os nos da segunda arvore. Finalize com -1:" << endl;
                    do {
                        cin >> info;
                        if (info != -1) {
                            arvore2.insereFilho(new NoArvore(info));
                        }
                    } while (info != -1);

                    if (arvore.igual(arvore2)) {
                        cout << "As arvores sao iguais." << endl;
                    } else {
                        cout << "As arvores nao sao iguais." << endl;
                    }
                }
                break;

            default:
                cout << "Opcao invalida." << endl;
        }
    } while (opcao != 0);
    return 0;
}
