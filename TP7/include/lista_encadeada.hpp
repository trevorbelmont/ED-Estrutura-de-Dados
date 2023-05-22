#ifndef LISTA_HPP
#define LISTA_HPP

#include <assert.h>

#include <iostream>
#include <list>
#include <string>

// não está ultilizando underline ("variable_" ) para identificar variáveis privadas.

using namespace std;

template <typename Tipo>
struct BaseNode {
 public:
  BaseNode() {  // Constructors can't be virtual
    cout << endl;
    cout << "---- A BaseNode has been created. ----" << endl;
  }
  // garante que o destrutor pai seja chamado na destruição do struct filho
  virtual ~BaseNode() {
    cout << endl;
    cout << "---- A blank BaseNode  has been destructed. ----" << endl;
  }
};

template <typename Tipo>
struct EndNode : public virtual BaseNode<Tipo> {
  BaseNode<Tipo> *prev;
  EndNode() {
    prev == nullptr;
    cout << endl;
    cout << "E E E---- An EndNode has been created. ----E E E" << endl;
  }
  virtual ~EndNode() override {
    cout << endl;
    cout << "E E E---- An EndNode has been destructed. Memory address held:" << &prev << " ----E E E" << endl;

    prev == nullptr;
    // não entendo pq, mas crash: delete prev;
  }
};

template <typename Tipo>
struct BeginNode : public virtual BaseNode<Tipo> {
  BaseNode<Tipo> *next;
  BeginNode() {
    next == nullptr;
    cout << endl;
    cout << "B B B---- An EndNode has been created. ----B B B" << endl;
  }
  virtual ~BeginNode() override {
    cout << endl;
    cout << "B B B ---- An EndNode has been destructed. Memory address held:" << &next << " ---- B B B" << endl;

    next == nullptr;
    // Não entendo pq, mas crasha: delete next;
  }
};

// Define um nodo carregando a chave do tipo <Tipo> que possui ponteiros para um próximo nodo do mesmo tipo e um anterior.
template <typename Tipo>
struct Node : public virtual BaseNode<Tipo> {
 public:  // O as váriáveis e móetodos dos tipos nodos em si são públicas. O encapsulamento dessas cabe à classe ou função que às usa.
  Tipo key;

  Node<Tipo> *prev = nullptr;
  Node<Tipo> *next = nullptr;

  Node() {
    // key = initialize(key);
    prev = next = nullptr;
  }
  Node(Tipo t) {
    key = t;
    prev = next = nullptr;
  }

  virtual ~Node() override {  // Chama tb o destrutor pai, Base Node.
    cout << "An actual Node<Tipo> has been destructed. prev: " << &prev << " next: " << &next << endl;
    next = prev = nullptr;
    delete next;
    delete prev;
  }

  // Inicializa valores que precisam ser inicializados e não vem com lixo de memória.
  // !Tipos básicos não são alterados pois já possuem conteúdo, ainda que não determinado (lixo de memória).
  /*
   Tipo initialize(Tipo t) {
     // Caso não seja necessária inicialização;
     Tipo expendable;
     try {
       expendable = Tipo(t);
       if (expendable == t) {
         cout << t << " Is Equals Tipo(t) : " << expendable << " ! It'll be casted and returned!" << endl;
         return t;
       }
     } catch (...) {  // caso alguma exceção for lançada o tipo precisa de inicialização.

       cout << t << " Is DIFFERENTfrom Tipo(: " << expendable << ") ! It'll be casted and returned!" << endl;
       return t;  // por enquanto faz nada
     }
     return t;
   }
   */

  // Sobrecarrega o operador = para nodes de tipos diferentes (desde que o cast Node<tipo>(Node<TipoRight>)) tenha sido implementada.
  // !! Os ponteiros do Nodo não são tocados.
  // Usa os casts padrões para tentar atribuir. Se falhar, retorna a variável sem alteração. ¬ Fora do padrão ISO C++.
  template <typename TipoRight>
  Node<Tipo> operator=(Node<TipoRight> right) const {
    Node<Tipo> converted;
    try {
      converted.key = Tipo(right.key);
      return converted;
    } catch (...) {  // ¬ Caso a conversão falhe, devolve nodo<Tipo> original intacto, não derruba aplicação. (Rever) ¬
      cout << " !! Cast não definido! A Variável não foi alterada." << endl;
      // Caso a conversão não esteja definida ou falhe, retorna a variável sem qualquer alteração e ponteiros intactos, this.
      return *this;
    }
  }
  template <typename ConversionType>
  Node(Node<ConversionType> nodeConversion) {
    key = static_cast<Tipo>(nodeConversion.key);
    prev = next = nullptr;
  }

