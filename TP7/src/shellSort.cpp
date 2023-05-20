#include <iostream>
#include <list>
#include <string>

// não está ultilizando underline ("variable_" ) para identificar variáveis privadas.

using namespace std;

// Define um nodo carregando a chave do tipo <Tipo> e possui ponteiros para um próximo e um anterior.
template <typename Tipo>
struct Node {
  Tipo key;
  Node<Tipo> *prev = nullptr;
  Node<Tipo> *next = nullptr;
};

// Lista encadeada de tipo genérico
template <typename Tipo>
class Lista {
 private:
  Node<Tipo> *first;  // Ponteiro Node<Tipo> para oo início da lista (primiera posição);
  Node<Tipo> *last;   // Ponteiro Node<Tipo> para a próxima posição OCUPADA da lista.

  int size_;  // Variável privada que designa o tamanho do lista;

 public:
  Lista() {
    first = last = new Node<Tipo>;
    size_ = 0;
  }

  // Insere no final.
  void push_back(Tipo t) {
    Node<Tipo> *aux = new Node<Tipo>;
    aux->key = t;

    if (size_ == 0) {
      last = first = aux;
    } else {
      aux->prev = last;
      last->next = aux;
      last = aux;
    }
    size_++;
  }

  // Insere no início.
  void push_front(Tipo t) {
    Node<Tipo> *aux = new Node<Tipo>;
    aux->key = t;
    if (size_ == 0) {
      first = last = aux;
    } else {
      aux->next = first;
      first->prev = aux;
      first = aux;
    }
    size_++;
  }
  // Retorna um ponteiro para a posição especificada. Retorna nullptr caso falhar.
  Node<Tipo> *get(int pos) {
    int i = 0;
    Node<Tipo> *it = first;
    for (int i = 0; i < pos; i++) {  // percorre a lista só até a posição i
      it = it->next;
    }
  }
  // Insere antes da posição especificada pelo ponteiro do segundo argumento. Retorna false, caso falhe.
  bool insert(Tipo t, Node<Tipo> *pos) {
    if (pos == nullptr) {
      return false;
    }
    // Aloca  mais memória para o novo nodo a ser inserido.
    Node<Tipo> *nuevo = new Node<Tipo>;
    // Insere e posiciona o nuevo nuedo endereçando seus ponteiros (e valores).
    nuevo->key = t;
    nuevo->prev = pos->prev;
    nuevo->next = pos;  // Como está inserindo antes, pos passa a ser o proximo (no "índice" metafórico pos+1).

    pos->prev->next = nuevo;  // Endereça o antigo vizinho anterior de pós.
    pos->prev = nuevo;        // Atualiza o ponteiro pro vizinho prévio (de pós).

    return true;
  }

  // Meramente apaga o elemento de índice especifico, pos, porém sem retorná-lo. Retorna falso caso falhar em remover;
  bool erase(int pos) {
    if (pos >= size) {
      return false;
    } else {
      Node<Tipo> *del = get(pos);   // O Node<Tipo> a ser deletado.
      del->prev->next = del->next;  // Emenda o ponteiro next do anterior com o do próximo
      del->next->prev = del->prev;  // Emenda o ponteiro prev do próximo com o do anterior
      delete get(pos);
      return true;
    }
  }

  // Meramente apaga o elemento indicado pelo pointer específico sem retorná-lo. Retorna falso caso falhe.
  // bool erase(Node<Tipo> *ptr);

  // Remove o elemento apontado pelo ponteiro e retorna um ponteiro pra próxima posição válida.
  //*Node<Tipo> remove(Node<Tipo> *ptr);

  // Remove e retorna uma cópia do elemento da posição, pos, do índice específico;
  Tipo remove(int pos);

  // Retira e retorna o último elemento. 
  Tipo pop_back() {
    if (size_ <= 0) {
      Tipo nulinho;
      return nulinho; // ¬Devolve lixo se falhar
    }
    Node<Tipo> popped = *last;  // O node a ser retirado recebe uma cópia do nodo apontado por last
    last = last->prev;          // O ponteiro privado last passa ser o penúltimo (que ainda aponta o antigo último)
    delete last->next;          // Desaloca o antigo último da lista
    size_--;                    // ¬ não desalocou memória.
    return popped.key;
  }

  // Retira e retorna o primeiro elemento. 
  Tipo pop_front() {
    if (size_ <= 0) {
      Tipo t;
      return t; // ¬Devolve lixo se falhar
    }
    Node<Tipo> popped = *(first);  // Faz cópia de first.
    delete first;                  // Desaloca o atual first (na front da lista)
    first = (popped.next);         // Atualiza o novo first.
    size_--;
    // ¬¬ Acho que é porque node poppoed está alocado estáticamente

    return popped.key;
  }

  // Retorna e remove o elemento da posição pos;
  Tipo pop(int pos) {
  }

  // Retorna o tamanho atual da lista;
  int size() {
    return size_;
  }

  // Retorna o nodo da posição, pos, especificada. Retorna um nodo totalmente nulo, se falhar
  Node<Tipo> at(int pos) {
    if (pos > size) {
      return nullptr;
    }
    int i = 0;
    Node<Tipo> aux = first;
    while (aux != end()) {
      aux = aux->next;
    }
  }

  // Ponteiro para o fim da lista, que é a próxima posição livre da lista. (Corresponde a last->next)
  Node<Tipo> *end() {
    return last->next;
  }
};
