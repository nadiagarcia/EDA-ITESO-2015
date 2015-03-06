/*
 * palindromopilacola.c
 *
 *  Created on: 06/03/2015
 *      Author: ie698969
 */

#include <stdio.h>
#include "pilas.h"
#include "colas.h"

int esLetra(char caracter){
	if (caracter >= 65 && caracter <= 90){
		return 1;
	}else if(caracter >= 97 && caracter <= 122){
		return 1;
	}else{
		return 0;
	}
}

int main (){
	setvbuf(stdout, NULL, _IONBF, 0);
	char frase[100];
	PILA * pila = NULL;
	COLA * cola = NULL;
	int palindromo = 1;
	int i = 0;

	printf("Ingrese frase;\n");
	gets(frase);

	while(frase[i]){
		if(esLetra(frase[i])){
			push(&pila,frase[i]);
			pushQ(&cola,frase[i]);
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
		printf("La frase \"%s\" es palindroma\n", frase);
	}else{
		printf("La frase \"%s\" no es palindroma\n", frase);
	}
	return 0;
}
