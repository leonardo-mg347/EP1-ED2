#include "ABB.hpp"

void ABB::insere(int preco, const std::string &nome){
    Node* novo      = new Node(preco, nome);
    if(this->tamanho == 0){
        this->raiz->muda(preco, nome);
        delete novo;
    }else{
        Node* auxiliar  = this->raiz;
        while(!(auxiliar == nullptr)){
            if(auxiliar->compara(preco) == -1){
                if(auxiliar->esquerda == nullptr) {
                    auxiliar->esquerda = novo;
                    break;
                }
                else auxiliar = auxiliar->esquerda;
            } 
            else {
                if(auxiliar->direita == nullptr){
                    auxiliar->direita = novo;
                    break;
                } 
                else auxiliar = auxiliar->direita;
            }
        }
    }
    this->tamanho++;
    std::cout << "Nó inserido com sucesso.\n" <<
    "Tamanho: " << this->tamanho << std::endl;

    if(this->tamanho > 1) novo->show();
    else raiz->show();
    return;
}

std::string ABB::busca(int preco){
    Node* auxiliar = this->raiz;
    while(!(auxiliar->chave == preco)){
        if(auxiliar->compara(preco) == -1) auxiliar = auxiliar->esquerda;
        else auxiliar = auxiliar->direita;
    }
    return auxiliar->nome;
}

int ABB::conta(int limite){
    int   contador = 0;
    Node* auxiliar = raiz;
    
    //achar uma sub-árvore com raíz menor ou igual ao limite
    while(auxiliar != nullptr && auxiliar->chave > limite){
       auxiliar = auxiliar->esquerda;
    }
    if(auxiliar == nullptr) return contador; 

    contador++;

    //Se a raíz é menor ou igual ao limite, toda a sub-árvore da esquerda é menor
    std::vector<Node*> visitar;
    if(auxiliar->esquerda != nullptr){
        Node* raizEsquerda = auxiliar->esquerda;
        visitar.push_back(raizEsquerda);
        while(!visitar.empty()){
            visitar.pop_back();
            contador++;
            if(raizEsquerda->esquerda != nullptr) visitar.push_back(raizEsquerda->esquerda);
            if(raizEsquerda->direita != nullptr)  visitar.push_back(raizEsquerda->direita);
            if(!visitar.empty()) raizEsquerda = visitar.back();
        }
    }
    if(auxiliar->direita != nullptr){
        Node* raizDireita = auxiliar->direita;
        visitar.push_back(raizDireita);
        while(!visitar.empty()){
            visitar.pop_back();
            if(raizDireita->chave <= limite) contador++;
            if(raizDireita->esquerda != nullptr) visitar.push_back(raizDireita->esquerda);
            if(raizDireita->direita != nullptr) {
                if(raizDireita->chave < limite) visitar.push_back(raizDireita->direita);
            }
            if(!visitar.empty()) raizDireita = visitar.back();
        }
    }
    visitar.clear();
    return contador;
}

std::string ABB::nesimo(int n, int limite){
    Node*        raizTemporaria = this->raiz;
    Node*        auxiliar       = raizTemporaria;
    int          precocmp       = limite;
    bool         achou          = false;
    Node*        raizTemporaria2;
    std::string  nome;
    
    //achando a maior sub-árvore com raíz menor ou igual ao limite
    while(raizTemporaria->chave > limite){
        raizTemporaria  = raizTemporaria->esquerda;
        auxiliar        = raizTemporaria;
    }
    //std::cout << "chave da raiz: " << auxiliar->chave << std::endl; 
    for(int i = 0; i <= n ; i++){
        //achando o nome com a maior chave da árvore e menor ou igual que precocmp
        while(raizTemporaria->chave > precocmp){
        raizTemporaria  = raizTemporaria->esquerda;
        auxiliar        = raizTemporaria;
        }
        while(!achou){
            //std::cout << auxiliar->chave << std::endl;
            if(auxiliar->chave == precocmp){
                nome           = auxiliar->nome;
                achou          = true;
                precocmp       = auxiliar->chave - 1;
            }else if(auxiliar->chave < precocmp){
                if(auxiliar->direita != nullptr){
                    if(auxiliar->direita->chave > precocmp){
                        raizTemporaria2 = auxiliar;
                    }
                    auxiliar = auxiliar->direita;  
                }else{//Se não há filho da direita, o maior é o auxiliar
                    precocmp = (auxiliar->chave - 1);
                    nome     = auxiliar->nome;   
                    achou    = true;
                }
                    
            }else{//auxiliar->chave > precocomp
                if(auxiliar->esquerda != nullptr && auxiliar->esquerda->chave <= precocmp){
                    auxiliar = auxiliar->esquerda;
                }else{
                    nome     = raizTemporaria2->nome;
                    achou    = true;
                    precocmp = raizTemporaria2->chave - 1;
                }
            }
        //std::cout << "\n\nlaço while:" << std::endl;
        //std::cout << precocmp << std::endl;
    }
    achou    = false;
    auxiliar = raizTemporaria;
    //std::cout << "chave do auxiliar: " << auxiliar->chave << std::endl;
    }
    return nome;
}
