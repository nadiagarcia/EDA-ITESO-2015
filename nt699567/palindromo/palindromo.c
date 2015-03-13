/*
 * palindromo.c
 *
 *  Created on: 03/03/2015
 *      Author: nt699567
 */
#include "pilas.h"
#include <stdio.h>

int main() {

	setvbuf(stdout,NULL,_IONBF,0);

	char palabra[20];

	int i = 0;

	printf("Dame la palabra que quieres analizar:");
	gets(palabra);

	PILA *stack = NULL;

	while (palabra[i]) {
		push(&stack, palabra[i]);
		i++;
	}

	i = 0;

	while (palabra[i]) {
		if (palabra[i] == top(stack)) {
			pop(&stack);
			i++;
		}
		i++;
	}



	if(i==strlen(palabra)){
		printf("La palabra es un palindromo.\n");
	}else{
		if(!isEmpty(stack))
		printf("La palabra no es un palindromo.\n");
	}

	return 1;
}

