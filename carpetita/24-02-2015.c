#include <stdio.h>
#include <stdlib.h>

typedef struct numero{
	int numero;
	struct numero *siguiente;
} NUMERO;

int main(){
	char x;
	int y;
	NUMERO *numero1= (NUMERO *)malloc(sizeof(NUMERO));
	numero1-> numero = 0;
	numero1-> siguiente = NULL;
	NUMERO *actual = numero1;
	
	while(x != 13){
		x = getch();
		y = x - 48;
		if(y>=0 && y<=9){
		actual->siguiente = (NUMERO *)malloc(sizeof(NUMERO));
		actual = actual ->siguiente;
		actual -> numero = y;
		actual -> siguiente = NULL;
		printf("%d",y);
		}
	}
	NUMERO *numero2= (NUMERO *)malloc(sizeof(NUMERO));
	numero2-> numero = 0;
	numero2-> siguiente = NULL;
	actual = numero2;
	printf("\ndame el numero 2\n");
	x=0;
	while(x != 13){
		x = getch();
		y = x - 48;
		if(y>=0 && y<=9){
		actual->siguiente = (NUMERO *)malloc(sizeof(NUMERO));
		actual = actual ->siguiente;
		actual -> numero = y;
		actual -> siguiente = NULL;
		printf("%d",y);
		}
	}
}

