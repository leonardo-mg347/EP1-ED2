#include "estrutura.hpp"
#include "util.hpp"
#include "ABB.hpp"
#include "RBTree.hpp"
#include "treap.hpp"
#include "splay.hpp"

int main(){

    //definindo o tipo de estrutura que será usada.
    int tipo = perguntaTipo();

    //criando a estrutura vazia.
    EstruturaDeDados* estrutura;
    switch (tipo)
    {
    case 1:{
        estrutura = new ABB;
        break;
    }
    case 2:{
        estrutura = new RBTree<int, std::string>;
        break;
    }
    case 3:{
        estrutura = new Treap;
        break;
    }
    case 4:{
        estrutura = new Splaytree;
        break;
    }
    default:{
        std::cout << "\n\nTipo inválido\n\n" << std::endl;
        return -1;
    }
    }    

    std::string comando; 
    std::string* info;
    while(!(std::cin.eof() && comando != "exit")){ 
        //recebendo um comando
        comando = recebeComando();

        //lendo o comando recebido
        info              = leComando(comando);
        int numero        = transformaNum(info[1]);
        
        //executa o comando
        switch(info[0][0])
        {
            case 'I':{
                estrutura->insere(numero, info[2]);
                break;
            }
            case 'B':{
                std::string nome = estrutura->busca(numero);
                std::cout << "O nome do vinho que custa " << numero << " é: " << nome << std::endl;
                break;
            }
            case 'C':{
                std::cout << "Número limite: " << numero << std::endl;
                int contador = estrutura->conta(numero);
                std::cout << "Quantidade de vinhos com preco até " << numero << ": " << contador << std::endl;
                break;
            }
            case 'N':{
                int limite = transformaNum(info[2]);
                std::cout << "O nome do vinho pedido é: " << estrutura->nesimo(numero, limite) << std::endl;
                break;
            }
            case 'V':{
                estrutura->funcaoV();
                break;
            }
        }
    }
        
}