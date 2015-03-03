#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void palindroma(char string[]){
	PILA *stack=NULL;
	PILA *aux=NULL;
	int i=0,incorrecto=0;
	while(string[i]!='\0'){
		if(string[i]!=' '){
			push(&stack,string[i]);
		}
		i++;
	}
	i=0;
	while(!isEmpty(stack)&&!incorrecto){
		if(top(stack)!=string[i]&&string[i]!=' ') incorrecto=1;
		if(string[i]!=' ') pop(&stack);
		i++;
	}
	
	if(incorrecto){
		printf("No es palindroma.");
	}
	else{
		printf("Es palindroma.");
	}	
}

int main(){
	
	char string[25];
	printf("Ingrese la frase a probar: \n");
	fflush(stdin);
	gets(string);
	palindroma(string);	
	
	return 0;
}
