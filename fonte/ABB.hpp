#ifndef ABB_HPP
#define ABB_HPP

#include "estrutura.hpp"
#include "util.hpp"
#include <vector>


class Node{
    friend class arvoreBinariaDeBusca;
private:
    int chave;           //preço do vinho
    int rank;            //tamanho da subárvore enraizada no nó
    int prof;            //profundidade do nó
    std::string nome;    //nome do vinho
    Node* direita;       //filho da direita
    Node* esquerda;      //filho da esquerda

public:
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

    /**
     * @brief busca o rank de um nó
     * @return rank do nó que chamou ou 0 se o nó for nulo
     */
    int getRank();

    /**
     * @brief verifica se o nó cumpre as invariantes e soma a profundidade do nó em um endereço
     * @param aux nó a ser verificado
     * @param min range mínimo para o nó
     * @param max range máximo para o nó
     * @param contador referencia para o inteiro que guarda a soma das profundidades 
     */
    void V(Node* aux,int min, int max, int &contador);
};

class arvoreBinariaDeBusca: public EstruturaDeDados{
private:
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

    void funcaoV() override;

};

using ABB = arvoreBinariaDeBusca;



#endif