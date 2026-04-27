#ifndef ABB_HPP
#define ABB_HPP

#include "estrutura.hpp"
#include "util.hpp"
#include <vector>

class arvoreBinariaDeBusca: public EstruturaDeDados{
private:
    class Node{
        public:
            int chave;           //preço do vinho
            int rank;            //tamanho da subárvore enraizada no nó
            int prof;            //profundidade do nó
            std::string nome;    //nome do vinho
            Node* direita;       //filho da direita
            Node* esquerda;      //filho da esquerda


            Node(int chave, std::string nome,int prof, int rank){
                this->chave     = chave;
                this->nome      = nome;
                this->prof      = prof;
                this->rank      = rank;
                this->direita   = nullptr;
                this->esquerda  = nullptr;
            }

            ~Node(){
                if(direita){
                    delete direita;
                }
                if(esquerda){
                    delete esquerda;
                }
            }

            int getRank(){
                return this->rank;
            }
    };
    Node*   raiz;
public:
    arvoreBinariaDeBusca(): EstruturaDeDados(){
        this->raiz    = nullptr;
        std::cout << "\nÁrvore binária de busca.\n\n";
    };

    void insere(int preco, const std::string &nome) override;

    std::string busca(int preco) override;

    int conta(int limite) override;

    std::string nesimo(int n, int limite) override;

}; using ABB = arvoreBinariaDeBusca;
#endif