  // Retorna uma versão do nodo atual , nodo<Tipo>, convertido para o nodo do tipo requisitado , Nodo<ConversionType>.
  // !Atenção: o Nodo<ConversionTipe> retornado não possui qualquer ponteiro inicializado.
  // Pela natureza diferente (e a não implementação de hierarquia) nodos de tipos diferentes não podem compartilhar ponteiros para nodos.
/*   template <typename ConversionType>
  operator Node<ConversionType>() const {
    Node<ConversionType> conversion;
    conversion.key = ConversionType(this->key);
    return conversion;
  }
 */};

// Lista encadeada de tipo genérico com no mínimo um nodo (first).
template <typename Tipo>
class Lista {
 private:
  Node<Tipo> *first_;  // Ponteiro Node<Tipo> para oo início da lista (primiera posição);
  Node<Tipo> *last_;   // Ponteiro Node<Tipo> para a próxima posição OCUPADA da lista.
  // Os pointers lista.begin() e lista.end() são calculados em tempo de execução e são dinâmicos.
  // o Ponteiro lista.end() é sempre um criado na invocação que é destruído caso não usado.

  int size_;  // Variável privada que designa o tamanho do lista;

 public:
  // Cria lista vazia com pointer no estdo original (para listas vazias):
  // last_ = first_ = new nodo_único; (ou seja, este nodo está realmente alocado e existe).
  // nodo_único->prev = nodo_único_nest = nullptr;
  Lista() {
    first_ = last_ = new Node<Tipo>();  // ponteiros apontam nullptr naturalmente
    size_ = 0;
  }

  // Insere no final.
  void push_back(Tipo t) {
    if (size_ == 0) {
      last_->key = first_->key = t;  // atribuições pedagógicas (last == first, neste caso)
    } else {                         // Aloca memória atrás para próxima entrada;
      // Cria novo nodo com valor t, prepara e o encaixa.
      Node<Tipo> *aux = new Node<Tipo>(t);
      aux->prev = last_;
      last_->next = aux;
      last_ = aux;
      last_->next = nullptr;
      aux = nullptr;
      delete aux;
    }

    size_++;
  }

  // Insere no início.
  void push_front(Tipo t) {
    if (size_ == 0) {
      first_->key = last_->key = t;  // atribuição pedagógica (first == last, neste caso)
    } else {                         // Aloca memória na frente para a nova entrada
      Node<Tipo> *aux = new Node<Tipo>(t);
      aux->next = first_;
      first_->prev = aux;
      first_ = aux;
      first_->prev = nullptr;

      aux = nullptr;
      delete aux;
    }
    size_++;
  }
  // Insere antes da posição especificada pelo *pos. Retorna false, caso falhe.
  // O elemento inserido passa a ocupar a posição, pos, especificada. Os posteriores são arredados para frente.
  bool insert(Tipo t, Node<Tipo> *pos) {
    //  -------------------- Checagens de Tipo:  ---------------------- //
    //(Compromisso: maior fortitude porém maior complexidade (overhead))//

    // Checagem do tipo do Nodo<Tipo usado como ponteiro em ponteiro *pos; // Talvez o compilador avise e isso seja excesso de zelo
    try {
      Node<Tipo> *expendable = pos;  // Tenta atribuição entre ponteiros para checar se *pos é do mesmo tipo dos ponteiros da lista. Se falhar lançará exceção.
    } catch (...) {
      cout << " Pointer Type missmatch at insertion. Syntax expected: lista<Type T>.insert(Type T, Node<Type T>)." << endl;
      // ¬ Poderia pegar exceções do sistema, das bibliotecas nativas de exceções e printar aqui...
      return false;
    }
    // O próprio compilador se encarega da checagem do Tipo t do primeiro parâmetro.
    // Pois a função foi apenas definida para o Tipo definido na inicialização da classe
    //  -------------- </ Fim dasChecagens de Tipo /> -------------- //

    if (pos == nullptr && pos != end() && pos != begin()) {
      return false;
      // Caso não seja um ponteiro válido previsto no escopo da classe
    }
    // Se a lista estiver vazia inexorávelmente aloca na primeira posição (que é first_=last_)
    else if (size_ == 0) {
      push_front(t);  // tipo void que já cresce a lista.
      return true;
    } else if (pos == first_) {  // Se for inserir no início
      push_front(t);
    } else if (pos == last_) {  // Se for inserir no fim
      push_back(t);
    }
    // Se for inserir no meio. !! a inserção abaixo NÃO SUPORTA INSERÇÃO NO COMEÇO
    else {  // aloca memória para novo nodo, posiciona, cresce e retorna true; (para posições genéricas)

      // Aloca  mais memória para o novo nodo a ser inserido.
      Node<Tipo> *nuevo = new Node<Tipo>;
      // Insere e posiciona o nuevo nuedo endereçando seus ponteiros (e valores).
      nuevo->key = t;
      nuevo->prev = pos->prev;
      nuevo->next = pos;  // Como está inserindo antes, pos passa a ser o proximo (no "índice" metafórico pos+1).

      if (pos->prev != nullptr) {   // Se havia algo antes de pós, este algo agora aponta o nuevo
        (pos->prev)->next = nuevo;  // o que vinha antes de pós, passa a apontar pra nuevo.
      }
      pos->prev = nuevo;  // a posição pós, agora movida, passa a apontar pra nuevo - que tomou seu lugar e vem antes dela
      nuevo == nullptr;   // Desaloca e libera nuevo
      delete nuevo;
      return true;
    }
  }

