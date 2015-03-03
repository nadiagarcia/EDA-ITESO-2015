#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"

int main (int argc, char* argv[]) {
	int i, f = 0;
	char string[50];
	char c, d;
	PILA *pars;
	strcpy (string, argv[1]);
	
	for (i = 0; string[i] != NULL && f == 0; i++)	 {
		switch (string [i]){	
		case '{':
		case '[':
		case '(':	
			printf ("%c", c, string[i]);
			push (&pars, string[i]);
			break;
		case ']':
		case ')':
		case '}':
			c = pop (&pars);
			printf ("%c | %c", c, string[i]);
			if (string[i] == ']') d = '[';		
			else if (string[i] == '}') d = '{';
			else if (string[i] == ')') d = '(';
			
			if (c != d) f = 1;
		break;
		}
	}
	if (!isEmpty (pars)) f == 1;
	empty (&pars);
	
	if (f == 1) printf ("%s no esta bien formada\n", &string);
	else printf ("%s esta bien formada\n", &string);
}
