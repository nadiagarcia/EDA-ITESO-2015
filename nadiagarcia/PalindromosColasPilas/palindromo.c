/*
 * palindromo.c
 *
 *  Created on: 06/03/2015
 *      Author: NADIAGARCIA
 */

#include "pilas.h"
#include "colas.h"

int esLetra(char caracter){
	if(caracter >= 65 && caracter <= 90)
		return 1;
	else if(caracter >= 97 && caracter <= 122)
		return 1;
	else
		return 0;
}

int main(){
	setvbuf(stdout, NULL, _IONBF,0);

	char cFrase[50];
	PILA *pila = NULL;
	COLA *cola = NULL;
	int palindromo = 1;

	printf("Dame la frase para ver si es palindroma\n");
	gets(cFrase);

	int i = 0;

	while(cFrase[i]){
		if(esLetra(cFrase[i])){
			push(&pila,cFrase[i]);
			pushQ(&cola,cFrase[i]);
		}
		i++;
	}


	while(!isEmpty(pila) && palindromo){
		if(top(pila) != topQ(cola)){
			palindromo = 0;
		}else{
			pop(&pila);
			popQ(&cola);
		}
	}

	if(palindromo){
		printf("la frase es palindroma\n");
	}else{
		printf("la frase no es palindroma\n");
	}


	return 0;
}