  // Meramente apaga o elemento de índice especifico, pos, porém sem retorná-lo. Retorna falso caso falhar em remover;
  bool erase(int pos) {
    if (pos >= size_ || pos < 0) {
      cout << "!! Trying to erase invalid Node<Tipo> index at lista<Tipo>.erase(int pos)! Index pos used:: " << pos << endl;
      cout << "List<node>.size_ = " << size_ << endl;
      return false;
      // Não pode apagar posições não alocadas ou inválidas.
    } else {
      return erase(get(pos));  // Cicla até o índice pos, agara o ponteiro para o nodo e apaga na função homõnima
      // A implementação de erase(Node<Tipo> *ponteiro) é mais segura e completa.
      // Estamos começando a centralizar as operações no código, para melhor manutenção e legibilidade.
    }
  }

  // Meramente apaga o elemento indicado pelo pointer específico sem retorná-lo. Retorna falso caso falhe.
  // Espera-se que o compilador acuse caso o parâmetro Node não seja do Tipo específico da lista.
  // Usar esta função para liberar memória que não pertence a lista possivelmente quebra a lista
  bool erase(Node<Tipo> *del) {
    if (del == end() || size_ == 0) {
      return false;
      // Não há tratamento de excção para tentar apagar ponteiros nulos
      //  Também não paga end() ou begin() quando a lista está vazia - uma vez que, neste caso, end() == last_ == first__.
    }
    // Se for apagar o primeiro, chama o push_front
    else if (del == first_) {
      pop_front();
      return true;
    }  // Terceiriza se for apagar o último
    else if (del == last_) {
      pop_back();
      return true;
    }  // Apaga APENAS NODES QUE NÃO ESTÃO NAS extremidades
    else {
      try {                                                     // try que impede o programa de quebrar se um ponteiro inǘalido for passado. checar se meia transaction não é feita.
        if (del->prev != nullptr) del->prev->next = del->next;  // Emenda o ponteiro next do anterior com o do próximo
        if (del->next != nullptr) del->next->prev = del->prev;  // Emenda o ponteiro prev do próximo com o do anterior
        delete del;
        size_--;
        return true;
      } catch (...) {
        cout << "invalid pointer in erase. press keys to continue." << endl;
        string s;
        cin >> s;
        return false;
      }
    }
  }
  bool empty() {
    return (size_ == 0);  // ¬ last == first é só test. é perigoso e não preciso
  }

  void clean() {
    while (!empty()) {
      pop_front();
    }
  }

  // Remove o elemento apontado pelo ponteiro e retorna um ponteiro pra próxima posição válida.
  //*Node<Tipo> remove(Node<Tipo> *ptr);

  // Remove o nodo especificado pelo ponteiro<Nodo> *del retornando o ponteiro para próxima entrada.
  // Naturalmente retorna nullptr quando não há mais próximas entradas;
  Node<Tipo> *remove(Node<Tipo> *del) {
    Node<Tipo> *nextValid = del->next;
    if (erase(del)) {  // se remover alguma coisa, se encarrega de diminuir o tamanho da lista.
      return nextValid;
    } else {
      return nullptr;
    }
  }

  // Retira e retorna o último elemento.
  Tipo pop_back() {
    if (size_ == 0) {
      Tipo nullinho;
      cout << "!! Pop _front em lista vazia. Lixo de memória não inicializada será retornado!  " << nullinho << endl;

      return nullinho;  // ¬Devolve lixo se falhar
    }
    Node<Tipo> popped = *last_;  // O node a ser retirado recebe uma cópia do nodo apontado por last_
                                 // O ponteiro privado last_ passa ser o penúltimo (que ainda aponta o antigo último)
    if (size_ > 1) {             // Se não é o último da lista (portanto, se last-prev é válido)
      last_ = last_->prev;
      delete last_->next;     // Desaloca o antigo último da lista
      last_->next = nullptr;  // Atualiza para nullptr o pointer next da nova última posição da lista

    } else if (size_ == 1) {
      delete last_;
      last_ = first_ = nullptr;
    }
    size_--;  // ¬ não desalocou memória.
    return popped.key;
  }

