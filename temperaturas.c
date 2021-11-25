#include <stdio.h>
#include <stdlib.h>

float *vet = NULL;
float media=0.0;
int qtd,i=0,cont=0;

void inserir(float *vet,int qtd){
    int tmp;
    tmp = i;
    for (i;i<qtd+tmp;i++){
        printf("Insira a temperatura: ");
        scanf("%f",&vet[i]);
        media +=vet[i];
        cont++;
    }
}

int main(){
    printf("Numero de posiçoes necessárias?: ");
    scanf("%d",&qtd);

    vet = (float*) malloc(qtd*sizeof(float));

    if (vet){
        inserir(vet,qtd);
        do {
            printf("Memória cheia!!\n");
            printf("Quantas posiçoes pretende inserir(0 para sair):");
            scanf("%d",&qtd);
            if (qtd>0){
                vet = (float*) realloc(vet,qtd*sizeof(float));
            }
            inserir(vet,qtd);
        }while(qtd!=0);
    }
    else
        printf("memória insuficiente!");
    
    media = media/cont;
    vet[cont]=media;
    
    /*for (i=0;i<1000;i++){
        printf("%d",vet[i]);
        vet = realloc(vet,1*sizeof(int)); 
    }*/

    /*do{
        printf("insira a temperatura(0 para sair): ");
        scanf("%d",&tmp);

        if (vet == NULL){
            vet = (int*) calloc(x,sizeof(int));
            vet[i]=tmp;
            media+=tmp;
            cont++;
        }
        else{
            vet = realloc(vet,2*sizeof(int));
            vet[i]=tmp;
            media+=tmp;
            cont++;
        }
        if (tmp==0){
            media=media/(cont-1);
            vet[i]=media;
            break;
        }
        i++;
    }  
    while(tmp!=0);
    */
    for(int j=0;j<=cont;j++){
        printf(" %.3f ||",vet[j]);
    }
    printf("\na média é: %.3f ",media);

    free(vet);
    vet == NULL;
}