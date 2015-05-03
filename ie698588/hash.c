/*
 * hash.c
 *
 *  Created on: 17/03/2015
 *      Author: ie698588
 */

#include<stdio.h>
#include<stdlib.h>
#define TAM 30

int tabla_hash[TAM] = { 0 };

int hash(int clave) {
	//esta parte es modular
	return clave % TAM;
}

int insertar(int clave) {
	int indice;
	indice = hash(clave);
	if (tabla_hash[indice] != 0) {
		int inicio = indice + 1;
		printf("Hubo colisión");
		while (tabla_hash[inicio % TAM] != 0 && inicio % TAM != indice) {
			printf("Hubo colisión\n");
			inicio++;
		}
		if (tabla_hash[inicio % TAM] == 0) {
			tabla_hash[indice] = clave;
			return 1;
		} else {
			printf("Espacio agotado");
			return 0;
		}

	} else {
		tabla_hash[indice] = clave;
		return 1;
	}
}

int buscar(int clave) {
	int indice = hash(clave);

	if (tabla_hash[indice] == clave)
		return indice;

	else {
		int inicio = indice + 1;
		while (tabla_hash[inicio % TAM] != 0 && inicio % TAM != indice) {
			inicio++;
		}
		if (tabla_hash[inicio % TAM] == clave) {
			return inicio % TAM;
		} else {
			return -1;
		}

	}

}

int eliminar(int clave) {
	int indice;
	indice = buscar(clave);
	if (indice == -1) {
		printf("No existe");
		return 0;
	} else {
		tabla_hash[indice] = 0;
		return 1;
	}

}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);

	int op;
	int expediente;
	while () {
		printf("¿Qué desea hacer?");
		printf(
				"1. Ingresar un expediente 2.Buscar un expediente 3.Eliminar un expediente");
		scanf("%d", &op);
		switch (op) {
		case 1:
			printf("Ingrese su expediente");
			scanf("%d", &expediente);
			insertar(expediente);
			break;

		case 2:
			printf("Ingrese su expediente");
			scanf("%d", &expediente);
			buscar(expediente);
			break;

		case 3:
			printf("Ingrese su expediente");
			scanf("%d", &expediente);
			eliminar(expediente);
			break;
		}

	}
	return 0;
}
