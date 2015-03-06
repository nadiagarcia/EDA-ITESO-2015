/*
 * colas.h
 *
 *  Created on: Feb 26, 2015
 *      Author: ngarcia
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ELEMENTO;

typedef struct Cola {
	ELEMENTO iValor;
	struct Cola * siguiente;
} COLA;

int isEmptyQ(COLA *queue) {
	if (queue == NULL)
		return 1;
	else
		return 0;
}

void emptyQ(COLA **queue) {
	if (queue != NULL) {
		COLA *aux;
		while (*queue != NULL) {
			aux = (*queue)->siguiente;
			free(*queue);
			*queue = aux;
		}
	}
}

ELEMENTO topQ(COLA *queue) {
	if (queue == NULL) {
		printf("Error, cola vacia");
		return -1; //valor que indica un error al hacer top
	}
	return queue->iValor;
}

ELEMENTO popQ(COLA **queue) {

	if (*queue == NULL) {
		printf("Error, cola vacia");
		return -1; //valor que indica un error al hacer top
	}

	ELEMENTO valor;

	COLA *aux = (*queue)->siguiente;
	valor = (*queue)->iValor;

	free(*queue);
	*queue = aux;

	return valor;
}

void pushQ(COLA **queue, ELEMENTO e) {
	COLA *nuevo = (COLA *) malloc(sizeof(COLA));
	nuevo->iValor = e;
	nuevo->siguiente = NULL;

	if (*queue == NULL) {
		*queue = nuevo;
	} else {
		COLA *aux = *queue;
		while (aux->siguiente != NULL)
			aux = aux->siguiente;

		aux->siguiente = nuevo;
	}
}

