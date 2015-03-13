/*
 * ass.c
 *
 *  Created on: 05/03/2015
 *      Author: nt699567
 */
#include<stdio.h>
#include<stdlib.h>
#include "pilas.h"
#include<string.h>

int main(){

	setbuf(stdout,NULL);
	char operacion[100];
	int i=0, error=0, tamanio;
	PILA *nueva=NULL;

	printf("Ingrese la expresion a evaluar\n");
	scanf("%s",operacion);

	tamanio=strlen(operacion);

	while(i<tamanio){
		if(operacion[i]=='(' ||operacion[i]=='['||operacion[i]=='{'){
			push(&nueva,operacion[i]);
		}
		if(operacion[i]==')'||operacion[i]==']'||operacion[i]=='}'){
			if((pop(&nueva)=='('&&operacion[i]==')')||(pop(&nueva)=='['&&operacion[i]==']')||(pop(&nueva)=='{'&&operacion[i]=='}')){
				error=0;
			}
			else{
				error=1;
			}
		}

		i++;
	}
	if(error==0){
		printf("La operacion esta bien planteada\n");
	}
	else{
		printf("La formula no esta bien planteada\n");
	}

	return 0;
}


