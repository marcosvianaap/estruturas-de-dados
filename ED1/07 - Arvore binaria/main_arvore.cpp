#include <iostream>
#include <cstdlib>
#include "BinaryTree.h"

using namespace std;

int main(){
    BinaryTree Arvoreinfos;
    int opcao, info,
    imp, valor, pares,
    folhas, alt;

    do{
        cout << "Digite 0 para encerrar o algoritmo!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para imprimir a arvore!\n";
        cout << "Digite 3 para visualizar a arvore!\n";
        cout << "Digite 4 para verificar um valor na arvore!\n";
        cout << "Digite 5 para contar valores que sao pares na arvore\n";
        cout << "Digite 6 para contar a qtde de nos que sao folha\n";
        cout << "Digite 7 para contar a qtde total de nos\n";
        cout << "Digite 8 para obter o tamanho da arvore!\n";
        cout << "Digite 9 para comparar arvores\n";
        cin >> opcao;

        if (opcao == 1){
            cout << "Digite um valor:\n";
            cin >> info;
            
            NoBinaryTree novo_info(info);
            if (Arvoreinfos.isFull()){
                cout << "A Arvore esta cheia!\n";
                cout << "Nao foi possivel inserir o elemento!\n";
            } else{            
                Arvoreinfos.insere(novo_info);
            }

        } else if (opcao == 2){
            cout << "Digite 1 para fazer a impressao em pre-ordem!\n";
            cout << "Digite 2 para fazer a impressao simetrica!\n";
            cout << "Digite 3 para fazer a impressao em pos-ordem!\n";
            cin >> imp;
            if (imp == 1){
                cout << "\n";
                Arvoreinfos.imprimePre(Arvoreinfos.obterRaiz());
                cout << "\n";
            } else if (imp == 2){
                cout << "\n";
                Arvoreinfos.imprimeSim(Arvoreinfos.obterRaiz());
                cout << "\n";
            } else if (imp == 3){ 
                cout << "\n";
                Arvoreinfos.imprimePos(Arvoreinfos.obterRaiz());
                cout << "\n";
            } else {
                cout << "\n";
                cout << "\nOpcao invalida!\n";
                cout << "\n--> Programa encerrado!\n";
                cout << "\n";
                std::exit(0);
            }  
                           
        } else if (opcao == 3){
            
            Arvoreinfos.imprimeEmOrdem(Arvoreinfos.obterRaiz(), cout << "\n");
            cout << "  :(Arvore atual)\n";
            cout << "\n";

        } else if (opcao == 4) {
            cout << "Digite o valor que deseja procurar na arvore:\n";
            cin >> valor;
            if (Arvoreinfos.pertence(valor, Arvoreinfos.obterRaiz())) {
                cout << "\nO valor " << valor << " esta presente na arvore\n" << endl;
            } else {
                cout << "\nO valor " << valor << " nao esta presente na arvore\n" << endl;
            }
        } else if (opcao == 5) {
            pares = Arvoreinfos.pares(Arvoreinfos.obterRaiz());
            if (pares != 0) {
                cout << "\nA arvore possui " << pares << " nos com valores pares.\n";
            } else {
                cout << "\nA arvore nao possui valores pares.\n";
            }
        } else if (opcao == 6) {
            int num_folhas = Arvoreinfos.folhas(Arvoreinfos.obterRaiz());
            cout << "\nA arvore possui " << num_folhas << " no/nos folha.\n";
        }else if (opcao == 7) {
            int num_nos = Arvoreinfos.numNos(Arvoreinfos.obterRaiz());
            cout << "\nA arvore possui " << num_nos << " nos.\n";
        }else if (opcao == 8) {
            int alt = Arvoreinfos.altura(Arvoreinfos.obterRaiz());
            cout << "\nA altura da arvore e " << alt << "\n" << endl;
        } else if (opcao == 9) {
            // Criando a segunda árvore
            BinaryTree outraArvore;
            int numElementos;
            cout << "Digite o numero de elementos da segunda arvore: ";
            cin >> numElementos;
            for (int i = 0; i < numElementos; i++) {
                cout << "Digite o valor " << i+1 << " da segunda arvore: ";
                cin >> info;
                NoBinaryTree novo_info(info);
                outraArvore.insere(novo_info);
            }

            // Verificando se as duas árvores são iguais
            if (Arvoreinfos.igual(Arvoreinfos.obterRaiz(), outraArvore.obterRaiz())) {
                cout << "\nAs arvores sao iguais\n";
            } else {
                cout << "\nAs arvores sao diferentes\n";
            }
        }else if (opcao != 0){
            cout << "\nOpcao invalida!\n";
            cout << "\n--> Programa encerrado!\n";
            std::exit(0);
        }
    } while (opcao != 0);

    return 0;
}

