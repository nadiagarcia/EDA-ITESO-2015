/*
 * palabraslista.c
 *
 *  Created on: 27/02/2015
 *      Author: nt699567
 */

#include <stdio.h>
#include <string.h>

int main() {

	setvbuf(stdout,NULL,_IONBF,0);

	char palabra[20];

	FILE *ArchivoPalabras = fopen("palabras.txt", "r");

	if (ArchivoPalabras==NULL) {
		printf("No se pudo abrir el archivo.");
		return -1;
	}

	return 0;
}
