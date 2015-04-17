/*
 * arboles.c
 *
 *  Numero de veces que se repite una palabra en un archivo de texto.
 *
 *  Created on: 17/04/2015
 *      Author: ie698969
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
	char palabra[20];
	int frecuencia;
	struct nodo *izq, *der;
} NODO;

void insertar(char* la_letra, NODO **raiz) { //Cambiar
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
		(*raiz)->palabra = la_letra; //Usar str copy
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
	char renglon[100];
	FILE * texto = fopen("texto.txt", "r");
	//while ((c = fgetc(texto)) != EOF) {
	//	insertar(c, &arbol_letras);
	//}
	while (fgets(renglon, 100, texto)) {
		char *palabra = strtok(renglon, " ");
		while (palabra) {
			printf("Insertando %s\n", palabra);
			insertar(palabra, &arbol_letras);
			palabra = strtok(NULL, " ");
		}
	}
	enOrden(arbol_letras);
	return 0;
}
