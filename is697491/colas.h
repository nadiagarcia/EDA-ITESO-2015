/*
 * colas.h
 *
 *  Created on: Feb 26, 2015
 *      Author: ngarcia
 */

#include <stdio.h>
#include <stdlib.h>

typedef int q_ELEMENTO; 

typedef struct Cola {
	q_ELEMENTO iValor;
	struct Cola *siguiente;
} COLA;

int q_isEmpty(COLA *queue) {
	if (queue == NULL)
		return 1;
	else
		return 0;
}

void q_empty(COLA **queue) {
	if (queue != NULL) {
		COLA *aux;
		while (*queue != NULL) {
			aux = (*queue)->siguiente;
			free(*queue);
			*queue = aux;
		}
	}
}

ELEMENTO q_top(COLA *queue) {
	if (queue == NULL) {
		printf ("Error, cola vacia");
		return -1; //valor que indica un error al hacer top
	}
	return queue->iValor;
}

ELEMENTO q_pop(COLA **queue) {

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

void q_push(COLA **queue, ELEMENTO e) {
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

