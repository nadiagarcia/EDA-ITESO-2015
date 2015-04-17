/*
 * arboles.c
 *
 *  Created on: 17/04/2015
 *      Author: NADIAGARCIA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
	char palabra[20];
	int frecuencia;
	struct nodo *izq, *der;
} NODO;

void insertar(char *la_palabra, NODO **raiz) {
	//if( *raiz != NULL)
	if (*raiz) {
		if (strcmp((*raiz)->palabra, la_palabra) < 0)
			insertar(la_palabra, &(*raiz)->izq);
		else if (strcmp((*raiz)->palabra, la_palabra) > 0)
			insertar(la_palabra, &(*raiz)->der);
		else
			(*raiz)->frecuencia++;
	} else {
		*raiz = (NODO *) malloc(sizeof(NODO));
		(*raiz)->izq = (*raiz)->der = NULL;
		(*raiz)->frecuencia = 1;
		strcpy((*raiz)->palabra, la_palabra);
	}
}

void preOrden(NODO *raiz) {
	// r i d
	if (raiz) {
		printf("%s\t%d\n", raiz->palabra, raiz->frecuencia);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void enOrden(NODO *raiz) {
	// i r d
	if (raiz) {
		enOrden(raiz->izq);
		printf("%s\t%d\n", raiz->palabra, raiz->frecuencia);
		enOrden(raiz->der);
	}
}

void postOrden(NODO *raiz) {
	// i d r
	if (raiz) {
		postOrden(raiz->izq);
		postOrden(raiz->der);
		printf("%s\t%d\n", raiz->palabra, raiz->frecuencia);
	}
}

int main() {
	char renglon[100];
	FILE *texto = fopen("texto.txt", "r");
	NODO *arbol_letras = NULL;

	while (fgets(renglon, 100, texto)) {
		char *palabra = strtok(renglon, " ");
		while (palabra) {
			printf("insertando %s\n",palabra);
			insertar(palabra, &arbol_letras);
			palabra = strtok(NULL, " ");
		}
	}

	enOrden(arbol_letras);

	return 0;
}

