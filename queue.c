#include <stdio.h>
#include "queue.h"

void start(Queue *fila, int size){
    fila->data = malloc(sizeof(int)*size);
    fila->tail = -1;
    fila->head = -1;
    fila->size = size;
}

int isfull(Queue * fila){
    if ((fila->head == fila->tail + 1) || (fila->head == 0 && fila->tail == fila->size - 1)) return 1;
    return 0;
}

int isempty(Queue *fila){
    if (fila->head == -1) return 1;
    return 0;
}

int insert(Queue *fila, int data){
    if (isfull(fila)){
        return 0;
    }
    else{
        if (fila->head == -1) fila->head = 0;
        fila->tail = (fila->tail + 1) % fila->size;
        fila->data[fila->tail] = data;
        return 1;
    }
}

int pull(Queue *fila){
    int element;
    if (isempty(fila))
        return 0;
    else {
    
        element = fila->data[fila->head];
        fila->data[fila->head] = 0;

        if (fila->head == fila->tail) {
            fila->head = -1;
            fila->tail = -1;
        } 
        else {
            fila->head = (fila->head + 1) % fila->size;
        }
        return 1;
    } 
}

void list(Queue *fila){
    for (int i =0; i<fila->size;i++){
        printf("%d ||",fila->data[i]);
    }
    printf("\n");
}
void clean(Queue *fila){
    for (int i=0;i<fila->size;i++){
        fila->data[i]=0;
    }
    fila->head =0;
    fila->tail=0;
}
