#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
//Due to linux's wildcards [*], use "x" to signify a multiplication
//Compile: cc     RPN.c   -lm -o RPN
int main (int argc, char* argv[]) {
	int i, f = 0, a = 2, op, b;
	char string[50];
	char temp[100];
	char *pch;
	char c, p;
	PILA *operators = NULL;
	COLA *input = NULL, *output = NULL;
	
	if (argc < 2) {
		printf ("RPN Converter: %s \"Equation\"\n", argv[0]);
		printf ("RPN Solver: %s Equation without \"\"\n", argv[0]);
		return 0;
	}
	
	if (argc == 2) { //infix => postfix converter
	pch = strtok (argv[1]," ");
	while (pch != NULL) {
		if (strcmp (pch, "+") == 0) 	  {f = '+' + 32000; op = SUMA;}
		else if (strcmp (pch, "-") == 0) {f = '-' + 32000; op = RESTA;}
		else if (strcmp (pch, "/") == 0) {f = '/' + 32000; op = DIV;}
		else if (strcmp (pch, "*") == 0) {f = 'x' + 32000; op = MULTI;}
		else if (strcmp (pch, "x") == 0) {f = 'x' + 32000; op = MULTI;}
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
		else if (i == 'x') 	i = MULTI;
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
		//q_push (&input, q_top (&output));
		i = q_pop(&output);
		if (i > 32000) {
			i - 32000; 
			printf ("%c ", i);
		}
		else printf ("%d ", i);
	}
	printf ("\n");
	empty (&operators);
	q_empty (&input);
	q_empty (&output);
	return 0;
	}

	
	else {//RPN SOLVER
	i = 1;
	while (i <= argc - 1) { //Add everything to a stack
		if (strcmp (argv[i], "+") == 0) 	  op = 1; //SUMA;
		else if (strcmp (argv[i], "-") == 0) op = 2; //RESTA;
		else if (strcmp (argv[i], "/") == 0) op = 3; //DIV;
		else if (strcmp (argv[i], "x") == 0) op = 4; //MULTI;
		else if (strcmp (argv[i], "^") == 0) op = 5; //EXP;
		else if (strcmp (argv[i], "(") == 0) op = 6; //PARS_O;
		else if (strcmp (argv[i], ")") == 0) op = 7; //PARS_C;
		else { 
			//printf (": %d\n", atoi(argv[i]));
			push (&operators, atoi(argv[i]));
			i++;
			continue;	 
		}
		//If a operand was execured
		i++;
		a = pop (&operators);
		b = pop (&operators);
		switch (op) {
		case 1: //suma
			push (&operators, a + b); break;
		case 2: //resta
			push (&operators, b - a); break;
		case 3: //div
			push (&operators, b / a); break;
		case 4: //multi				
			push (&operators, b * a); break;
		case 5: //exp
			push (&operators, pow(b,a));
		}
	}
	a = pop (&operators);
	if (isEmpty (operators)) printf ("Resultado = %d\n", a);
	else printf ("Bad formula\n");
	empty (&operators);
	q_empty (&input);
	q_empty (&output);
	}
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
