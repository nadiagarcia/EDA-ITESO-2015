#include "pilas.h"
#include <stdio.h>
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	char Ec[80]={};
	int x=0, nova=0;
	printf("introduzca la Ecuacion a revisar\n");
	fflush(stdin);
	gets(Ec);
	PILA *stack = NULL;
	while (Ec[x] !='\0') {

		if (Ec[x] == '(' || Ec[x] == '[' || Ec[x] == '{') {
			push(&stack, Ec[x]);
		} else if (Ec[x] == ')' || Ec[x] == ']' || Ec[x] == '}') {
			char par = top(stack);
			if (par == '(' && Ec[x] == ')')  pop(&stack);
			else if (par == '[' && Ec[x] == ']')  pop(&stack);
			else if (par == '{' && Ec[x] == '}')  pop(&stack);
			else
				nova=1;
		}
		x++;
	}
if(nova||!isEmpty(stack)) {
	printf("\nLa Formula es No es fbf");

} else {
	printf("La formula es fbf");
}
return 0;
}

