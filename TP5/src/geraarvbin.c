#include <getopt.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// Syntax tree structure
typedef long TipoChave;
typedef struct TipoRegistro {
  TipoChave Chave;
} TipoRegistro;
typedef struct TipoNo *TipoApontador;
typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;

typedef struct prm {
  char nomesaida[200];
  int semente;
  int numno;
  FILE *saida;
  int treesize;
  int numlevel;
} prm_t;

// vetores e tamanho
int *pre_ordered;
int *in_ordered;
int *post_ordered;
int nodeCount;

void uso()
// Descricao: imprime as instrucoes de uso do programa
// Entrada:  N/A
// Saida: instrucoes
{
  fprintf(stderr, "geraexp\n");
  fprintf(stderr, "\t-o <arq>\t(arquivo de saida) \n");
  fprintf(stderr, "\t-s <num>\t(semente)\n");
  fprintf(stderr, "\t-n <num>\t(numero de nos)\n");
  fprintf(stderr, "\t-h\t(opcoes de uso)\n");
}

void parse_args(int argc, char **argv, prm_t *prm)
// Descricao: analisa a linha de comando a inicializa variaveis
// Entrada: argc e argv
// Saida: prm
{
  extern char *optarg;
  extern int optind;
  int c;
  // valores padrao
  prm->nomesaida[0] = 0;
  prm->semente = 0;
  prm->numno = 3;
  prm->numlevel = 2;
  // percorre a linha de comando buscando identificadores
  while ((c = getopt(argc, argv, "o:s:n:iph")) != EOF) {
    switch (c) {
      case 'o':
        // arquivo de saida
        strcpy(prm->nomesaida, optarg);
        break;
      case 's':
        // semente aleatoria
        prm->semente = atoi(optarg);
        srand48((long)prm->semente);
        break;
      case 'n':
        // numero de nos
        prm->numno = atoi(optarg);
        prm->numlevel = ((int)log2((double)prm->numno)) + 2;
        break;
      case 'h':
      default:
        uso();
        exit(1);
    }
  }
  // verifica apenas o nome do arquivo de saida
  if (!prm->nomesaida[0]) {
    printf("Arquivo de saida nao definido.");
    exit(1);
  }
}

void dumpTree(TipoApontador *T, int level, prm_t *prm, int parent) {
  if ((*T) != NULL) {
    for (int i = 0; i < level; i++) fprintf(prm->saida, "    ");
    fprintf(prm->saida, " %3ld (%d)\n", (*T)->Reg.Chave, level);

    // Imprime nós apontando o parent//fprintf(prm->saida, " %3ld (%d) ->%d\n", (*T)->Reg.Chave, level, parent);

    dumpTree(&(*T)->Esq, level + 1, prm, (*T)->Reg.Chave);
    dumpTree(&(*T)->Dir, level + 1, prm, (*T)->Reg.Chave);
  }
}

int createTree(TipoNo **curr, int level, prm_t *prm) {
  // create node
  (*curr) = (TipoNo *)malloc(sizeof(TipoNo));
  (*curr)->Esq = (*curr)->Dir = NULL;
  // set type
  if (drand48() > ((8.0 * (1 << level) * prm->treesize)) / (((1 << prm->numlevel) * prm->numno))) {
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
    if (prm->treesize < prm->numno) createTree(&((*curr)->Esq), level + 1, prm);
    if (prm->treesize < prm->numno) createTree(&((*curr)->Dir), level + 1, prm);
  } else {
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
  }
  return prm->treesize;
}

int pre_order(TipoApontador *t, int *array, int *n) {
  if (t != NULL) {
    array[(*n)++] = (*t)->Reg.Chave;
    if (((*t)->Esq) != NULL) pre_order(&((*t)->Esq), array, n);

    if (((*t)->Dir) != NULL) pre_order(&((*t)->Dir), array, n);
  }
  return *n;
}

int post_order(TipoApontador *t, int *array, int *n) {
  if (t != NULL) {
    if (((*t)->Esq) != NULL) post_order(&((*t)->Esq), array, n);
    if (((*t)->Dir) != NULL) post_order(&((*t)->Dir), array, n);
    array[(*n)++] = (*t)->Reg.Chave;
  }
  return *n;
}

