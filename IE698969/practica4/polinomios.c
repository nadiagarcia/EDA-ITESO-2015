/*
 * polinomios.c
 *
 *	Descripcion:
 *	Realiza un programa que, usando listas, evalue
 *	un polinomio de una sola variable.
 *
 *	La entrada, proporcionada por el usuario será
 *	el coeficiente y su exponente para describir cada termino.
 *	Cuando haya terminado de ingresar los términos del polinomio
 *	el programa le preguntará con qué valores evaluará el polinomio.
 *	El programa debe de evaluar el polinomio con
 *	los valores dados por el usuario.
 *
 *  Created on: 27/02/2015
 *      Author: ie698969
 */

#include <stdio.h>
#include <stdlib.h>

//Se crea una lista para guardar cada termino del polinomio
typedef struct nodo {
	int coeficiente;
	int exponente;
	struct nodo * siguiente;
} TERMINO;

int main() {
	//Codigo eclipse
	setvbuf(stdout, NULL, _IONBF, 0);

	//Inicializar lista
	TERMINO *inicio = NULL;
	TERMINO *nuevo = (TERMINO *) malloc(sizeof(TERMINO));
	TERMINO *actual;
	TERMINO *anterior;

	//Variables
	int variableX, seleccion, salir;

	while (salir) {
		printf("Calcular Polinomio.\n");
		printf("Seleccione\n");
		printf("1.Agregar termino al polinomio.\n");

		scanf("%d", &seleccion);

		switch (seleccion) {

		case 1:
			//codigo
		break;

		default:
			printf("Seleccione una opcion valida.\n");
			break;
		}

	}
	return 0;
}
