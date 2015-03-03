#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void check_par(char formula[]){
	int i=0,error=0,incorrecto=0;
	PILA *stack=NULL;
	while(formula[i] != '\0'){
		error = 0;
		if(formula[i] == '(' || formula[i] == '[' || formula[i] == '{'){
			push(&stack, formula[i]);
		}
		else if(formula[i] == ')' || formula[i] == ']' || formula[i] == '}'){
			char par = top(stack);
			if(par == '(' && formula[i] == ')') error = 1, pop(&stack);
			else if(par == '[' && formula[i] == ']') error = 1, pop(&stack);
			else if(par == '{' && formula[i] == '}') error = 1, pop(&stack);
			else{ incorrecto = 1, error = 1;}
		}
		i++;
	}
	
	if(incorrecto||!isEmpty(stack)){
		printf("No es valida.");
	}
	else{
		printf("Valida.");
	}
	
}

int main(){
	
	char formula[40]={};
	printf("Ingrese la formula: \n");
	fflush(stdin);
	gets(formula);
	check_par(formula);	
	
	return 0;
}
