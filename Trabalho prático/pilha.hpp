class Pilha {
 private:
  char *c_;  // vetor que comporta pilha de caracteres;
  
  int size_; // o tamanho utilizado da pilha.
  int max_size_; // o tamanho máximo da pilha.

 public:
 
 //Cria pilha padrão (máximo 1000 caracteres).
  Pilha();
  
  //Cria pilha com máximo de tam caracteres.
  Pilha(int tam);

  // Desempilha retornando o caractere desempilhado.
  char pop();

  //Insere caractere no topo da pilha. Retorna true se inseriu com sucesso.
  bool insert(char x);

  // Retorna o elemento no topo da pilha sem desempilhar.
  char get();


  // Retorna true se a pilha estiver vazia.
  bool empty();

  //Retorna true se a pilha estiver no tamanho máximo
  bool full();

  //Retorna o tamanho atual da lista
  int size();

  // Desaloca memória e Destrói a pilha.
  ~Pilha();
};