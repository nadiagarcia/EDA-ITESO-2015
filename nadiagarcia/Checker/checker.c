/*
 * checker.c
 *
 *  Created on: 03/03/2015
 *      Author: NADIAGARCIA
 */

#include "pilas.h"
#include <stdio.h>

int main() {

	char operacion[100];
	int i = 0, error = 0;
	printf("Dame la operacion a revisar\n");

	gets(operacion);

	PILA *stack = NULL;

	while (operacion[i] && !error) {
		if (operacion[i] == '(' || operacion[i] == '[' || operacion[i] == '{') {
			push(&stack,operacion[i]);
		}else if(operacion[i] == ')' || operacion[i] == ']' || operacion[i] == '}'){
			char par = top(stack);
			if(par == '(' && operacion[i] == ')')
				error = 0;
			else if(par == '[' && operacion[i] == ']')
				error = 0;
			else if (par == '{' && operacion[i] == '}')
				error = 0;
			else
				error = 1;
		}
	}

	if(error){
		printf("La operacion esta mal formada\n");
	}else{
		if(!isEmtpy(stack))
			printf("La operacion esta mal formada\n");
	}

	return 0;
}
