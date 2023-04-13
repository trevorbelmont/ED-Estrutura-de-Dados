// Header de uma filas circular dinâmica capaz de se reconfigurar como uma pilha.
// o void FiFo2LiFo descarrega (pop) toda a fila em container temporário e reinfilera, push, na ordem LiFo.

// Implementação de fila circular iterativa (não encadeada)
// (inicialmente para valores interos positivos): -1 pode ser usado como uma chave de nulidade
class rQeuee {
 public:
  // cria fila circular e aloca valor arbitrário espaço de elementos
  rQeuee();

  // cria fila com maxSize = n;
  rQeuee(int n);

  // checa tamanho da fila
  bool empty();

  // retorna o tamanho atual
  int getSize();

  // retorna o número de espaços já alocados
  int getMaxSize();

  // Add at end  - retorna novo iterador de end
  // não muda o iterador se falhar
  int push(int it);

  // Retira primeiro da fila e retorna seu valor
  int pop();

  // retorna valor do primeiro da fila sem destruí-lo
  int front();

  // Reconfigura o TAD fazendo as entradas já armazenadas da lista FiFo funcionarem como LiFo.
  // ( 2n: pois faz o pop da fila interira, seguido do push dela toda.
  void Fifo2Lifo();

  // Lista a fila circular horizontalmente (apenas valores alocados e first to last)
  void list();

  // destrói a fila-pilhada
  ~rQeuee();

  private:
  //   Realoca e redimensiona a fila para o tamanho size. CAUTION!
  //   Procura preservar os dados e retorna true se não houver problemas.
  bool reallocate(int newSize);

  // retorna o próximo índice do vetor. Retorna "-1" se não houver espaço
  int pos();


  // retorna o valor da posição i na fila. 
  // Inútil para o usuário
  int get(int i);

  int* qeuee;  // o vetor da fila em sí de tamanho [qeuee::size].(dinâmicamente alocado)
  // int* temp;   //

  int maxSize;  // Atual tamanho máximo do array interno *qeuee;
  int margin;   // a quantidade de espaço preparado de antemão na criação ou realocação de size não especificada - ou indiretamente via push;

  int size;   // o tamanho da lista
  int first;  // o atual primeiro da fila
  int last;   // O ATUAL próximo nódulo livre  da lista circular - similar ao iterador  <qualquer_tad>.end();
};