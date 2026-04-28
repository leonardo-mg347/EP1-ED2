#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <algorithm>
#include "estrutura.hpp"

enum { RED, BLACK };

template<typename K, typename V> class RBTree;

template<typename K, typename V>
class RBNode {
  friend class RBTree<K, V>;
  private:
  K key;
  V val;
  RBNode<K, V> *left, *right;
  bool color;
  
  RBNode(K k, V v) {
    key = k;
    val = v;
    left = right = 0;
    color = RED;
  }
  
  ~RBNode() {
    if (left)
    delete left;
    if (right)
    delete right;
  }


  static bool isRed(RBNode<K, V> *c) {
    return c && c->color == RED;
  }
  
  RBNode<K, V> *rotateLeft() {
    assert(right);
    RBNode<K, V> *d = right;
    right = d->left;
    d->left = this;
    std::swap(color, d->color);
    return d;
  }
  
  RBNode<K, V> *rotateRight() {
    assert(left);
    RBNode<K, V> *d = left;
    left = d->right;
    d->right = this;
    std::swap(color, d->color);
    return d;
  }
  
  void flipColors() {
    assert(color == BLACK);
    assert(isRed(left));
    assert(isRed(right));
    color = RED;
    left->color = BLACK;
    right->color = BLACK;
  }
  
  public:
  static V search(RBNode<K, V> *c, K k) {
    if (!c)
    return V();
    
    if (k == c->key)
    return c->val;
    if (k < c->key)
    return search(c->left, k);
    return search(c->right, k);
  }
  
  static RBNode<K, V> *insert(RBNode<K, V> *c, K k, V v) {
    if (!c)
    return new RBNode<K, V>(k, v);
    
    if (k == c->key)
    c->val = v;
    else if (k < c->key)
    c->left = insert(c->left, k, v);
    else if (k > c->key)
    c->right = insert(c->right, k, v);
    
    
    if (isRed(c->right) && !isRed(c->left))
    c = c->rotateLeft();
    if (isRed(c->left) && isRed(c->left->left))
    c = c->rotateRight();
    if (isRed(c->left) && isRed(c->right))
    c->flipColors();
    
    return c;
  }
  
  static void count(RBNode<K,V>* noh, K limite, int* cont){
    if     (!noh) return;
    if     (noh->key > limite) count(noh->left, limite, cont);
    else if(noh->key == limite){
      (*cont)++;
      count(noh->left, limite, cont);
    }
    else if(noh->key < limite){
      (*cont)++;
      count(noh->right, limite, cont);
      count(noh->left, limite, cont);
    }
    return;
  }
  
  static int find_greater(RBNode<K,V>* noh, K limite){
    if(noh->key == limite) return noh->key;
    if(noh->key > limite){
      if(noh->left) return find_greater(noh->left, limite);
      else return -1;
    }
    if(noh->key < limite){
      if(noh->right){
        int valor = find_greater(noh->right, limite);
        if( valor == -1) return noh->key;
        else return valor;
      }
      else return noh->key;
    }
  }
  
  void v(RBNode* aux,int min, int max, int &contador, int prof){
    if (aux == nullptr) return;
    assert(aux->key > min && aux->key < max); 
    if(aux->right) assert(aux->right->color == BLACK);
    if(aux->color == BLACK && aux->left){
      if(aux->left->color == RED)
      {
        if(aux->left->left) assert(aux->left->left->color == BLACK);
      }
    }

    contador += prof;
    
    v(aux->left, min,aux->key, contador, prof+1);
    v(aux->right,aux->key, max, contador, prof+1);
    
    return;
  }
};

template<typename K, typename V>
class RBTree: public EstruturaDeDados{
  private:
  RBNode<K, V> *root;
  
  public:
  RBTree(): EstruturaDeDados(){
    root = 0;
    std::cout<< "Árvore Rubro-Negra Esquerdista" << std::endl;
  }
  
  ~RBTree() {
    if (root)
    delete root;
  }
  
  V search(K k) {
    return RBNode<K, V>::search(root, k);
  }

  void insert(K k, V v) {
    root = RBNode<K, V>::insert(root, k, v);
    root->color = BLACK;
  }

  void insere(int preco, const std::string& nome) override;

  std::string busca(int preco) override;

  int conta(int limite) override;

  std::string nesimo(int n, int limite) override;

  void funcaoV() override;
};
#endif