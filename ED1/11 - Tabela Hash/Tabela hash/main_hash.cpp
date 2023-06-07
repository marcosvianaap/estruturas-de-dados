#include <iostream>
#include "aluno.h"
#include "hash.h"

int main() {
    std::cout << "Programa gerador de Hash!\n";
    int tam_vetor, max;
    std::cout << "Digite o tamanho da Hash!\n";
    std::cin >> tam_vetor;
    std::cout << "Digite o numero maximo de elementos!\n";
    std::cin >> max;
    std::cout << "O fator de carga e: " << (float)max / (float)tam_vetor << std::endl;
    Hash alunohash(tam_vetor, max);
    int opcao;
    int ra;
    std::string nome;
    bool busca;

    do {
        std::cout << "Digite 0 para parar o algoritmo!\n";
        std::cout << "Digite 1 para inserir um elemento!\n";
        std::cout << "Digite 2 para remover um elemento!\n";
        std::cout << "Digite 3 para busca um elemento!\n";
        std::cout << "Digite 4 para imprimir a Hash!\n";
        std::cin >> opcao;

        if (opcao == 1) {
            std::cout << "Qual e o RA do aluno?\n";
            std::cin >> ra;
            std::cout << "Qual e o nome do aluno?\n";
            std::cin >> nome;
            Aluno aluno(ra, nome);
            alunohash.inserir(aluno);
        } else if (opcao == 2) {
            std::cout << "Qual e o RA do aluno a ser removido?\n";
            std::cin >> ra;
            Aluno aluno(ra, "");
            alunohash.deletar(aluno);
        } else if (opcao == 3) {
            std::cout << "Qual e o RA do aluno a ser buscado?\n";
            std::cin >> ra;
            Aluno aluno(ra, "");
            alunohash.buscar(aluno, busca);
            if (busca) {
                std::cout << "Aluno encontrado:\n";
                std::cout << "RA: " << aluno.obterRa() << std::endl;
                std::cout << "Nome: " << aluno.obterNome() << std::endl;
            } else {
                std::cout << "Aluno nao encontrado!\n";
            }
        } else if (opcao == 4) {
            alunohash.imprimir();
        }

    } while (opcao != 0);

    return 0;
}
