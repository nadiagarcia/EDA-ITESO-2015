/*
 * pracp.c
 *
 *  Created on: 03/03/2015
 *      Author: nt699567
 */
#include "pilas.h"
#include <stdio.h>

int main() {

	setvbuf(stdout,NULL,_IONBF,0);

	char operacion[100];

	int i = 0, error;

	printf("Dame la operacion a revisar:");
	gets(operacion);

	PILA *stack = NULL;

	while (operacion[i]) {
		if ((operacion[i] == '(') || (operacion[i] == '[')
				|| (operacion[i] == '{')) {
			push(&stack, operacion[i]);
		} else if (operacion[i] == ')' || operacion[i] == ']'
				|| operacion[i] == '}') {
			char par = top(stack);
			if (par == '(' && operacion[i] == ')') {
				error = 0;
			} else if (par == '[' && operacion[i] == ']') {
				error = 0;
			} else if (par == '{' && operacion[i] == '}') {
				error = 0;
			} else
				error = 1;
		}
	}

	if (error) {
		printf("La operacion esta mal formada.\n");
	} else {
		if (!isEmpty(stack))
			printf("La operacion esta mal formada.\n");
	}
	return 0;
}

