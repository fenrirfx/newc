#include <stdio.h>
#include "queue.h"

int front = -1, rear = -1;

void inicia(Queue *fila, int size){
    fila->data = malloc(sizeof(int)*size);
    fila->maxelems = 0;
    fila->nelems = 0;
    fila->size = size;
}

int isfull(Queue * fila){
    if ((front == rear + 1) || (front == 0 && rear == fila->size - 1)) return 1;
    return 0;
}

int isempty(){
    if (front == -1) return 1;
    return 0;
}

int insert(Queue *fila, int data){
    if (isfull(fila)){
        return 0;
    }
    else{
        if (front == -1) front = 0;
        rear = (rear + 1) % fila->size;
        fila->data[rear] = data;
        return data;
    }
}

int remover(Queue *fila){
    int element;
    if (isempty())
        return 0;
    else {
    
        element = fila->data[front];
        fila->data[front] = 0;

        if (front == rear) {
            front = -1;
            rear = -1;
        } 
        else {
            front = (front + 1) % fila->size;
        }
        return 1;
    } 
}

void listar(Queue *fila){
    for (int i =0; i<fila->size;i++){
        printf("%d ||",fila->data[i]);
    }
    printf("\n");
}
void limpar(Queue *fila){
    for (int i=0;i<fila->size;i++){
        fila->data[i]=0;
    }
    fila->maxelems =0;
    fila->nelems=0;
}