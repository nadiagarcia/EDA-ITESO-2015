/*
 * reinas.c
 *
 *  Colocar 8 reinas en un tablero de ajedrez sin que se ataquen
 *
 *  Created on: 13/03/2015
 *      Author: ie698969
 */

#include <stdio.h>

#define SIZE 8

int tablero[SIZE][SIZE] = { { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } };
//inicializa tablero todos cero. Dos dimensiones.

void llenarAtaque(int i, int j, int num) { //Lugares que ataca la reina colocada (funcion para ahorrar lineas).
	int fila;
	for (fila = 0; fila < SIZE; fila++) { //Llenar vertical
		if (tablero[fila][j] == 0) {
			tablero[fila][j] = num;
		}
	}
	int columna;
	for (columna = 0; columna < SIZE; columna++) { //Llenar horizontal
		if (tablero[i][columna] == 0) {
			tablero[i][columna] = num;
		}
	}
	//LLenar diagonales, izquierda arriba
	fila = 1, columna = j;
	while (fila >= 0 && columna >= 0) {
		if (tablero[fila][columna] == 0) {
			tablero[fila][columna] = num;
		}
		fila--, columna--;
	}
	//LLenar diagonales, derecha arriba
	fila = 1, columna = j;
	while (fila >= 0 && columna < SIZE) {
		if (tablero[fila][columna] == 0) {
			tablero[fila][columna] = num;
		}
		fila--, columna++;
	}
	//LLenar diagonales, izquierda abajo
	fila = 1, columna = j;
	while (fila < SIZE && columna >= 0) {
		if (tablero[fila][columna] == 0) {
			tablero[fila][columna] = num;
		}
		fila++, columna--;
	}
	//LLenar diagonales, derecha abajo
	fila = 1, columna = j;
	while (fila < SIZE && columna < SIZE) {
		if (tablero[fila][columna] == 0) {
			tablero[fila][columna] = num;
		}
		fila++, columna++;
	}
}

void limpiarAtaque(int num) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; i < SIZE; j++) {
			if (tablero[i][j] == num) {
				tablero[i][j] = 0;
			}
		}
		printf("\n");
	}
}

void imprimirTablero() {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; i < SIZE; j++) {
			printf("%d\t", tablero[i][j]);
		}
		printf("\n");
	}
	printf("\n===================\n");
}

int colocarReina(int reina) {
	if (reina == SIZE + 1) { //Cuando intente poner una reina de mas ya terminamos.
		imprimirTablero();
		return 1; //Si fue solucion
	} else {
		int i, j;
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				if (tablero[i][j] == 0) {
					tablero[i][j] = reina;
					llenarAtaque(i, j, reina);
					colocarReina(reina + 1);
					limpiarAtaque(reina);
				}
			}
		}
		return 0; //Sin solucion
	}
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0); //Codigo eclipse
	//Tablero de ajedrez
	colocarReina(1); //Empezamos con la reina 1
	return 0;
}
