#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
#include "colas.h"

#define SUMA 3 	
#define RESTA 3
#define MULTI 2
#define DIV 2
#define EXP 1 	
#define PARS_O 0
#define PARS_C -1

int get_pref (char c) ;

int main (int argc, char* argv[]) {
	int i, f = 0, a = 2, op;
	char string[50];
	char temp[100];
	char *pch;
	char c, p;
	PILA *operators = NULL;
	COLA *input = NULL, *output = NULL;
	
	if (argc < 2) {
		printf ("RPN Converter:\nExec: %s \"Equacion\"\n", argv[0]);
		return 0;
	}
		
	pch = strtok (argv[1]," ");
	while (pch != NULL) {

		if (strcmp (pch, "+") == 0) 	  {f = '+' + 32000; op = SUMA;}
		else if (strcmp (pch, "-") == 0) {f = '-' + 32000; op = RESTA;}
		else if (strcmp (pch, "/") == 0) {f = '/' + 32000; op = DIV;}
		else if (strcmp (pch, "*") == 0) {f = '*' + 32000; op = MULTI;}
		else if (strcmp (pch, "^") == 0) {f = '^' + 32000; op = EXP;}
		else if (strcmp (pch, "(") == 0) {f = '(' + 32000; op = PARS_O;}
		else if (strcmp (pch, ")") == 0) {f = ')' + 32000; op = PARS_C;}
		else { 
			q_push (&output, atoi(pch));
			pch = strtok (NULL, " \n");
			continue;	 
		}
				
		//If an operator will be added, execute this: 
		if (!isEmpty (operators)) i = top (operators) - 32000;
		else i = -5;
		if (i == '+') 	   	i = SUMA;
		else if (i == '-') 	i = RESTA;
		else if (i == '*') 	i = MULTI;
		else if (i == '/') 	i = DIV;
		else if (i == '(') 	i = PARS_O;
		else if (i == ')') 	i = PARS_C;
		
		if (op == PARS_C) {
			while (!isEmpty (operators) && get_pref (top(operators) - 32000) != 0 ) 
				q_push(&output, pop(&operators));
			pop (&operators);
		} else if (op == PARS_O) {
			push (&operators, f);
		} else if (op == i) { //Same preference
			q_push (&output, pop(&operators));
			push (&operators, f);
		} else if (op < i) { //New operator has lower preference
			push (&operators, f);
		} else { //New operator has higer preference
			if (!isEmpty (operators) && top (operators) - 32000 != '(') {
				q_push (&output, pop(&operators));
			}
			push (&operators, f);
		}
			pch = strtok (NULL, " \n");
	}
	
	while (!isEmpty (operators)) {
		q_push (&output, pop(&operators));
	}
	
	while (!q_isEmpty (output)) {
		i = q_pop(&output);
		if (i > 32000) {
			i - 32000; 
			printf ("%c ", i);
		}
		else printf ("%d ", i);
		
	}
	printf ("\n");
	return 0;
}

int get_pref (char c) {
	char i;
	if (c == '+') i = SUMA;
	else if (c == '-') i = RESTA;
	else if (c == '*') i = MULTI;
	else if (c == '/') i = DIV;
	else if (c == '(') i = PARS_O;
	else if (c == ')') i = PARS_C;
	else i = -1;
		
	return i;
}
