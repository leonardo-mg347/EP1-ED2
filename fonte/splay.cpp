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
    aux->rank = noh->rank; 
    noh->rank = 1 + Snode::Rank(noh->esquerda) + Snode::Rank(noh->direita);
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

    aux->rank = noh->rank; 
    noh->rank = 1 + Rank(noh->esquerda) + Rank(noh->direita);
}

int Snode::Rank(Snode* noh){
    if(noh == nullptr) return 0;
    else return noh->rank;
}

void Snode::V(Snode* aux, int min, int max, int &contador, int prof){
    if (aux == nullptr) return;

    assert(aux->chave > min && aux->chave < max); 

    contador += prof;
    
    V(aux->esquerda, min,aux->chave, contador, prof+1);
    V(aux->direita,aux->chave, max, contador, prof +1);

    return;
}

//------------------Splay Tree ---------------------------------------------------


void Splaytree::insere(int preco, const std::string& nome)
{
    if(raiz == nullptr){
        raiz = new Snode(preco, nome);
        return;
    } 

    Snode* aux = raiz;
    while(true){
        aux->rank++;
        if(aux->chave < preco){
            if(aux->direita == nullptr){
                aux->direita = new Snode(aux, preco, nome);
                aux= aux->direita;
                break;
            }
            aux = aux->direita;
        }
        if(aux->chave > preco){
            if(aux->esquerda == nullptr){ 
                aux->esquerda = new Snode(aux, preco, nome);
                aux = aux->esquerda;
                break;
            }
            aux = aux->esquerda;
        } 
    }
    raiz = Snode::Splay(aux);
    raiz->rank = 1 + Snode::Rank(raiz->esquerda) + Snode::Rank(raiz->direita);
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

    //encontrar o maior nó que seja menor ou igual ao limite
    while(aux != nullptr){
        if(aux->chave == limite){
            aux2 = aux;
            break;
        } 
        else if(aux->chave > limite) aux = aux->esquerda;
    
        else if(aux->chave < limite){
            aux2 = aux;
            aux = aux->direita;
        }
    }
    if(aux2 == nullptr) return 0;
    //o maior está no aux2
    Snode::Splay(aux2);
    raiz = aux2;

    //agora todos os menores ou iguais estão na subárvore da esquerda
    return (1 + Snode::Rank(raiz->esquerda));
}

std::string Splaytree::nesimo(int n, int limite){
    int total = conta(limite); //Splaya o maior
    int alvo  = (total - 1) - n;//se n é 3 e tem 10 nós candidatos o nó que procuro é o 6 

    if(total <= 0 || alvo < 0) return "Não encontrado";

    Snode* aux = raiz;
    while(aux){
        int qtd_esq = Snode::Rank(aux->esquerda);
        
        if(qtd_esq == alvo){
            Snode::Splay(aux);
            raiz = aux;
            return raiz->nome;
        }
        else if(alvo < qtd_esq){//o n-ésimo está na esquerda
            aux = aux->esquerda;
        }
        else{ //o n-ésimo está na direita
            alvo -= (qtd_esq + 1);
            aux = aux->direita;
        }
    }
    return "Não encontrado";
}

void Splaytree::funcaoV(){
    int  contador = 0;
    raiz->V(raiz, 0, 1000000, contador, 0);

    std::cout << "Soma de todas as profundidades da árvore: " << contador <<  std::endl;
}