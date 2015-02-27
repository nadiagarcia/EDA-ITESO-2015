#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//cc     polinomio.c -lm  -o polinomio && ./polinomio
typedef struct POLY {
	//char variable;
	int exponent;
	int coef;
	struct POLY *next;
} POLY;

int main () {
	int total = 0;
	int temp = 1;
	char var = 'X';
	POLY *current, *new;
	POLY *start = NULL;

	printf ("Polinomios: By Felipe Escoto\n");
	while (temp != 0) { 
		new = (POLY *) malloc (sizeof (POLY));
		new->next = NULL;
		printf ("Coeficiente: ");
		scanf ("%d", &new->coef);
		printf ("Exponente: ");
		scanf ("%d", &new->exponent);
		temp = -1;
		
		if (start == NULL) {
			start = new;
		} else {
			current = start;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = new;
		}
		while (temp != 0 && temp != 1) {
			printf ("Otro termino? [1/0]: ");
			scanf ("%d", &temp);
		}
	}
	
	printf ("Evaluar con x = ");
	scanf ("%d", &temp);
	
	current = start;
	while (current != NULL) {
		total = total + pow (temp, current->exponent) * current->coef;
		current = current->next;
	}
	printf ("Total: %d\n", total);
	return 0;	
}	
