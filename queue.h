#include <stdlib.h>

typedef struct Queue {
  int *data;
  int maxelems;
  int nelems;
  int size;
} Queue;

void inicia(Queue *fila, int size);
void realoca(Queue *fila,int size);
void listar(Queue *fila);
void rearange(Queue *fila);
void limpar(Queue *fila);
int insert(Queue *fila, int data);
int inserir(Queue *fila, int data);
int remover(Queue *fila);

