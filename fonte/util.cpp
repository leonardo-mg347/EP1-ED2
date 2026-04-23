#include <iostream>

int perguntaTipo(){
    int tipo;
    std::cout <<    "(1) árvores binárias de busca(sem balanceamento)\n"
                    "(2) árvores rubro-negras esquerdistas\n"
                    "(3) treaps\n"
                    "(4) árvores splay\n"
                    "Qual é o tipo de estrutura que você Deseja usar: ";
    std::cin >> tipo;
    return tipo;
}

std::string recebeComando(){
    std::string comando;
    //std::cout << "Digite um comando: ";
    std::getline(std::cin >> std::ws, comando);
    return comando;
}

std::string* leComando(std::string comando){
    std::string* info = new std::string[3];
    std::string nome;
    std::string preco;
    std::string funcao;

    int indice  = 2;
    char atual  = comando[indice];
    char opcoes[5]= {'I', 'B', 'C', 'N', 'V'};
    bool valido = false;

    for(int i = 0; i<5;i++){
        if(opcoes[i] == comando[0]){
            valido = true;
            break;
        }
    }
    
    if(valido && comando[1] == ' ') funcao = comando[0];
    else funcao = "invalido";

    while(atual != ' ' && atual != 0 && atual != 13){
        preco.push_back(atual);
        indice ++;
        atual = comando[indice];
    }

    indice++;
    atual = comando[indice];

    
    while(atual != ' ' && atual != 0 && atual != 13){
        nome.push_back(atual);
        indice++;
        atual = comando[indice];
    }

    info[0] = funcao;
    info[1] = preco;
    info[2] = nome;
    return info;
}

int transformaNum(std::string str){
    int i = 0, numero= 0, tamanho = 0, exp = 1;
    char atual   = str[i];
    while(atual != 0){
        tamanho++;
        i++;
        atual = str[i];
    }

    i= 0;
    atual = str[i];
    while(atual != 0){
        tamanho--;
        atual -= '0';
        for(int j = 0; j <tamanho; j++){
            exp *= 10;
        }
        numero+= atual*exp;
        i++;
        exp = 1;
        atual = str[i];
    }
    return numero;
}