#ifndef TREAP_HPP
#define TREAP_HPP
#define MAX_PRIORITY 1000000

#include <random>
#include "estrutura.hpp"



class Tnode{
    friend class Treap;
private:
    int         chave;
    int         prioridade;
    std::string nome;
    Tnode*      esquerda;
    Tnode*      direita;
public:
    Tnode(int c, std::string n, int p){
        chave              = c;
        prioridade         = p;
        nome               = n;
        esquerda = direita = 0; 
    }

    static Tnode* insert(Tnode* noh, int c, std::string n, int p);

    static std::string search(Tnode* noh, int preco);

    static void count(Tnode* noh, int limite, int* contador);

    static int find_greater(Tnode* noh, int limite);

    static int getPriority(Tnode* noh);

    static Tnode* rotateLeft(Tnode* noh);

    static Tnode* rotateRight(Tnode* noh);
};

class Treap: public EstruturaDeDados{
private:
    Tnode* raiz;
public:
    Treap(): EstruturaDeDados(){
        raiz = 0;
    }

    ~Treap(){
        if(raiz) delete raiz;
    }

    int gerarPrioridade();

    void insere(int preco, const std::string& nome) override;

    std::string busca(int preco) override;

    int conta(int limite) override;

    std::string nesimo(int n, int limite) override;
};
#endif