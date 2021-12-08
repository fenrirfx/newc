#include <stdio.h>
#include <stdlib.h>

typedef struct elementoLista {
    int data;
    struct elementoLista *proxno;
    struct elementoLista *anteno;
}elemento;

typedef struct listaD{
    elemento *head;
    elemento *tail;
}listad;

void init(listad *lista){
    lista->head = NULL;
    lista->tail = NULL;
}

void limpar(listad *list){
        elemento *proxNo, *actual;
        actual = list->head;
        while (actual!=NULL){
            proxNo = actual->proxno;
            free(actual);
            actual = proxNo;
            if (actual->proxno == NULL){
                free(list);
            }
        }
        free(proxNo);
        free(actual);
        
}

void insertI(elemento *list,listad *lista){
    int valor;

    elemento *novo = malloc(sizeof(elemento));
    printf("insira o valor: ");
    scanf("%d",&novo->data);

    novo->proxno = NULL;
    novo->anteno = NULL;

    if(lista->head == NULL){
        lista->head = novo;
        lista->tail = novo;
    }    
    else{
        lista->head->anteno = novo;
        novo->proxno = lista->head;
        lista->head = novo;
    }
}


void insertL(elemento *list, listad *lista){
    int valor;

    if (lista->head == NULL){
        insertI(list,lista);
        return;
    }

    elemento *novo = malloc(sizeof(elemento));
    printf("insira o valor: ");
    scanf("%d",&novo->data);

    novo->proxno = NULL;
    novo->anteno = NULL;

    if(lista->head == NULL){
        lista->head = novo;
        lista->tail = novo;
    }    
    else{
        lista->tail->proxno = novo;
        novo->anteno = lista->tail;
        lista->tail = novo;
    }
}

void show (elemento *list, listad *lista){
    elemento *tmp;
    tmp = lista->head;
    int cont=0;
    if (tmp == NULL){
        printf("lista vazia!!\n");
        return;
    }

    while (tmp != NULL){
        printf("%d ||",tmp->data);
        tmp = tmp->proxno;
        cont++;
    }
    printf("\n");
    printf("%d | %d |\n",lista->head->data, lista->tail->data);
    free(tmp);
}

void RemoveI(elemento *list, listad *lista){
    elemento *tmp, *aux;

    tmp = lista->head;
    
    if (tmp->proxno != NULL){
        aux = tmp->proxno;
        free (tmp);
        lista->head = aux;
    }
    else{
        free(tmp);
        init(lista);
    }
}

void RemoveF(elemento *list, listad *lista){
    elemento *tmp, *aux;

    tmp = lista->tail;
    
    if (tmp->anteno != NULL){
        aux = tmp->anteno;
        aux->proxno = NULL;
        free (tmp);
        lista->tail = aux;
    }
    else{
        free(tmp);
        init(lista);
    }
}

void RemoverP(elemento *list, listad *lista){
    int valor;
    elemento *tmp, *aux, *remover;

    printf("Escolha o elemento a remover:");
    scanf("%d",&valor);

    tmp = lista->head;
    while (tmp != NULL){
        if (tmp->data == valor){
            aux = tmp;
            if (tmp->proxno == NULL)
                RemoveF(list, lista);
            else if (tmp->anteno == NULL)
                RemoveI(list, lista);
            else{
                tmp->anteno->proxno = aux->proxno;
                tmp->proxno->anteno = aux->anteno;
                break;
            }
        }
        tmp = tmp->proxno;
    }
    free(aux);
}

void opcao(elemento *list, listad * lista,int opt){
    switch(opt){
        case 0:
            exit (0);
        case 1:
            show(list, lista);
            break;
        case 2:
            insertI(list,lista);
            break;
        case 3:
            insertL(list,lista);
            break;
        case 4:
            RemoveI(list, lista);
            break;
        case 5:
            RemoveF(list, lista);
            break;
        case 6:
            RemoverP(list, lista);
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
    printf("*****4 - Remover I ****\n");
    printf("*****5 - Remover F ****\n");
    printf("*****6 - Remover P ****\n");
    printf("***********************\n");
    printf("escolha: ");
    scanf("%d",&opt);

    return opt;
}

int main(int argc, char const *argv[]){
    elemento *list = malloc(sizeof(elemento));
    listad *lista = malloc(sizeof(listad));
    int resp;

    if (!list){
        printf("sem memória disponivel");
        exit(1);
    }
    init(lista);
    int opt;

    do{
        opt = menu();
        opcao(list,lista,opt);
    }while (opt);
    
    return 0;
}