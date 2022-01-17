#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b){

    int t = *a;
    *a = *b;
    *b = t;
}

void bubblesort(int *elems, int nelems, int (*compare)(int n1, int n2)){
    int troca=1;

      for(int i=0 ; i< nelems; i++){
        for(int j=0; j<=i; j++)
        {
            if(compare(elems[i],elems[j]))
                swap(&elems[j], &elems[i]);
        }
    }
}

int compare(int n1, int n2){

    if (n1<n2)
        return 1;
    else
        return 0;
}

int main(int argc,  char *argv[]){

    int dados[] = {4,6,3,9,1,7,5};
    int elementos = 7;

    bubblesort(dados,elementos,(int(*)(int,int))&compare);
    printf("\n\n");
    for(int i=0;i<elementos;i++){
        printf("%d ",dados[i]);
    }
}
