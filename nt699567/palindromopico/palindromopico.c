/*
 * palindromopico.c
 *
 *  Created on: 06/03/2015
 *      Author: nt699567
 */
#include "pilas.h"
#include "colas.h"
#include <stdio.h>

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);

	char palabra[40];

	int i = 0, palindromo = 1;

	printf("Dame la frase que quieres analizar:(Sin espacios)\n");
	gets(palabra);

	PILA *stack = NULL;

	COLA *queue = NULL;

	while (palabra[i]) {
		push(&stack, palabra[i]);
		qpush(&queue, palabra[i]);
		i++;
	}

	i = 0;

	while (!isEmpty(stack) && palindromo) {
		if (top(stack) != qtop(queue)) {
			palindromo = 0;
		} else {
			pop(&stack);
			qpop(&queue);
		}
	}

	if (palindromo) {
		printf("La palabra es un palindromo.\n");
	} else {
		printf("La palabra no es un palindromo.\n");
	}

	return 1;
}

