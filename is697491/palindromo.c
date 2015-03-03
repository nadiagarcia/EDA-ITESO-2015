#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"

int main (int argc, char* argv[]) {
	int i, f = 0;
	char string[50];
	char c;
	PILA *palabra;
	strcpy (string, argv[1]);
	
	for (i = 0; string[i] != NULL; i++)	
		push (&palabra, string[i]);

	i = 0;
	while (!isEmpty(palabra)) {
		c = pop(&palabra);
		if (c != string[i]) f = 1;
		i++;
	}
	empty (&palabra);
	if (f == 1) printf ("%s no es un palindromo\n", &string);
	else printf ("%s es un palindromo\n", &string);
}
