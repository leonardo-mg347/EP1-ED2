#include "treap.hpp"


//--------------------TNODE::------------------------------------------------------

Tnode* Tnode::insert(Tnode* noh, int c, std::string n, int p)
{
    if(noh == 0) return new Tnode(c, n , p);

    else if(c < noh->chave){
        noh->esquerda = insert(noh->esquerda, c, n, p);
    }
    else if(c > noh->chave){
        noh->direita = insert(noh->direita, c, n, p);
    }

    //Após inserir o nó com base na chave, fazemos rotações de acordo com as prioridades.
    if(getPriority(noh->esquerda) < noh->prioridade){
        noh = rotateRight(noh);
    }
    else if(getPriority(noh->direita) < noh->prioridade){
        noh = rotateLeft(noh);
    }

    return noh;
}

std::string Tnode::search(Tnode* noh, int preco)
{   if(noh){
        if(noh->chave == preco) return noh->nome;
        else if(noh->chave > preco) return search(noh->esquerda, preco);
        else if(noh->chave < preco) return search(noh->direita, preco);
    }
    return "Não encontrado";
}

void Tnode::count(Tnode* noh, int limite, int* contador)
{
    if(noh != 0){
        if(noh->chave == limite){
            (*contador)++;
        }
        else if(noh->chave < limite){
            (*contador)++;
            count(noh->direita, limite, contador);
        }  
        count(noh->esquerda, limite, contador); 
    };
    return;
}

int Tnode::find_greater(Tnode* noh,int limite)
{
    if (noh == nullptr)       return -1;
    if (noh->chave == limite) return noh->chave;
    if(noh->chave < limite){
        int maior_direita = find_greater(noh->direita, limite);
        if(maior_direita != -1) return maior_direita;
        else return noh->chave;
    }
    return find_greater(noh->esquerda, limite);
}

int Tnode::getPriority(Tnode* noh)
{
    if(noh == 0) return MAX_PRIORITY;
        else return noh->prioridade;
}

Tnode* Tnode::rotateLeft(Tnode* noh)
{
    assert(noh->direita);
    Tnode* aux = noh->direita;
    noh->direita = aux->esquerda;
    aux->esquerda= noh;

    return aux;
}

Tnode* Tnode::rotateRight(Tnode* noh)
{
    assert(noh->esquerda);
    Tnode* aux = noh->esquerda;
    noh->esquerda = aux->direita;
    aux->direita = noh;

    return aux;
}

void Tnode::V(Tnode* aux, int min, int max, int p_min, int &contador, int prof){
    if (aux == nullptr) return;

    assert(aux->chave > min && aux->chave < max); 
    if(aux->direita) assert(aux->prioridade < aux->direita->prioridade);
    if(aux->esquerda)assert(aux->prioridade < aux->esquerda->prioridade);

    contador += prof;
    
    V(aux->esquerda, min,aux->chave, aux->prioridade, contador, prof + 1);
    V(aux->direita,aux->chave, max,aux->prioridade,contador, prof + 1);

    return;    
}


//------------------Treap------------------------------------------------

void Treap::insere(int preco, const std::string& nome)
{
    int prioridade = gerarPrioridade();
    raiz = raiz->insert(raiz, preco, nome, prioridade);
}

std::string Treap::busca(int preco)
{
    return raiz->search(raiz, preco);
}

int Treap:: conta(int limite)
{
    int contador = 0;
    raiz->count(raiz, limite, &contador);
    return contador;
}

std::string Treap::nesimo(int n, int limite)
{
    int valorDoNesimo;
    for(int i = 0; i <= n; i++){
        valorDoNesimo = Tnode::find_greater(this->raiz, limite);
        limite = valorDoNesimo - 1;
    }
    return Tnode::search(this->raiz, valorDoNesimo);
}

int Treap::gerarPrioridade()
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, MAX_PRIORITY);

    return dis(gen);
}

void Treap::funcaoV(){
    int  contador = 0;
    int  prof     = 0;  

    raiz->V(raiz, 0, 1000000,raiz->prioridade, contador, prof);

    std::cout << "Soma de todas as profundidades da árvore: " << contador <<  std::endl;
};
