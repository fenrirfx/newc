#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue myqueue;

int main(int argc, char const *argv[]){

    int qtd, num, buf,cont;
    do{
    printf("*****************\n");
    printf("***1 - Inicia ***\n");
    printf("***2 - Insere ***\n");
    printf("***3 - Remove ***\n");
    printf("***4 - Listar ***\n");
    printf("***5 - Limpar ***\n");
    printf("***0 - Sair   ***\n");
    printf("*****************\n");
    printf("%d %d ", myqueue.head, myqueue.tail);
    printf("Escolha: ");
    scanf("%d",&cont);
        switch(cont){
            case 1:
                printf("quantas posiçoes de fila pretende inserir?: ");
                scanf("%d",&qtd);
                start(&myqueue, qtd);
                break;
            case 2:
                printf("Insira o numero: ");
                scanf("%d",&qtd);
                if (insert(&myqueue,qtd))
                    printf("numero inserido\n");
                else
                    printf("Lista cheia\n");
                break;
            case 3:
                if (pull(&myqueue))
                    printf("Número removido\n"); 
                else
                    printf("lista vazia\n");
                break;               
            case 4:
                list(&myqueue);
                break;
            case 5:
                clean(&myqueue);
                break;
            case 0:
                exit(0);
            default:
                printf("opçao inválida");
                break;
        }
    }
    while(cont!=0);
 return 0;   
}