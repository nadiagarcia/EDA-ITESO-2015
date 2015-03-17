/*
 * numeros.c
 *
 *  Created on: Mar 10, 2015
 *      Author: ngarcia
 */

#include <stdio.h>

int buscaDigitoRepetido(int n, int d) {
	if (n == 0)
		return 1;
	if (n % 10 == d)
		return 0;

	return buscaDigitoRepetido(n / 10, d);

}

int revisaReglas(int n) {
	if (n < 10)
		return 1;
	if (n % 10 == 0)
		return 0;

	return buscaDigitoRepetido(n / 10, n % 10) & revisaReglas(n / 10);
}

int revisaMultiplos(int n, int i){

}

int seImprime(int n){
	if(revisaReglas(n)){
		return revisaMultiplos(n,1);
	}else{
		return 0;
	}
}

int main() {
	unsigned int i;

	for (i = 1; i <= 999; i++) {
		printf("%d ", i);
		if (revisaReglas(i))
			printf("si \n");
		else
			printf("no \n");
	}
}
