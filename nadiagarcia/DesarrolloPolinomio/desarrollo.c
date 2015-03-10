/*
 * desarrollo.c
 *
 *  Created on: 10/03/2015
 *      Author: NADIAGARCIA
 */

#include <stdio.h>

int Coeficiente(int n, int m){
	if(m == 0)
		return 1;
	if(m == n)
		return 1;
	else
		return Coeficiente(n-1,m-1) + Coeficiente(n-1,m);
}

int main(){

	int n, i;

	printf("Dame n para desarrollar el polinomio x+1 \n");
	scanf("%d",&n);

	for(i=n; i>=0; i--){
		printf("%dx^%d ",Coeficiente(n,i),i);
		if(i>0)
			printf("+ ");
	}

	return 1;

}
