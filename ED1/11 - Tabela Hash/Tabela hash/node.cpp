#include "node.h"

Node::Node(Aluno a) : aluno(a), proximo(nullptr) {}

Aluno Node::obterAluno() {
    return aluno;
}

Node* Node::obterProximo() {
    return proximo;
}

void Node::definirProximo(Node* prox) {
    proximo = prox;
}
