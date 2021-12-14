#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tam=0;

char ** explode(char *separator, char *string, int *explode_size){
	
	//copia a string a e aloca espaço para a mesma de acordo com o tamanho
	char *ptr = strcpy((char*)malloc(strlen(string)),string);
	int size = sizeof(char*);
	//cria o ponteiro duplo que sera retornado com uma posição de ponteiro de char
	char **str = (char**)malloc(size);
	int i=1,cont=1;
	//atribui o ponteiro da string copiada à primeira posição criada do ponteiro duplo
	str[0]= ptr;

	//enquanto a string nao for nula repete
	while(*ptr){
		if(*ptr == *separator){ //detecta quando o char do ponteiro é igual ao separator
			str = (char**) realloc(str,(++i)*size); //cria a próxima posição do ponteiro duplo
			str[i-1] = ptr+1; //atribui à posiçao seguinte a string do ponteiro p+1
			*ptr = 0; // coloca o o zero na posiçao de p ao invés do separator;
			cont++; // incrementa o cont para depois alocar ao explode_size;
		}
		ptr++; // incrementa o ptr por char
		tam++; // variável global que conta todos os caracteres da string
	}
	
	*explode_size = cont; // atribui o cont aao explode_size
	return str;
	
}
char * implode(char *separator, char **strings, int nstrings){
	int size = sizeof(char*);
	// atribui o tamanho do contador em char
	int sizes = strlen(separator)*sizeof(char);
	tam = tam*size;
	// cria o ponteiro com malloc de tam*sizes
	char *tmp = malloc(tam*sizes);
	//cria o ponteiro duplo a ser retornado com o valor total de caracteres necessários
	char **ptr = (char**) malloc(tam*sizes); 
	// ciclo que une as string
	for (int i=0;i<nstrings;i++){
		strcat(tmp,strings[i]);// contatena o string[i] para o temp	
			if (i<(nstrings-1))// testa se é a ultima posiçao para nao incrementar mais separator
			strcat(tmp,separator); // senão for adiciona o separator por contatenação ao tmp
		*ptr = ("%s",tmp); // atribui ao ponteiro a string que foi contatenada
	}
	return *ptr;
}

int main(int argc, char const *argv[])
{
char **res;
char *res_implode;
int res_size;
int i=0;

	res = explode(",", "Ana,Carlos,Francisco,Hugo,Xavier", &res_size);
		
	for(i=0; i<res_size; i++) {
		printf("|%s|\n", *(res+i));
	}
		
	res_implode = implode("::", res, res_size);
	printf("|%s|\n", res_implode);
}
