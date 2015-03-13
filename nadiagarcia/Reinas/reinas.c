/*
 * reinas.c
 *
 *  Created on: 13/03/2015
 *      Author: NADIAGARCIA
 */

#include <stdio.h>
#define SIZE 8

int control[SIZE][SIZE] = { { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 },
		{ 0 } };
int tablero[SIZE][SIZE] = { { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 },
		{ 0 } };

void llenarAtaque(int i, int j, int num) {
	//vertical
	int fila;
	for (fila = 0; fila < SIZE; fila++) {
		if (control[fila][j] == 0)
			control[fila][j] = num;
	}

	//horizontal
	int columna;
	for (columna = 0; columna < SIZE; columna++) {
		if (control[i][columna] == 0)
			control[i][columna] = num;
	}

	//diagonal, izq arriba
	fila = i, columna = j;
	while (fila >= 0 && columna >= 0) {
		if (control[fila][columna] == 0)
			control[fila][columna] = num;

		fila--, columna--;
	}

	//diagonal, derecha arriba
	fila = i, columna = j;
	while (fila >= 0 && columna < SIZE) {
		if (control[fila][columna] == 0)
			control[fila][columna] = num;

		fila--, columna++;
	}

	//diagonal, izq abajo
	fila = i, columna = j;
	while (fila < SIZE && columna >= 0) {
		if (control[fila][columna] == 0)
			control[fila][columna] = num;

		fila++, columna--;
	}

	//diagonal, derecha abajo
	fila = i, columna = j;
	while (fila < SIZE && columna < SIZE) {
		if (control[fila][columna] == 0)
			control[fila][columna] = num;

		fila++, columna++;
	}
}

void limpiarAtaque(int num) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (control[i][j] == num)
				control[i][j] = 0;
		}
	}
}

void imprimirTablero() {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%d\t",tablero[i][j]);
		}
		printf("\n");
	}

	printf("=====================================================================\n");

}

int colocarReina(int reina) {
	if (reina == SIZE + 1) {
		imprimirTablero();
		return 1;
	} else {
		int i, j;
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				if (control[i][j] == 0) {
					control[i][j] = reina;
					tablero[i][j] = reina;
					llenarAtaque(i, j, reina);
					colocarReina(reina + 1);
					limpiarAtaque(reina);
					tablero[i][j] = 0;
				}
			}
		}

		return 0;
	}
}

int main(){
	setvbuf(stdout, NULL, _IONBF,0);
	colocarReina(1);

	return 1;
}

