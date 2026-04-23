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
            std::string nome;    //nome do vinho
            Node* direita;       //filho da direita
            Node* esquerda;      //filho da esquerda
            Node(int chave, std::string nome){
                this->chave     = chave;
                this->nome      = nome;
                this->direita   = NULL;
                this->esquerda  = NULL;
            }

            void muda(int chave, std::string nome){
                this->chave = chave;
                this->nome = nome;
            }

            int compara(int preco){
               if(preco < this->chave) return -1;
               else return 0; 
            }

            void show(){
                std::cout << "Chave: " << this->chave <<
                "\nNome: " << this->nome << std::endl;
            }
    };
    Node*   raiz;
    int     tamanho;
public:
    arvoreBinariaDeBusca(): EstruturaDeDados(){
        this->raiz    = new Node(-1, "Indefinido");
        this->tamanho = 0;
        std::cout << "\nÁrvore binária de busca.\n\n";
    };

    void insere(int preco, const std::string &nome) override;

    std::string busca(int preco) override;

    int conta(int limite) override;

    std::string nesimo(int n, int limite) override;

}; using ABB = arvoreBinariaDeBusca;
#endif