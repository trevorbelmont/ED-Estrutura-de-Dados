// emplementar uma pilha a partir de filas circulares
// cripilha, pilhavazia, empilha, desempilha e destróipilha

// struct genérico de nó
struct nod {
  int value;
  int* next;
};

// Implementação de fila circular iterativa (não encadeada)
// (inicialmente para valores interos positivos): mas -1 é a chave de nulidade
class rQeuee {
 public:
  // cria fila circular e aloca valor arbitrário espaço de elementos
  rQeuee();

  // cria fila com maxSize = n;
  rQeuee(int n);

  // checa tamanho da fila
  bool empty();

  int getSize();

  int getMaxSize();

  // Add at end  - retorna novo iterador de end
  // não muda o iterador se falhar
  int push(int it);

  // Retira primeiro da fila e retorna seu valor
  int pop();

  // retorna valor do primeiro da fila sem destruí-lo
  int front();

  //retorna o próximo índice do vetor. Retorna "-1" se não houver espaço
  int pos();

  
  int get(int i);

  // destrói a fila-pilhada
  ~rQeuee();



  // private:
  
  
  //  Realoca e redimensiona a fila para o tamanho size. CAUTION!
  //  Procura preservar os dados e retorna true se não houver problemas.
  bool reallocate(int newSize);

  int* qeuee;   // o vetor da fila em sí de tamanho [qeuee::size].(dinâmicamente alocado)
  int maxSize;  // Atual tamanho máximo do array interno *qeuee;
  int margin;   // a quantidade de espaço preparado de antemão na criação ou realocação de size não especificada - ou indiretamente via push;

  
  int size;   // o tamanho da lista
  int first;  // o atual primeiro da fila
  int last;   // O ATUAL próximo nódulo livre  da lista circular - similar ao iterador  <qualquer_tad>.end();
};