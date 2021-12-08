#include <stdio.h>
#include <stdlib.h>

struct elementoLista {
    int data;
    struct elementoLista *proxno;
};
typedef struct elementoLista elemento;

int vazia(elemento *lista){
    if (lista->proxno == NULL)
        return 1;
    else
        return 0;
}

void inicia(elemento *lista){
    lista->proxno = NULL;
}

void limpar(elemento *lista){
    if(!vazia(lista)){
        elemento *proxNo, *actual;
        actual = lista->proxno;
        while(actual != NULL){
            proxNo = actual->proxno;
            free(actual);
            actual = proxNo;
        }
    }
}

void mostrar(elemento *lista){
    if (vazia(lista)){
        printf("a lista está vazia!\n");
        return;
    }
    elemento *tmp;
    tmp = lista->proxno;

    while(tmp != NULL){
        printf("%d |",tmp->data);
        tmp = tmp->proxno;
    }
    printf("\n");
}

void inserirI(elemento *lista){
    elemento *novo = (elemento*)malloc(sizeof(elemento));
    if(!novo){
        printf("sem memória disponível!!");
        exit (1);
    }
    printf("insira o valor: ");
    scanf("%d",&novo->data);

    elemento *anterior = lista->proxno;
    lista->proxno = novo;
    novo->proxno = anterior;
}

void inserirF(elemento *lista){
    elemento *novo = (elemento*)malloc(sizeof(elemento));
    if(!novo){
        printf("sem memória disponível!!");
        exit (1);
    }
    printf("insira o valor: ");
    scanf("%d",&novo->data);
    novo->proxno = NULL;

    if (vazia(lista))
        lista->proxno = novo;
    else{
        elemento *tmp = lista->proxno;
        while(tmp->proxno != NULL){
            tmp = tmp->proxno;
        }
        tmp->proxno = novo;     
    }
}

void opcao(elemento *list, int opt){
    switch(opt){
        case 0:
            limpar(list);
            break;
        case 1:
            mostrar(list);
            break;
        case 2:
            inserirI(list);
            break;
        case 3:
            inserirF(list);
            break;
        case 4:
            inicia(list);
            break;
        default:
            printf("opção inválida!!\n");
            break;
    }
}

int menu(){
    int opt;

    printf("***********************\n");
    printf("*****0 - sair      ****\n");
    printf("*****1 - mostrar   ****\n");
    printf("*****2 - inserir I ****\n");
    printf("*****3 - inserir F ****\n");
    printf("*****4 - limpar    ****\n");
    printf("***********************\n");
    printf("escolha: ");
    scanf("%d",&opt);

    return opt;
}

int main(int argc, char const *argv[]){
   elemento *lista = (elemento*) malloc(sizeof(elemento));

    if (!lista){
        printf("sem memória disponivel");
        exit(1);
    }
    int opt;

    do{
        opt = menu();
        opcao(lista,opt);
    }while (opt);

    free(lista);
    lista=NULL;

    return 0;
}