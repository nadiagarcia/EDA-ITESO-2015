/*
 * tabla.c
 *
 *  Created on: 17/03/2015
 *      Author: NADIAGARCIA
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 30
int tabla_hash[SIZE] = { 0 };

int hash(int clave) {
	//Esta parte es modular.

	return clave % SIZE;
}
int insertar(int clave) {
	int indice;
	indice = hash(clave);
	if (tabla_hash[indice] != 0) {
		int inicio = indice + 1;
		printf("Hubo colision\n");
		while (tabla_hash[inicio % SIZE] != 0 && inicio % SIZE != indice) {
			printf("Hubo colision\n");
			inicio++;
		}
		if (tabla_hash[inicio % SIZE] == 0) {
			tabla_hash[inicio % SIZE] = clave;
			return 1;
		} else {
			printf("Espacio agotado\n");
			return 0;
		}
	} else {
		tabla_hash[indice] = clave;
		return 1;
	}
}

int buscar(int clave) {
	int indice;
	indice = hash(clave);
	if (tabla_hash[indice] == clave) {
		return indice;
	} else {
		int inicio = indice + 1;
		while (tabla_hash[inicio % SIZE] != clave && inicio % SIZE != indice) {
			inicio++;
		}
		if (tabla_hash[inicio % SIZE] == clave) {
			return inicio%SIZE;
		} else {
			return -1;
		}

	}
}

int eliminar(int clave){
	int indice;
	indice = buscar(clave);
	if(indice==-1){
		printf("No existe \n");
		return 0;
	}
	else{
		tabla_hash[indice]= 0;
		return 1;
	}
}

int main() {
	int i=1;
	int usuario;
	int hacer;
	printf("ingrese el expediente");
	scanf("%d",&usuario);
	printf("Ingrese que quiere hacer");
	scanf("%d",&hacer);
	switch (hacer);

	return 0;
}

