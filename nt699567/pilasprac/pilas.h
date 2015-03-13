/*
 * pilas.h
 *
 *  Created on: 03/03/2015
 *      Author: nt699567
 */

#ifndef PILAS_H_
#define PILAS_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int ELEMENTO;

typedef struct Pila {
	ELEMENTO iValor;
	struct Pila *siguiente;
} PILA;

int isEmpty(PILA *stack) {
	if (stack == NULL)
		return 1;
	else
		return 0;
}

void empty(PILA **stack) {
	if (stack != NULL) {
		PILA *aux;
		while (*stack != NULL) {
			aux = (*stack)->siguiente;
			free(*stack);
			*stack = aux;
		}
	}
}
ELEMENTO top(PILA *stack) {

	if (stack == NULL) {
		printf("Error, pila vacia");
		return -1; //valor que indica un error al hacer top
	}

	return stack->iValor;
}
ELEMENTO pop(PILA **stack) {

	if (*stack == NULL) {
		printf("Error, pila vacia");
		return -1; //valor que indica un error al hacer top
	}

	ELEMENTO valor;

	PILA *aux = (*stack)->siguiente;
	valor = (*stack)->iValor;

	free(*stack);
	*stack = aux;
	return valor;
}

void push(PILA **stack, ELEMENTO e) {
	PILA *nuevo = (PILA *) malloc(sizeof(PILA));
	nuevo->iValor = e;
	nuevo->siguiente = *stack;
	*stack = nuevo;
}

#endif /* PILAS_H_ */
