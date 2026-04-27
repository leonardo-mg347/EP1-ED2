#include "ABB.hpp"

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
    }
    if(raiz->esquerda != nullptr){
        std::cout << "Nó inserido.\n Preço: "<< raiz->esquerda->chave << "\nNome: " << raiz->esquerda->nome << "\nRank: " << raiz->esquerda->rank << "\nprofundidade: " << raiz->esquerda->prof << std::endl;
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
    
    //achar uma sub-árvore com raíz menor ou igual ao limite
    while(aux != nullptr && aux->chave > limite){
       aux = aux->esquerda;
    }
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
    int   qtd_dir;
    int   contados     = 0;
    int   falta_contar = conta(limite);
    std::cout << falta_contar <<std::endl;
    Node* aux          = raiz;

    if(falta_contar == 0) return "Não encontrado";

    while(true){
        if(aux->chave > limite) aux = aux->esquerda;
        else{
            if(aux->esquerda){
                qtd_dir = falta_contar - (1 + aux->esquerda->getRank());
                std::cout << qtd_dir << std::endl;
                if(n - contados== qtd_dir) break;
                else if(n - contados > qtd_dir){
                    falta_contar -= (1 + qtd_dir);
                    contados += (1+qtd_dir);
                    aux = aux->esquerda;
                }    
                else if(n - contados < qtd_dir){
                    falta_contar -= (1+ aux->esquerda->getRank()) ;
                    contados +=  (1+ aux->esquerda->getRank());
                    aux = aux->direita;
                }        
            }
            else{
                qtd_dir = falta_contar - 1;
                if(qtd_dir > 0){
                    aux = aux->direita;
                    falta_contar--;
                    contados++;
                }    
                else break; //qtd_dir = 0;
            }
        }
    }




/*     Node*        raizTemporaria = this->raiz;
    Node*        aux            = raizTemporaria;
    int          precocmp       = limite;
    bool         achou          = false;
    Node*        raizTemporaria2;
    std::string  nome;
    
    //achando a maior sub-árvore com raíz menor ou igual ao limite
    while(raizTemporaria->chave > limite){
        raizTemporaria  = raizTemporaria->esquerda;
        aux        = raizTemporaria;
    }
    //std::cout << "chave da raiz: " << aux->chave << std::endl; 
    for(int i = 0; i <= n ; i++){
        //achando o nome com a maior chave da árvore e menor ou igual que precocmp
        while(raizTemporaria->chave > precocmp){
        raizTemporaria  = raizTemporaria->esquerda;
        aux        = raizTemporaria;
        }
        while(!achou){
            //std::cout << aux->chave << std::endl;
            if(aux->chave == precocmp){
                nome           = aux->nome;
                achou          = true;
                precocmp       = aux->chave - 1;
            }else if(aux->chave < precocmp){
                if(aux->direita != nullptr){
                    if(aux->direita->chave > precocmp){
                        raizTemporaria2 = aux;
                    }
                    aux = aux->direita;  
                }else{//Se não há filho da direita, o maior é o aux
                    precocmp = (aux->chave - 1);
                    nome     = aux->nome;   
                    achou    = true;
                }
                    
            }else{//aux->chave > precocomp
                if(aux->esquerda != nullptr && aux->esquerda->chave <= precocmp){
                    aux = aux->esquerda;
                }else{
                    nome     = raizTemporaria2->nome;
                    achou    = true;
                    precocmp = raizTemporaria2->chave - 1;
                }
            }
    }
    achou    = false;
    aux = raizTemporaria;
    } */
    return aux->nome;
}