int in_order(TipoApontador *t, int *array, int *n) {
  if (t != NULL) {
    if (((*t)->Esq) != NULL) pre_order(&((*t)->Esq), array, n);
    array[(*n)++] = (*t)->Reg.Chave;
    if (((*t)->Dir) != NULL) pre_order(&((*t)->Dir), array, n);
  }
  return *n;
}

char *ancestral(int i, int j) {
  // j and i index in post-ordered
  int jIPt = -1, iIPt = -1;

  // j and i index in pre-ordered
  int jIPr = -1, iIPr = -1;

  // gets j and i index in both arrays (pre and post ordered)

  // get j and i index in post order array
  for (int k = 0; k < nodeCount; k++) {
    if (iIPt < 0 || jIPt < 0) {
      if (post_ordered[k] == i) {
        iIPt = k;
      }
      if (post_ordered[k] == j) {
        jIPt = k;
      }
    }
    // catch i and j index in pre-order array
    if (iIPr < 0 || jIPr < 0) {
      if (pre_ordered[k] == i) {
        iIPr = k;
      }
      if (pre_ordered[k] == j) {
        jIPr = k;
      }
    }
  }
  // printf("pos: i = %d, j = %d     pre: iPr = %d, jPr = %d  \n", iIPt, jIPt, iIPr, jIPr);
  //  checks if j comes before i in post-order && j comes after i in pre-order
  char *result = (char *)malloc(5 * sizeof(char));
  if ((iIPt >= jIPt) && (iIPr <= jIPr)) {
    result = "true";
  } else {
    result = "false";
  }

  return result;
}

int main(int argc, char *argv[]) {
  TipoNo *root;
  prm_t prm;
  int i, j;

  int index = 0;

  parse_args(argc, argv, &prm);
  prm.saida = fopen(prm.nomesaida, "wt");
  prm.treesize = 0;

  createTree(&root, 0, &prm);
  dumpTree(&root, 0, &prm, -1);

  pre_ordered = (int *)calloc(prm.numno, sizeof(int));

  /******< Imprime Pré-Ordem, In-Ordem e Pós-Ordem >********/

  nodeCount = index = pre_order(&root, pre_ordered, &index);
  fprintf(prm.saida, "\n\n");
  fprintf(prm.saida, "Pré-ordered [%d]:  ", index);

  printf("Pré-ordered [%d]:  ", index);

  for (int i = 0; i < nodeCount; i++) {
    printf(" %d", pre_ordered[i]);
    fprintf(prm.saida, " %d", pre_ordered[i]);
  }
  printf("\n");
  fprintf(prm.saida, "\n");

  in_ordered = (int *)calloc(index + 1, sizeof(int));
  index = 0;
  index = in_order(&root, in_ordered, &index);
  fprintf(prm.saida, "in-ordered [%d]:  ", index);
  printf("in-ordered [%d]:  ", index);
  for (int i = 0; i < nodeCount; i++) {
    printf(" %d", in_ordered[i]);
    fprintf(prm.saida, " %d", in_ordered[i]);
  }
  printf("\n");
  fprintf(prm.saida, "\n");

  post_ordered = (int *)calloc(index + 1, sizeof(int));
  index = 0;
  index = post_order(&root, post_ordered, &index);
  fprintf(prm.saida, "post-ordered [%d]:  ", index);
  printf("post-ordered [%d]:  ", index);
  for (int i = 0; i < nodeCount; i++) {
    printf(" %d", post_ordered[i]);
    fprintf(prm.saida, " %d", post_ordered[i]);
  }
  printf("\n");
  fprintf(prm.saida, "\n\n");
  /******</ Imprime Pré-Ordem, In-Ordem e Pós-Ordem />********/

  for (int k = 0; k < prm.treesize; k++) {
    i = j = 0;
    while (i == j) {
      i = (int)(drand48() * prm.treesize);
      j = (int)(drand48() * prm.treesize);
    }
    char *result = ancestral(i, j);
    fprintf(prm.saida, "%3d testando ancestral(%2d,%2d) = %s\n", k, i, j, result);
  }

  fclose(prm.saida);
  printf("\nTest de ancestralidade no arquivo saida.txt. \n");

  return 0;
}
