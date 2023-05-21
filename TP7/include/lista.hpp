#ifndef LISTA_HPP
#define LISTA_HPP

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

  // !! Sobrecarrega o operador = para Nodos A chave é atribuida e ponteiros do Nodo não são tocados.
  // Usa os casts padrões para tentar atribuir. Não altera a variável se falhar. ¬ Fora do padrão ISO C++.
  template <typename TipoRight>
  Node<Tipo> operator=(Node<TipoRight> right) const {
    Node<Tipo> converted = *this;
    try {
      converted.key = Tipo(right.key);
      return converted;
    } catch (...) {
      cout << " !! Cast não definido! A Variável não foi alterada." << endl;
    }
    return *this;
  }

  // Retorna uma versão do nodo atual , nodo<Tipo>, convertido para o nodo do tipo requisitado , Nodo<ConversionType>.
  // !Atenção: o Nodo<ConversionTipe> retornado não possui qualquer ponteiro inicializado.
  // Pela natureza diferente (e a não implementação de hierarquia) nodos de tipos diferentes não podem compartilhar ponteiros para nodos.
  template <typename ConversionType>
  operator Node<ConversionType>() const {
    Node<ConversionType> conversion;
    conversion.key = TipoRight(this->key);
    return conversion;
  }
};

// Lista encadeada de tipo genérico
template <typename Tipo>
class Lista {
 private:
  Node<Tipo> *first_;  // Ponteiro Node<Tipo> para oo início da lista (primiera posição);
  Node<Tipo> *last_;   // Ponteiro Node<Tipo> para a próxima posição OCUPADA da lista.
  int size_;           // Variável privada que designa o tamanho do lista;

 public:
  // Sobrecarrega o operador = para nodes de tipos diferentes (desde que o cast Node<tipo>(Node<TipoRight>)) tenha sido implementada.
  template <typename TipoRight>
  Node<Tipo> operator=(Node<TipoRight> right) {  // queria saber se rodava
    Node<Tipo> converted;
    converted.key = Tipo(right.key);
    return converted;  // chega a rodar
  }

  Lista() {
    first_ = last_ = new Node<Tipo>;
    size_ = 0;
  }

  // Insere no final.
  void push_back(Tipo t) {
    Node<Tipo> *aux = new Node<Tipo>;
    aux->key = t;

    if (size_ == 0) {
      last_ = first_ = aux;
    } else {
      aux->prev = last_;
      last_->next = aux;
      last_ = aux;
    }
    size_++;
  }

  // Insere no início.
  void push_front(Tipo t) {
    Node<Tipo> *aux = new Node<Tipo>;
    aux->key = t;
    if (size_ == 0) {
      first_ = last_ = aux;
    } else {
      aux->next = first_;
      first_->prev = aux;
      first_ = aux;
    }
    size_++;
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
    if (pos >= size_) {
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
  bool erase(Node<Tipo> *del) {
    if (del == nullptr) {
      return false;
    } else {
      del->prev->next = del->next;  // Emenda o ponteiro next do anterior com o do próximo
      del->next->prev = del->prev;  // Emenda o ponteiro prev do próximo com o do anterior
      return true;
    }
  }

  // Remove o elemento apontado pelo ponteiro e retorna um ponteiro pra próxima posição válida.
  //*Node<Tipo> remove(Node<Tipo> *ptr);

  // Remove e retorna uma cópia do elemento da posição, pos, do índice específico;
  Tipo remove(int pos) {}

  // Retira e retorna o último elemento.
  Tipo pop_back() {
    if (size_ <= 0) {
      Tipo nulinho;
      return nulinho;  // ¬Devolve lixo se falhar
    }
    Node<Tipo> popped = *last_;  // O node a ser retirado recebe uma cópia do nodo apontado por last_
    last_ = last_->prev;
    last_->next = nullptr;  // O ponteiro privado last_ passa ser o penúltimo (que ainda aponta o antigo último)
    delete last_->next;     // Desaloca o antigo último da lista
    size_--;                // ¬ não desalocou memória.
    return popped.key;
  }

  // Retira e retorna o primeiro elemento.
  Tipo pop_front() {
    if (size_ <= 0) {
      Tipo t;
      return t;  // ¬Devolve lixo se falhar
    }
    Node<Tipo> popped = *(first_);  // Faz cópia de first_.
    delete first_;                  // Desaloca o atual first_ (na front da lista)
    first_ = (popped.next);         // Atualiza o novo first_.
    first_->prev = nullptr;         // Atualiza o ponteiro do first para nullptr;
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

  // Lista as entradas da lista separadas pela string separadora especificada.
  /// Caso não especificado um blank space é utilizado.
  void list(string sep = "  ") {
    if (size_ <= 0) {
      cout << "!Empty List" << endl;
      return;
    }
    Node<Tipo> *it = first_;
    do {
      cout << it->key << sep;
      it = it->next;
    } while (it != nullptr);
    cout << endl;
  }

  // Agarra (uma cópia) do nodo da posição, pos, especificada. Retorna nullpointer se falhar
  Node<Tipo> *get(int pos) {
    if (pos >= size_) {
      return nullptr;
    }
    Node<Tipo> *aux = first_;  // cicla por ponteiro para evitar atribuições desnecessárias.
    for (int i = 0; i < pos; i++) {
      aux = aux->next;
    }
    return aux;
  }

  // Retorna o valor do Tipo na posição, pos, especificada. Retorna um nodo totalmente nulo, se falhar
  Tipo at(int pos) {
    if (pos >= size_) {
      Tipo nulinho;
      return nulinho;
    }
    Node<Tipo> *aux = first_;  // cicla por ponteiro para evitar atribuições desnecessárias.
    for (int i = 0; i < pos; i++) {
      aux = aux->next;
    }
    return aux->key;
  }
  // Ponteiro para o fim da lista, que é a próxima posição livre da lista. (Corresponde a last_->next)
  Node<Tipo> *end() {
    return last_->next;
  }
};

#endif