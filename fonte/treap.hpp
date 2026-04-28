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

    /**
     * @brief verifica se o nó cumpre as invariantes e soma a profundidade do nó em um endereço
     * @param aux nó a ser verificado
     * @param min range mínimo para o nó
     * @param max range máximo para o nó
     * @param p_raiz prioridade mínima para manter as invariantes
     * @param contador referencia para o inteiro que guarda a profundidade 
     */
    void V(Tnode* aux,int min, int max,int p_min, int &contador, int prof);
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

    void funcaoV() override;
};
#endif