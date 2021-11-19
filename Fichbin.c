#include <stdio.h>
#include <stdlib.h>


int main (){

    int n;
    int i;
    char buffer[1024];
    int f=10;
    int x=13;

    FILE *arq;
    arq = fopen("/home/vieira/Programas/teste.dat","rb+");

    if (arq!=NULL){

        fseek (arq,0,SEEK_END);
        n = ftell(arq)/sizeof(int);
        printf("o ficheiro tem %d bytes",n);
        rewind(arq);

        n = fread(buffer,sizeof(int),1024,arq);
        for (i=0;i<=(n*sizeof(int))+1;i++){
            printf("\n%d", buffer[i]);
            if(buffer[i] == f){
                //printf("ok");
                fseek(arq,-2,SEEK_CUR);
                fwrite(&x,sizeof(char),1,arq);
                //fseek(arq,0,SEEK_CUR);
                //fwrite(&f,sizeof(char),1,arq);
                //fseek(arq,(n*sizeof(int))+2,SEEK_SET);
                //fwrite(&f,sizeof(char),1,arq);
            }
        }



        //while(!feof(arq)){


            /*result = fread(buffer,sizeof(int),1,arq);
            b = ("%c",buffer[i]);
            i++;
            if (b==f){
                fseek(arq,1,SEEK_CUR);
                fwrite(&x,sizeof(int),1,arq);

            }*/
            //fseek(arq,n*3,SEEK_SET);
            //fwrite(&x,sizeof(int),1,arq);
        //}
    }
    else
        printf("Houve um problema a abrir o arquivo!");

    fclose(arq);
return 0;
}
