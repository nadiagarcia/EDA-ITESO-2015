#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct numero {
	int numero;
	struct numero *siguiente;
	struct numero *anterior;
} NUMERO;

//#define SALTO 10 //LINUX - MACOS
#define SALTO 13 //WINDOWS

void ingresarNumero(NUMERO ** numero) {
	char c = 0;
	int n;
	NUMERO *actual = *numero;

	printf("\nDame el numero\n");
	while (c != SALTO) {

		c = getch();
		n = c - 48;
		if (n >= 0 && n <= 9) {
			actual->siguiente = (NUMERO *) malloc(sizeof(NUMERO));
			actual->siguiente->anterior = actual;
			actual = actual->siguiente;
			actual->numero = n;
			actual->siguiente = NULL;

			printf("%d", n);
		}

	}
}

void imprimeNumero(NUMERO *n) {
	//ya se que el primero es cero, asi que lo ignoro

	NUMERO *actual = n->siguiente;
	while (actual != NULL) {
		printf("%d", actual->numero);
		actual = actual->siguiente;
	}

}

int main() {

	NUMERO *numero1 = (NUMERO *) malloc(sizeof(NUMERO));
	numero1->numero = 0;
	numero1->siguiente = NULL;
	numero1->anterior = NULL;

	ingresarNumero(&numero1);

	NUMERO *numero2 = (NUMERO *) malloc(sizeof(NUMERO));
	numero2->numero = 0;
	numero2->siguiente = NULL;
	numero2->anterior = NULL;

	ingresarNumero(&numero2);

	printf("\nLos numeros: \n");
	NUMERO *actual_num1 = numero1;
	NUMERO *actual_num2 = numero2;

	printf("Numero 1: ");
	imprimeNumero(numero1);

	printf("\nNumero 2: ");
	imprimeNumero(numero2);

	while(actual_num1->siguiente != NULL){
		actual_num1 = actual_num1->siguiente;
		actual_num2 = actual_num2->siguiente;
	}

	//suma
	NUMERO *resultado = (NUMERO *) malloc(sizeof(NUMERO));
	resultado->siguiente = NULL;
	resultado->anterior = NULL;
	NUMERO *actual = resultado;

	int carry = 0;
	int suma;

	while (actual_num1!=NULL||actual_num2!=NULL) {
		
		if(actual_num1==NULL){
			suma = carry + actual_num2->numero;
			actual_num2 =actual_num2->anterior;
			printf("%d\n",suma);
			
		}
		else if(actual_num2==NULL){
			suma = carry + actual_num1->numero;
			actual_num1 =actual_num1->anterior;
			printf("%d\n",suma);
		}
		else{
			suma = carry + actual_num1->numero + actual_num2->numero;
			actual_num2 =actual_num2->anterior;
			actual_num1 =actual_num1->anterior;
		}
	
		
		if (suma > 9) {
			carry = 1;
			
		} else {
			carry = 0;
		}
		
		
		actual->siguiente=(NUMERO *)malloc(sizeof(NUMERO));
		actual->siguiente->anterior=actual;
		actual=actual->siguiente;
		actual->numero=suma%10;
		actual->siguiente=NULL;
			
	}
	actual=actual->anterior;
	resultado = actual;
	
	printf("\nResultado: ");
	while (actual->anterior != NULL) {
		printf ("%d", actual->numero);
		actual = actual->anterior;
	}

	return 0;

}


