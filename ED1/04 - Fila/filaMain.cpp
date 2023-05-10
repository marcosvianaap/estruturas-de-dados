#include <iostream>
#include "fila.h"

using namespace std;

int main() {
    FilaVet fila1;
    FilaVet fila2;
    FilaVet fila3;
    int opcao;
    TipoItem v;
    cout << "Programa gerador de filas:\n";

    do {
        cout << "Digite 0 para parar o programa!\n";
        cout << "Digite 1 para inserir um elemento na fila 1!\n";
        cout << "Digite 2 para remover um elemento da fila 1!\n";
        cout << "Digite 3 para imprimir a fila 1!\n";
        cout << "Digite 4 para reinicializar a fila 1!\n";
        cout << "Digite 5 para inserir um elemento na fila 2!\n";
        cout << "Digite 6 para remover um elemento da fila 2!\n";
        cout << "Digite 7 para imprimir a fila 2!\n";
        cout << "Digite 8 para reinicializar a fila 2!\n";
        cout << "Digite 9 para concatenar a fila 2 na fila 1!\n";
        cout << "Digite 10 para intercalar a fila 2 na fila 1!\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o elemento a ser inserido na fila 1!\n";
                cin >> v;
                fila1.enqueue(v);
                break;

            case 2:
                v = fila1.dequeue();
                cout << "O elemento removido da fila 1 foi: " << v << endl;
                break;

            case 3:
                fila1.print();
                break;

            case 4:
                fila1.reset();
                cout << "A fila 1 foi reinicializada!\n";
                break;

            case 5:
                cout << "Digite o elemento a ser inserido na fila 2!\n";
                cin >> v;
                fila2.enqueue(v);
                break;

                case 6:
                    v = fila2.dequeue();
                    cout << "O elemento removido da fila 2 foi: " << v << endl;
                    break;

                case 7:
                    fila2.print();
                    break;

                case 8:
                    fila2.reset();
                    cout << "A fila 2 foi reinicializada!\n";
                    break;

                case 9:
                    fila1.concatena(fila2);
                    cout << "A fila 2 foi concatenada na fila 1!\n";
                    break;

                case 10:
                    fila3 = fila1.merge(fila2);
                    cout << "A fila 2 foi intercalada na fila 1 resultando na fila 3:\n";
                    fila3.print();
                    break;

                default:
                    if (opcao != 0) {
                        cout << "Opcao invalida! Tente novamente.\n";
                    }
                    break;
            }
    } while (opcao != 0);

    return 0;
}
