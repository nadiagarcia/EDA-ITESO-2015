/*
 * arboles.c
 *
 *  Numero de veces que se repite un caracter en un archivo de texto.
 *
 *  Created on: 17/04/2015
 *      Author: ie698969
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
	char letra;
	int frecuencia;
	struct nodo *izq, *der;
} NODO;

void insertar(char la_letra, NODO **raiz) {
	//if(*raiz != NULL)
	if (*raiz) {
		if ((*raiz)->letra > la_letra) {
			insertar(la_letra, &(*raiz)->izq);
		} else if ((*raiz)->letra < la_letra) {
			insertar(la_letra, &(*raiz)->der);
		} else {
			(*raiz)->frecuencia++;
		}
	} else {
		*raiz = (NODO *) malloc(sizeof(NODO)); //Crear espacio de memoria
		(*raiz)->izq = (*raiz)->der = NULL;
		(*raiz)->frecuencia = 1;
		(*raiz)->letra = la_letra;
	}
}
void preOrden(NODO *raiz) {
	//raiz - izq - der
	if (raiz) {
		printf("%c\t%d\n", raiz->letra, raiz->frecuencia);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}
void enOrden(NODO *raiz) {
	//izq - raiz - der
	if (raiz) {
		enOrden(raiz->izq);
		printf("%c\t%d\n", raiz->letra, raiz->frecuencia);
		enOrden(raiz->der);
	}
}
void postOrden(NODO *raiz) {
	//izq - der - raiz
	if (raiz) {
		postOrden(raiz->izq);
		postOrden(raiz->der);
		printf("%c\t%d\n", raiz->letra, raiz->frecuencia);
	}
}

int main() {
	NODO *arbol_letras = NULL;
	char c;
	FILE * texto = fopen("texto.txt", "r");
	while ((c = fgetc(texto)) != EOF) {
		insertar(c, &arbol_letras);
	}
	enOrden(arbol_letras);
	return 0;
}
