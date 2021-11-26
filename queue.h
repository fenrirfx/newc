#include <stdlib.h>

typedef struct Queue {
  int *data;
  int head;
  int tail;
  int size;
} Queue;

void start(Queue *fila, int size);
void list(Queue *fila);
void clean(Queue *fila);
int insert(Queue *fila, int data);
int pull(Queue *fila);