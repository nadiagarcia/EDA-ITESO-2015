/*
 * palin.c
 *
 *  Created on: 05/03/2015
 *      Author: StarOfDeath
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	char Palin[30];
	int i = 0, noval = 0;
	printf("introduzca la palabra a revisar");
	fflush(stdin); //recordar usar esto
	gets(Palin);
	PILA *stack = NULL; // RECORDAR PONER NULL o falla.

	while (Palin[i] != '\0') { //no fin de cadena
		if (Palin[i] != ' ') { //espacios
			push(&stack, Palin[i]);
		}
		i++;
	}
	i = 0;
	while (!isEmpty(stack) && !noval) { //comprobar si se vacio la pila
		if (top(stack) != Palin[i] && Palin[i] != ' ')
			noval = 1;
		if (Palin[i] != ' ')
			pop(&stack);
		i++;
	}
	empty(&stack);
	if (noval)
		printf("%s No es Palindromo\n", Palin); //impresion de respuestas y si es valido o no
	else
		printf("%s Si es un Palindromo\n", Palin);
	return 0;
}
