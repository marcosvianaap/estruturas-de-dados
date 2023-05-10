#include "NoBinaryTree.h"

NoBinaryTree::NoBinaryTree(){
    info = -1;
}

NoBinaryTree::NoBinaryTree(int valor){
    info = valor;
}

int NoBinaryTree::obterInfo(){
    return info;
}
