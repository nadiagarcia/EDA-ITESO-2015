/*
 * notacionpolaca.c
 *
 *  Created on: 06/03/2015
 *      Author: nt699567
 */

#include <stdio.h>
#include "colas.h"
#include "pilas.h"

int main(){

	setvbuf(stdout,NULL,_IONBF,0);

	char op[20];

	int i=0;

	printf("Dame la operacion que deseas pasar a postfija:");
	gets(op);

	PILA *operadores=NULL;

	COLA *operandos=NULL;

	while(op[i]){

	}



	return 0;
}

