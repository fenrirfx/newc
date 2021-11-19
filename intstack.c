#include <stdio.h>
#include "intstack.h"

void init(IntStack *intstack, int size){
  intstack-> data=malloc(sizeof(int)*size);
  intstack-> maxelems=size;
  intstack-> nelems=0;
}

int push(IntStack *intstack, int data) {
  intstack->data[intstack->nelems] = data;
  intstack->nelems++;
}

int pop(IntStack *intstack) {
  intstack->nelems--;
  intstack->data[intstack->nelems];
}

int hasElems(IntStack *intstack){
  if (intstack->nelems>intstack->maxelems){
    return -2;
  }
    if (intstack->nelems<=0){
    return -1;
  }
}