#ifndef NODE_H
#define NODE_H

#include "aluno.h"

class Node {
private:
    Aluno aluno;
    Node* proximo;

public:
    Node(Aluno a);
    Aluno obterAluno();
    Node* obterProximo();
    void definirProximo(Node* prox);
};

#endif  // NODE_H
