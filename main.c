#include <stdio.h>
#include "intstack.h"

int main(int argc, char const *argv[])
{
  IntStack myStack;
  int buf,cont;
  int resp;
  char c;
  init(&myStack, 1); // alterar tamanho do array pela variável numérica, esta associada a malloc;
  do
  {
    printf("Deseja inserir ou remover elementos?(i)/(r):");
    c = getc(stdin);
    getchar();
    if (c=='i'){
      printf("Insira um elemento: ");
      scanf("%d",&resp);
      getchar();
      cont = hasElems(&myStack);
      if (cont!=-2){
        push(&myStack,resp);
      }
      else{
        printf("Pilha cheia!\n");
      }
    }
    else{
      cont = hasElems(&myStack);
      if (cont==-1){
        printf("nao existem registos\n");
      }
      else{
        buf = pop(&myStack);
        printf("Got: %d\n", buf);
      }
    }  
  } while (cont!=-1||cont!=1) ;
  
  return 0;
}
