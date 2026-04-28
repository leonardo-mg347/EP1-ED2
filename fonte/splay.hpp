#ifndef SPLAY_HPP
#define SLPAY_HPP

#include <vector>
#include "estrutura.hpp"

class Snode{
    friend class Splaytree;
private:
    int chave;
    int rank;
    std::string nome;
    Snode* esquerda;
    Snode* direita;
    Snode* pai;

public:
    Snode(int chave, std::string nome)
    {
        this->chave = chave;
        this->nome  = nome;
        this->rank  = 0;
        esquerda = direita = pai = 0;
    }

    Snode(Snode* pai, int chave, std::string nome)
    {
        this->chave = chave;
        this->nome  = nome;
        this->pai   = pai;
        this->rank  = 0;
        esquerda = direita = 0;
    }

    ~Snode()
    {
        if(esquerda) delete esquerda;
        if(direita)  delete direita;
        if(pai)      delete pai;
    }

    static Snode* Splay(Snode* noh);

    static void Zag(Snode* noh);

    static void Zig(Snode* noh);

    /**
     * @brief mostra o rank de um nó
     * @param nó consultado
     * @return rank do nó
     */
    static int Rank(Snode* noh);

    /**
     * @brief verifica se o nó cumpre as invariantes e soma a profundidade do nó em um endereço
     * @param aux nó a ser verificado
     * @param min range mínimo para o nó
     * @param max range máximo para o nó
     * @param contador referencia para o inteiro que guarda a soma das profundidades
     * @param prof profundidade do nó atual 
     */
    static void V(Snode* aux,int min, int max, int &contador, int prof);
    
};

class Splaytree: public EstruturaDeDados{
private:
    Snode* raiz;
public:
    Splaytree(): EstruturaDeDados(){
        raiz = 0;
    }

    ~Splaytree(){
        if(raiz) delete raiz;
    }

    void insere(int preco, const std::string& nome) override;

    std::string busca(int preco) override;

    int conta(int limite) override;

    std::string nesimo(int n, int limite) override;

    void funcaoV() override;
};
#endif