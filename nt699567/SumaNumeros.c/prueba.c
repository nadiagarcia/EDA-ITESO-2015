#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct numero {
	int numero;
	struct numero *sig;
	struct numero *ant;
} NUMERO;

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);

	char c = 0;
	int n;

	NUMERO *numero1 = (NUMERO*) malloc(sizeof(NUMERO));
	numero1->numero = 0;
	numero1->sig = NULL;
	numero1->ant = NULL;
	NUMERO *actual = numero1;

	printf("Dame el primer numero:\n");
	while (c != 13) {
		c = getch();
		n = c - 48;

		if (n >= 0 && n <= 9) {
			actual->sig = (NUMERO*) malloc(sizeof(NUMERO));
			actual->sig->ant = actual;
			actual = actual->sig;
			actual->numero = n;
			actual->sig = NULL;

			printf("%d \n", n);
		}

	}

	c = 0;

	NUMERO *numero2 = (NUMERO*) malloc(sizeof(NUMERO));
	numero2->numero = 0;
	numero2->sig = NULL;

	actual = numero2;

	printf("Dame el segundo numero:\n");
	while (c != 13) {
		c = getch();
		n = c - 48;

		if (n >= 0 && n <= 9) {
			actual->sig = (NUMERO*) malloc(sizeof(NUMERO));
			actual = actual->sig;
			actual->numero = n;
			actual->sig = NULL;

			printf("%d \n", n);
		}
	}

	printf("Los numeros:\n");
	NUMERO *actual_num1 = numero1;

	printf("Numero 1:");
	while (actual_num1->sig != NULL) {
		printf("%d", actual->numero);
		actual_num1 = actual_num1->sig;
	}

	printf("\nLos numeros:\n");
	NUMERO *actual_num2 = numero2;

	printf("\nNumero 2:");
	while (actual_num2 != NULL) {
		printf("%d", actual_num2->numero);
		actual_num2 = actual_num2->sig;
	}

	NUMERO *resultado;
	int carry = 0;
	int suma;
	actual_num1=numero1;

	while (actual_num1 != NULL) {
		if (actual_num1->sig == NULL) {
			suma = carry + actual_num1->numero + actual_num2->numero;
			resultado = (NUMERO*) malloc(sizeof(NUMERO));
			resultado->sig = NULL;
			resultado->ant = NULL;
		} else {
			suma = carry + actual_num1->numero + actual_num2->numero;
			resultado->ant = (NUMERO*) malloc(sizeof(NUMERO));
			resultado = resultado->ant;
			resultado->numero = 0;
			resultado->ant = NULL;
		}

		if (suma > 9) {
			carry = 1;
			suma -= 10;
		}
		resultado->numero = suma;
		actual_num1 = actual_num1->ant;
		actual_num2 = actual_num2->ant;

	}

	printf("\nEl resultado es:");
	NUMERO *actualr = resultado;
	while (actualr != NULL) {
		printf("%d", actualr->numero);
		actualr = actualr->sig;
	}

	return 0;
}
