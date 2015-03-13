/*
 * poli.c
 *
 *  Created on: 27/02/2015
 *      Author: nt699567
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct poli {
	int coe;
	int exp;
	struct poli *sig;
} POLI;

int main() {

	setvbuf(stdout, NULL, _IONBF, 0);

	int v, expo = 1, choice;

	float suma = 0, termino;

	POLI *inicio = NULL, *actual, *polinomio;

	while (expo != 0) {

		polinomio = (POLI*) malloc(sizeof(POLI));

		printf("Dame el exponente:\n");
		scanf("%i", &polinomio->exp);

		printf("Dame el coeficiente:\n");
		scanf("%i", &polinomio->coe);

		if (inicio == NULL) {
			inicio = polinomio;
		} else {
			polinomio->sig = inicio;
			inicio = polinomio;
		}
		expo = polinomio->exp;

		system("cls");

		if (expo != 0)
			printf(
					"Presiona 0 en coeficiente para terminar de ingresar el polinomio.\n\n");
	}

	printf("Selecciona lo que deseas hacer:\n");
	printf("Teclea 1 para evaluar el polinomio.\n");
	printf("Teclea cualquier otro valor para salir.\n");
	scanf("%i",&choice);

	while (choice == 1) {

		printf("Valor con el que evaluaras el polinomio:\n");
		scanf("%i", &v);

		actual = polinomio;

		while (actual != NULL) {
			if (actual->exp == 0) {
				termino = actual->coe;
				suma += termino;
			} else {
				termino = actual->coe;
				expo = actual->exp;
				suma += (termino * pow(v, expo));
			}
			actual = actual->sig;
		}

		printf("\nEl valor del polinomio es: %f\n\n", suma);

		printf("Selecciona lo que deseas hacer:\n");
		printf("Teclea 1 para evaluar el polinomio.\n");
		printf("Teclea cualquier otro valor para salir.\n");
		scanf("%i",&choice);
	}
	return 0;
}
