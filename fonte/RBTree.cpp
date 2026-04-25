#include "RBTree.hpp"

template<> 
void RBTree<int, std::string>::insere(int preco, const std::string& nome){
    this->insert(preco, nome);
}

template<>
std::string RBTree<int, std::string>::busca(int preco){
    return this->search(preco);
}

template<>
int RBTree<int, std::string>::conta(int limite){
    int contador = 0;
    root->count(this->root, limite, &contador);
    return contador;
}

template<>
std::string RBTree<int, std::string>:: nesimo(int n, int limite){
    int valorDoNesimo;
    for(int i = 0; i <= n; i++){
        valorDoNesimo = root->find_greater(root, limite);
        limite = valorDoNesimo - 1;
    }
    return search(valorDoNesimo);
}