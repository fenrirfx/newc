#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,  char *argv[]){

    FILE *arq, *arq1, *arq2;
    int i=1,j,cont=0;
    int n, num ,res;
    char ptr[100], buffer[100], buffer1[100],buffer2[100];
    char pasta[100] = "output/";
    char origem[100] = "/home/vieira/Music/";
    char ficheiro[100] = "resultado";

    arq = fopen("/home/vieira/Music/teste.dat","rb+");

    printf("Insira o numero de divisões que pretende:");
    scanf("%d",&num);

    if (arq!=NULL){
        fseek (arq,0,SEEK_END);
        n = ftell(arq);
        printf("o ficheiro tem %d bytes\n", n);
        if (num > n){
            printf("Nao é possivel a reduçao pretendida!");
            return 1;
        }
        if (num==1){
            printf("número necessita de ser maior que 1!");
            return 0;
        }
        res = n / num;
    }
    else
        printf("Houve um problema a abrir o arquivo!");
    
    rewind(arq);
    strcat(origem,pasta);

        for(j=0;j<num;j++){
            fread(buffer,1,res,arq);
            sprintf(ptr,"%d",i);
            strcpy(buffer1,ficheiro);
            strcat(buffer1,ptr);
            i++;
            strcpy(buffer2,origem);
            strcat(buffer2,buffer1);
            printf("%s\n",buffer2);
            arq1 = fopen(buffer2,"wb+");
            fwrite(buffer,1,res,arq1); 
            cont++;       
            if (cont<n && j+1 >= num){
                fread(buffer,1,n-cont,arq);
                fwrite(buffer,1,n-cont,arq1);
            }
            fclose(arq1);
                
        }
    fclose(arq);
    i=1;
    cont=0;
    for(j=0;j<num;j++){
        sprintf(ptr,"%d",i);
        strcpy(buffer1,ficheiro);
        strcat(buffer1,ptr);
        i++;
        cont++;
        strcpy(buffer2,origem);
        strcat(buffer2,buffer1);
        arq1 = fopen(buffer2,"rb");
        fread(buffer,1,res,arq1);
        arq2 = fopen("/home/vieira/Music/output/final","ab");
        fwrite(buffer,1,res,arq2);
        if (cont<n && j+1 >= num){
            fread(buffer,1,n-cont,arq1);
            fwrite(buffer,1,n-cont,arq2);
        }
    fclose(arq1);
    fclose(arq2);      
    }
}