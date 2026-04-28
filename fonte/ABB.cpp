#include "ABB.hpp"
// ----------------- Node -----------------------------------------

int Node::getRank(){
    int rank = this->rank;
    return rank;
}

void Node::V(Node* aux, int min, int max, int &contador){
    if (aux == nullptr) return;

    assert(aux->chave > min && aux->chave < max); 

    contador += aux->prof;
    
    V(aux->esquerda, min,aux->chave, contador);
    V(aux->direita,aux->chave, max, contador);

    return;
}

//-----------ABB ---------------------------------------------------

void ABB::insere(int preco, const std::string &nome){
    int  prof = 0;
    int  rank = 1;

    if(raiz == nullptr){
        raiz = new Node(preco, nome, prof, rank);
        return;
    }

    Node* aux = raiz;
    while(true){
        if(aux->chave == preco){ //valor já existe. Nesse caso sobrescreve
            aux->nome = nome;
            return;
        }
        
        aux->rank++;

        if(aux->chave < preco){
            if(aux->direita) aux = aux->direita;
            else{
                prof++;
                aux->direita = new Node(preco, nome, prof, rank);
                break;
            }
        } 
        else if(aux->chave > preco){
            if(aux->esquerda) aux = aux->esquerda;
            else{
                prof++;
                aux->esquerda = new Node(preco, nome, prof, rank);
                break;
            }  
        }
        prof++;
    }
    return;
}

std::string ABB::busca(int preco){
    Node* aux = raiz;
    while(aux->chave != preco){
        if(aux->chave < preco) aux = aux->direita;
        else aux = aux->esquerda;
    }
    return aux->nome;
}

int ABB::conta(int limite){
    int   contador = 0;
    Node* aux = raiz;
    
    if(aux == nullptr) return contador; 
    
    //Se a raíz é menor ou igual ao limite, toda a sub-árvore da esquerda é menor
    while(aux){
        if(aux->chave == limite){
            if(aux->esquerda) contador += (1 + aux->esquerda->getRank());
            else contador++;
            break;
        }
        else if(aux->chave < limite){
            if(aux->esquerda) contador += (1 + aux->esquerda->getRank());
            else contador++;
            aux = aux->direita;
        }
        else if(aux->chave > limite) aux = aux->esquerda;
    }
    return contador;
}

std::string ABB::nesimo(int n, int limite){
    int qtd_dir;//quantidade de candidatos na sub-árvore da direita
    int qtd_esq;
    int total = conta(limite);
    int mn = 0;//quantidade de nós com chave maior que o n-ésimo que estamos procurando 
    Node* aux  = raiz;

    while(aux){
        int chave = aux->chave;
        if(chave <= limite){ //achou o n = 0
            if(aux->esquerda) qtd_esq = aux->esquerda->getRank();
            else qtd_esq = 0;

            qtd_dir = total - (1+ qtd_esq);
            int decisao = mn + qtd_dir;
            if(decisao == n) break;
            else if(decisao > n){
                total -= (1+qtd_esq);
                if(aux->direita) aux = aux->direita;
                else return "Erro";
            } 
            else if(decisao < n){
                mn+= (qtd_dir +1);
                total-= (1+ qtd_dir);
                if(aux->esquerda) aux = aux->esquerda;
                else return "Erro";
            }
        }
        else{
            if(aux->esquerda) aux = aux->esquerda;
            else return "Não encontrado";
        }
    }
    return aux->nome;
}

void ABB::funcaoV(){
    int  contador = 0;
    raiz->V(raiz, 0, 1000000, contador);

    std::cout << "Soma de todas as profundidades da árvore: " << contador <<  std::endl;
}
