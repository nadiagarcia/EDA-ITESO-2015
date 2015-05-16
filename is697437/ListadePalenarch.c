#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct palabras {

	char palabra[50];
	struct palabras *siguiente;
	struct palabras *anterior;
} PALABRAS;

void Nueva(PALABRAS **x, FILE *stream) {
	(*x)->siguiente = (PALABRAS *) malloc(sizeof(PALABRAS));
	(*x)->siguiente->anterior = *x;
	(*x) = (*x)->siguiente;
	fflush(stdin);
	fscanf(stream, " %50s", (*x)->palabra);
	(*x)->siguiente = NULL;

}
int IrAInicio(PALABRAS **x, int contador) { //Se regresa la lista al inicio

	while ((*x)->anterior != NULL) {
		contador++;
		(*x) = (*x)->anterior;
	}
	return contador;
}
void Ordendelista(PALABRAS **x, int n) {
	char temp[50];
	int test, a, b;
	PALABRAS *comparado = (*x);
	comparado = comparado->siguiente;
	(*x) = (*x)->siguiente;
	for (a = 1; a < n; a++) {
		for (b = 0; b < n - 1; b++) {
			if (strcmp((*x)->palabra, comparado->palabra) < 0) {
				strcpy(temp, (*x)->palabra);
				strcpy((*x)->palabra, comparado->palabra);
				strcpy(comparado->palabra, temp);

			}
			comparado = comparado->siguiente;

		}
		IrAInicio(&comparado, test);
		(*x) = (*x)->siguiente;
	}
	//Se vuelve a comparar por ultima ves para la ultima palabra que no es posible comparar
	IrAInicio(&comparado, test);
	for (a = 1; a < n; a++) {
		if (strcmp((*x)->palabra, comparado->palabra) < 0) {
			strcpy(temp, (*x)->palabra);
			strcpy((*x)->palabra, comparado->palabra);
			strcpy(comparado->palabra, temp);

		}
		comparado = comparado->siguiente;
	}

}
void Imprimir(PALABRAS **x) {
	int test;
	IrAInicio(x, test);
	*x = (*x)->siguiente;
	while ((*x)->siguiente != NULL) {
		printf("%s\n", (*x)->palabra);
		*x = (*x)->siguiente;
	}
	printf("%s\n", (*x)->palabra);
}
int main() { // la lista se ordena en forma alfabetica con ASCII
	char listap[50] = { };
	int contador = 0;
	PALABRAS *palabrus = (PALABRAS *) malloc(sizeof(PALABRAS));
	strcpy(palabrus->palabra, listap);
	palabrus->siguiente = NULL;
	palabrus->anterior = NULL;
	PALABRAS *actual = palabrus;

	FILE *stream = fopen("PalabrasenARCH.txt", "r");
	do {
		Nueva(&actual, stream);
	} while (getc(stream) != EOF);
	contador = IrAInicio(&actual, contador);
	fclose(stream);
	Ordendelista(&actual, contador);
	Imprimir(&actual);
return 0;
}
