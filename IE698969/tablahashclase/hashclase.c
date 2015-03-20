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
	setvbuf(stdout, NULL, _IONBF, 0); //Codigo eclipse
	int usuario, opcion = 0, salir = 0;

	while (!salir) {
		printf("Ingrese el expediente\n");
		scanf("%d", &usuario);
		printf("Seleccione opcion:\n");
		printf("1. Insertar\n");
		printf("2. Buscar\n");
		printf("3. Eliminar\n");
		printf("4. Salir\n");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			insertar(usuario);
			break;
		case 2:
			printf("%d", buscar(usuario));
			break;
		case 3:
			eliminar(usuario);
			break;
		case 4:
			salir = 1;
			break;
		default:
			printf("Ingrese una opcion valida.\n");
			break;
		}
	}

	return 0;
}