  // Retira e retorna o primeiro elemento. Retorna lixo se estiver vazio.
  Tipo pop_front() {
    if (size_ == 0) {  // Se estiver vazio retorna lixo.
      Tipo nullinho;
      cout << "!! Pop _front em lista vazia. Lixo de memória não inicializada será retornado!  " << nullinho << endl;
      return nullinho;              // ¬Devolve lixo se falhar
    }                               // se não for o último
    Node<Tipo> popped = *(first_);  // Faz cópia de first_.
    delete first_;                  // Desaloca o atual first_ (na front da lista)

    if (size_ > 1) {
      first_ = (popped.next);  // Atualiza o novo first_ para a próxima entrada.
      first_->prev = nullptr;  // Atualiza o ponteiro do first para nullptr;
    } else if (size_ == 1) {   // Se for a única entrada na lista
      first_ = last_ = nullptr;
    }
    size_--;

    return popped.key;
  }

  // Retorna e remove o elemento da posição pos;
  // Tipo pop(int pos);

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

  // Agarra o ponteiro para o nodo da posição, pos, especificada. Retorna nullpointer se falhar
  // Se o índice for igual ao tamanho da lista, retorna list.end().
  Node<Tipo> *get(int pos) {
    // Checa se índice dado é inválido. Ou seja, está fora do escopo atual da lista ou é negativo.
    if ((pos > size_) || (pos < 0)) {
      return nullptr;
    } else if (pos == size_) {
      return end();
      // retorna lista<Tipo>.end(), caso o índice pos seja igual ao tamanho da lista
      // O método list<Tipo>.end() semrpe ajeita o ponteiro<Tipo> end().prev para apontar para list<Tipo>.back(), ou seja last_)
    }
    // O índice, pos, informado é um índice previsto e válido.
    else {
      Node<Tipo> *aux = first_;  // cicla por ponteiro para evitar atribuições desnecessárias.
      for (int i = 0; i < pos; i++) {
        aux = aux->next;
      }
      return aux;
    }
  }

  // Retorna o uma cópia da chave posição índice, pos, especificada. Retorna um Tipo totalmente nulo, se falhar
  Tipo at(int pos) {
    // Checa se índice dado é inválido. Ou seja, está fora do escopo atual da lista ou é negativo.
    if ((pos >= size_) || (pos < 0)) {
      Tipo nulinho;
      return nulinho;
    }
    Node<Tipo> *aux = first_;  // cicla por ponteiro para evitar atribuições desnecessárias.
    for (int i = 0; i < pos; i++) {
      aux = aux->next;
    }
    Tipo copia = aux->key;  // Copia o valor da chave do Tipo  e retorna
    return copia;
  }

  // Retorna um ponteiro para a primeira posição da lista. A private ls.first_
  // Não garante a validade do ponteiro - caso a lista esteja vazia, por exemplo.
  Node<Tipo> *front() {
    return first_;
  }
  // Ponteiro para o início da lista. Muito similar a lista.front() pois aponta a private ls.first_;
  // Não garante a validade do ponteiro - caso a lista esteja vazia por exemplo.
  Node<Tipo> *begin() {
    if (size_ == 0) {  // Retorna first_ com os ponteiros de first no estado original: first.next = last e first.prev = first;
      // first_ = last_; // checar se o estado empty original é matido após esvaziar
      first_ = nullptr;
      first_->next = last_;
      first_->prev = nullptr;
      return first_;
    } else {
      return first_;
    }
  }

  // Retorna o ponteiro para última posição OCUPADA da lista, ou o ponteiro last nullo, se alista estiver vazia.
  //. I.e. aponta a variável encapsulada privada ls.last_ - sem garantir a da chave dela,caso a lista esteja vazia ou a chave não tenha sido inicializado.
  Node<Tipo> *back() {
    return last_;
  }

  // Ponteiro para o fim da lista, que é a próxima posição livre da lista. (Não corresponde a Corresponde a last_->next)
  Node<Tipo> *end() {
    Node<Tipo> *temp_end = new Node<Tipo>();  // é liberado automaticamente sem um destrutor explícito? ¬¬
    temp_end->prev = last_;                   // o last em si por enquanto não aponta end;
    return temp_end;
  }

  ~Lista() {
    clean();
    delete first_;
    delete last_;
  }
};

#endif