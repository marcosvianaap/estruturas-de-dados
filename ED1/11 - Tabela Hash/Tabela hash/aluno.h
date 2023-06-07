#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    int ra;
    std::string nome;

public:
    Aluno();
    Aluno(int r, std::string n);
    int obterRa();
    std::string obterNome();
};

#endif  // ALUNO_H
