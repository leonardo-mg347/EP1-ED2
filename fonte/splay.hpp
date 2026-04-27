#ifndef SPLAY_HPP
#define SLPAY_HPP

#include <vector>
#include "estrutura.hpp"

class Snode{
    friend class Splaytree;
private:
    int chave;
    std::string nome;
    Snode* esquerda;
    Snode* direita;
    Snode* pai;

public:
    Snode(int chave, std::string nome)
    {
        this->chave = chave;
        this->nome  = nome;
        esquerda = direita = pai = 0;
    }

    Snode(Snode* pai, int chave, std::string nome)
    {
        this->chave = chave;
        this->nome  = nome;
        this->pai   = pai;
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

    static void count(Snode* noh, int limite, int* contador);
    
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

    std::string nesimo(int n, int limite) { return "Não implementado";};
};
#endif