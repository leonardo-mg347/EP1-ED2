#ifndef ESTRUTURA_HPP
#define ESTRUTURA_HPP

#include <string>
#include <iostream>
#include <assert.h>

class EstruturaDeDados{
public:
    /**
     * @brief insere um vinho na árvore
     * @param preco preco do vinho
     * @param nome  nome do vinho
     */
    virtual void insere(int preco, const std::string& nome) = 0;


     /**
     * @brief busca um vinho que custe determinado preço
     * @param preco preço do vinho a ser buscado
     * @return nome do vinho buscado
     */
    virtual std::string busca(int preco) = 0;


     /**
     * @brief conta quantos vinhos custam até um limite
     * @param limite preço máximo dos vinhos
     * @return número de vinhos que custam menos ou igual ao limite
     */
    virtual int conta(int limite) = 0;

    /**
     * @brief busca o n-ésimo vinho que custe menos ou igual a limite
     * @n 
     * @param limite valor máximo dos vinhos
     * @return nome do n-ésimo vinho
     */
    virtual std::string nesimo(int n, int limite) = 0;
    
    /**
     * @brief verifica invariantes da árvore e imprime a soma da profundidade
     * de todos os nós da árvore
     */
    virtual void funcaoV() = 0;

    virtual ~EstruturaDeDados() {};

    EstruturaDeDados() {};

};

    
#endif