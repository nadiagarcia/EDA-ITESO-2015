#include <stdio.h>
#include <stdlib.h>

typedef struct numero{
	int numero;
	struct numero *siguiente;
	struct numero *anterior;
} NUMERO;

int main(){
	char x;
	int y;
	NUMERO *numero1= (NUMERO *)malloc(sizeof(NUMERO));
	numero1-> numero = 0;
	numero1-> siguiente = NULL;
	numero1-> anterior = NULL;
	NUMERO *actual = numero1;
	
	while(x != 13){
		x = getch();
		y = x - 48;
		if(y>=0 && y<=9){
		actual->siguiente = (NUMERO *)malloc(sizeof(NUMERO));
		actual ->siguiente -> anterior = actual;
		actual = actual ->siguiente;
		actual -> numero = y;
		actual -> siguiente = NULL;
		printf("%d",y);
		}
	}
	NUMERO *numero2= (NUMERO *)malloc(sizeof(NUMERO));
	numero2-> numero = 0;
	numero2-> siguiente = NULL;
	numero2->anterior = NULL;
	actual = numero2;
	printf("\ndame el numero 2\n");
	x=0;
	while(x != 13){
		x = getch();
		y = x - 48;
		if(y>=0 && y<=9){
		actual->siguiente = (NUMERO *)malloc(sizeof(NUMERO));
		actual ->siguiente -> anterior = actual;
		actual = actual ->siguiente;
		actual -> numero = y;
		actual -> siguiente = NULL;
		printf("%d",y);
		}
	}
	printf("\n y los numeros son\n");
	NUMERO *actual_num1 = numero1;
	printf("numero 1: ");
	while(actual_num1->siguiente != NULL){
		printf("%d", actual_num1->numero);
		actual_num1 = actual_num1->siguiente;
		
	}
	printf("%d",actual_num1->numero);
	
	NUMERO *actual_num2 = numero2;
	printf("\nnumero 2: ");
	
	while(actual_num2->siguiente != NULL){
		printf("%d",actual_num2->numero);
		actual_num2 = actual_num2->siguiente;
	}
	printf("%d",actual_num2->numero);
}

