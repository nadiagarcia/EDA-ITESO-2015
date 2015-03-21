#include <stdio.h>
#include <stdlib.h>

typedef float ELEMENTOFLOAT;

typedef struct PilaFloat {
	ELEMENTOFLOAT iValor;
	struct PilaFloat *siguiente;
} PILAFLOAT;

int isEmptyF(PILAFLOAT *stack) {
	if (stack == NULL)
		return 1;
	else
		return 0;
}

void emptyF(PILAFLOAT **stack) {
	if (stack != NULL) {
		PILAFLOAT *aux;
		while (*stack != NULL) {
			aux = (*stack)->siguiente;
			free(*stack);
			*stack = aux;
		}
	}
}

ELEMENTOFLOAT topF(PILAFLOAT *stack) {

	if (stack == NULL) {
		printf("Error, pilaFloat vacia. Funcion top.\n");
		return -1; //valor que indica un error al hacer top
	}

	return stack->iValor;
}

ELEMENTOFLOAT popF(PILAFLOAT **stack) {

	if (*stack == NULL) {
		printf("Error, pilaFloat vacia. Funcion pop.\n");
		return -1; //valor que indica un error al hacer pop
	}

	ELEMENTOFLOAT valor;

	PILAFLOAT *aux = (*stack)->siguiente;
	valor = (*stack)->iValor;

	free(*stack);
	*stack = aux;

	return valor;
}

void pushF(PILAFLOAT **stack, ELEMENTOFLOAT e) {
	PILAFLOAT *nuevo = (PILAFLOAT *) malloc(sizeof(PILAFLOAT));
	nuevo->iValor = e;
	nuevo->siguiente = *stack;
	*stack = nuevo;
}

