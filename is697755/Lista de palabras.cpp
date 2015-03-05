#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct words{
	char palabra[15];
	int linea;
	struct words *siguiente;

}WORD;

int main(){
	
	char buff[1337];
	char * pch;
	int no_linea=1, encontrado;
	
	WORD *inicio=NULL;
	WORD *nuevo;
	WORD *actual;
	WORD *anterior;
	
	printf("Creando la lista ordenada de palabras...\n");
	FILE * archivo=fopen("Lista de palabras.txt","r");
	if (archivo==NULL) perror ("Error opening file");
	else{	
		while(fgets(buff,1337,archivo)){
			pch=strtok(buff," ");
			while(pch!=NULL){
				nuevo=(WORD*)malloc(sizeof(WORD));
				nuevo->siguiente=NULL;
				nuevo->linea=no_linea;
				strcpy(nuevo->palabra,pch);
				if(inicio==NULL){
					inicio=nuevo;
				}
				else{
					actual=inicio;
					anterior=actual;
                    encontrado = 0;
					while(actual!=NULL && !encontrado){
                        if(strcmp(actual->palabra,nuevo->palabra)<0){
                            anterior=actual;
                            actual=actual->siguiente;
                        }else{
                            encontrado = 1;
                        }
					}
                    if(actual == inicio){
                        nuevo->siguiente = inicio;
                        inicio = nuevo;
                    }else{
                        anterior->siguiente = nuevo;
                        
                        if(encontrado){
                            nuevo->siguiente = actual;
                        }
                    }
				}
				pch=strtok(NULL," ");
			}
			no_linea++;
		}
	}
	fclose(archivo);
	
	
	actual=inicio;
	printf("---------------------\n");
	while(actual!=NULL){
		printf("Palabra: %s\n",actual->palabra);
		printf("No. de linea: %d\n",actual->linea);
		printf("---------------------\n");
		actual=actual->siguiente;
	}
			
	system("PAUSE");
	return 0;
}
