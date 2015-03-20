/*
 * hashclase.c
 *
 *  Created on: 17/03/2015
 *      Author: ie698969
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 30
int tabla_hash[30] = { 0 };

int hash(int clave) {
	//Esta parte es modular

	return clave % SIZE;
}

int insertar(int clave) {
	int indice;
	indice = hash(clave);
	if (tabla_hash[indice] != 0) {
		int inicio = indice + 1;
		printf("Hubo colisión\n");
		while (tabla_hash[inicio % SIZE] != 0 && inicio % SIZE != indice) {
			printf("Hubo colisión\n");
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

			return inicio % SIZE;
		} else {
			return -1;
		}
	}
}

int eliminar(int clave) {
	int indice;
	indice = buscar(clave);
	if (indice == 1) {
		printf("No existe\n");
		return 0;
	} else {
		tabla_hash[indice] = 0;
		return 1;
	}
}

int main() {

	int i = 1;
	int usuario;
	int opcion;
	printf("Ingrese el expediente\n");
	scanf("%s", &usuario);
	printf("Qué desea hacer\n");
	scanf("%d", &opcion);

	switch (opcion)
	;

	return 0;
}
