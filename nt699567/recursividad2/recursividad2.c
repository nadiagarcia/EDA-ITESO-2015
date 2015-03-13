/*
 * recursividad2.c
 *
 *  Created on: 10/03/2015
 *      Author: nt699567
 */
#include <stdio.h>

int digitos(numero) {

	int n = 1;

	if (numero % n == 0) {
		printf("%i", numero);
		return 0;
	}

	return (numero + 1) + digitos();
}

int main() {

	setvbuf(stdout,NULL,_IONBF,0);

	int i, numero1=1;

	for (i = 0; i < 987654321; i++) {
		digitos(numero1);
	}
	return 1;
}
