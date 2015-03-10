/*
 * desarollopoli.c
 *
 *  Programa que calcule el desarrollo del polinomio (x+1)
 *  a la n potencia.
 *  Imprime la potencia en forma x**
 *
 *  Created on: 10/03/2015
 *      Author: ie698969
 */

#include <stdio.h>

int coeficiente(int n, int m){
	if (m == 0) return 1;
	if (m == n) return 1;
	else return coeficiente(n-1, m-1) +  coeficiente(n-1, m);
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0); //Codigo eclipse
	int n, i;
	printf("Ingrese la potencia a desarrollar (x+1)\n");
	scanf("%d", &n);
	for(i = n; i >= 0; i--){
		printf("%dx^%d ", coeficiente(n,i), i);
	}
	return 0;
}
