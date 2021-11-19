#include <stdlib.h>

typedef struct IntStacks {
  int *data;
  int maxelems;
  int nelems;
} IntStack;

void init(IntStack *intstack, int size);
int hasElems(IntStack *intstack);
int push(IntStack *intstack, int data);
int pop(IntStack *intstack);
