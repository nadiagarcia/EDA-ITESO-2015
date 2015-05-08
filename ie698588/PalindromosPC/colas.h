/*
 * colas.h
 *
 *  Created on: 06/03/2015
 *      Author: ie698588
 */

#ifndef COLAS_H_
#define COLAS_H_

#include <stdio.h>
#include <stdlib.h>
typedef int ELEMENTOC;
typedef struct Cola {
	ELEMENTO iValor;
	struct Cola *siguiente;
} COLA;
int isEmptyC(COLA *queue) {
	if (queue == NULL)
		return 1;
	else
		return 0;
}
void emptyC(COLA **queue) {
	if (queue != NULL) {
		COLA *aux;
		while (*queue != NULL) {
			aux = (*queue)->siguiente;
			free(*queue);
			*queue = aux;
		}
	}
}
ELEMENTO topC(COLA *queue) {
	if (queue == NULL) {
		printf("Error, cola vacia");
		return -1; //valor que indica un error al hacer top
	}
	return queue->iValor;
}
ELEMENTO popC(COLA **queue) {
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
void pushC(COLA **queue, ELEMENTO e) {
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

#endif /* COLAS_H_ */