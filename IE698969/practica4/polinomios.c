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
#include <math.h> //Se agrega para operaciones matematicas
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

	//Variables
	int variableX, seleccion, salir = 1, resultado;

	while (salir) {
		printf("Calcular Polinomio.\n");
		printf("Seleccione\n");
		printf("1. Agregar termino al polinomio.\n");
		printf("2. Evaluar polinomio.\n");
		printf("3. Salir.\n");

		scanf("%d", &seleccion);

		switch (seleccion) {

		case 1:
			//Inicializar nuevo
			nuevo = (TERMINO *) malloc(sizeof(TERMINO));
			nuevo->siguiente = NULL;

			//Agregar termino al polinomio
			printf("Ingrese coeficiente.\n");
			scanf("%d", &nuevo->coeficiente);
			printf("Ingrese exponente.\n");
			scanf("%d", &nuevo->exponente);

			if (inicio == NULL) {
				inicio = nuevo;
			} else {
				actual = inicio;
				nuevo->siguiente = inicio;
				inicio = nuevo;
				printf("Elemento agregado\n");
			}
			break;

		case 2:
			//Evaluar polinomio
			resultado = 0;

			//Ingresar el valor de vaeriableX
			printf("Ingrese el valor de X\n");
			scanf("%d", &variableX);

			//Operaciones
			actual = inicio;
			if (actual != NULL) {
				while (actual->siguiente != NULL) {
					//Hacer operaciones e ir guardando en resultado
					resultado = resultado + ((pow(variableX, actual->exponente)) * (actual->coeficiente));
				}
			} else {
				printf("No hay elementos en el polinomio.");
			}
			printf("Resultado: %d", resultado);
			break;

		case 3:
			//Salir
			salir = 0;
			break;

		default:
			printf("Seleccione una opcion valida.\n");
			break;
		}

	}
	return 0;
}
