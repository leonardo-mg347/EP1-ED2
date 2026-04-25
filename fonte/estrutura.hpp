#ifndef ESTRUTURA_HPP
#define ESTRUTURA_HPP

#include <string>
#include <iostream>
#include <assert.h>

class EstruturaDeDados{
public:
    virtual void insere(int preco, const std::string& nome) = 0;

    virtual std::string busca(int preco) = 0;

    virtual int conta(int limite) = 0;

    virtual std::string nesimo(int n, int limite) = 0;

    virtual ~EstruturaDeDados() {};

    EstruturaDeDados() {};

};

    
#endif