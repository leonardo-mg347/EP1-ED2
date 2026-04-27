#include "splay.hpp"

//----------------Snode-----------------------------------------------------------

Snode* Snode::Splay(Snode* noh)
{
    if(!noh) return nullptr;

    while(noh->pai != nullptr){
        Snode* pai = noh->pai;
        Snode* vo = pai->pai;
        
        if(vo == nullptr){//Um zig ou um zag
            if(noh == pai->esquerda) pai->Zig(pai);
            else pai->Zag(pai);
        }
        else if(pai == vo->esquerda && noh == pai->esquerda){
            vo->Zig(vo);
            pai->Zig(pai);
        }
        else if(pai == vo->direita && noh == pai->direita){
            vo->Zag(vo);
            pai->Zag(pai);
        }
        else if(pai == vo->esquerda && noh == pai->direita){
            pai->Zag(pai);
            vo->Zig(vo);
        }
        else{
            pai->Zig(pai);
            vo->Zag(vo);
        }
    }
    return noh;
}
void Snode::Zag(Snode* noh)
{
    assert(noh->direita);
    Snode* aux    = noh->direita;
    Snode* vo     = noh->pai;


    noh->direita = aux->esquerda;
    if (aux->esquerda != nullptr) {
        aux->esquerda->pai = noh;
    }
    aux->esquerda  = noh;
    noh->pai      = aux;
    aux->pai      = vo;
    if (vo != nullptr) {
        if (vo->esquerda == noh) vo->esquerda = aux;
        else vo->direita = aux;
    }
}

void Snode::Zig(Snode* noh)
{
    assert(noh->esquerda);
    Snode* aux    = noh->esquerda;
    Snode* vo     = noh->pai;

    noh->esquerda = aux->direita;
    if (aux->direita != nullptr) {
        aux->direita->pai = noh;
    }

    aux->direita  = noh;
    noh->pai      = aux;
    aux->pai      = vo;
    if (vo != nullptr) {
        if (vo->esquerda == noh) vo->esquerda = aux;
        else vo->direita = aux;
    }
}

//------------------Splay Tree ---------------------------------------------------


void Splaytree::insere(int preco, const std::string& nome)
{
    if(raiz == nullptr) raiz = new Snode(preco, nome);

    Snode* aux = raiz;
    while(true){
        if(aux->chave == preco) break; //preço duplicado
        if(aux->chave < preco){
            if(aux->direita) aux = aux->direita;
            else{
                aux->direita = new Snode(aux, preco, nome);
                aux = aux->direita;
                break;
            }
        }
        if(aux->chave > preco){
            if(aux->esquerda) aux = aux->esquerda;
            else{
                aux->esquerda = new Snode(aux, preco, nome);
                aux = aux->esquerda;
                break;
            }
        } 
    }
    Snode::Splay(aux);
    raiz = aux;
    std::cout << raiz->chave << std::endl;
}

std::string Splaytree::busca(int preco){
    Snode* aux = raiz;
    while(aux != nullptr){
        if(aux->chave == preco) return aux->nome;
        else if(aux->chave < preco) aux = aux->direita;
        else if(aux->chave > preco) aux = aux->esquerda;
    };
    Snode::Splay(aux);
    return aux->nome;
}

int Splaytree::conta(int limite)
{
    int contador = 0;
    Snode* aux   = raiz;
    Snode* aux2  = aux; //melhor candidato até o momento

    //maior subárvore com raiz menor ou igual ao limite
    while(aux->chave > limite){
        aux = aux->esquerda;
        aux2= aux;
    }

    //encontrar o maior nó que seja menor ou igual ao limite
    while(aux != nullptr){
        if(aux->chave == limite) break;
        else if(aux->chave > limite){
            if(aux->esquerda) aux = aux->esquerda;
            else break;
        }
        else if(aux->chave < limite){
            if(aux->direita){
                if(aux->direita->chave <= limite) aux = aux->direita;
                else{
                    aux2= aux;
                    aux = aux->direita;
                } 
            }
            else{
                aux2 = aux;
                break;
            } 
        }
    }
    //o maior está no aux2
    Snode::Splay(aux2);

    //agora todos os menores ou iguais estão na subárvore da esquerda

    return 0;
}