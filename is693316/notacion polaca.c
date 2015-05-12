#include<stdio.h>
#include<string.h>
#include "pilas.h"
PILA*stack;
int j=0;
void vaciar()
{
	while( !isEmpty(stack)	&&	top(stack)!='(')
	{	
		printf(" %c ",top(stack));
		pop(&stack);
	}
	if(isEmpty(stack))
		return ;
	if(top(stack)=='(')
	{
		pop(&stack);
	}
}
int npi(char x)
{
	if(x==')')
	{
		vaciar();
		return 0;
	}
	if(x=='^')
		{
			push(&stack,x);
			j=3;
			return 0;
		}
	if(x=='/' || x=='*')
		{
			if(j<=2)
			{
				push(&stack,x);
			}
			else
			{
				vaciar();
				push(&stack,x);
			}
			j=2;
			return 0;
		}
	if(x=='+' || x=='-'||x=='(')
	{
		if(j>1 && x!='(')
		{
			vaciar();
		}
		push(&stack,x);
		j=1;
		return 0;
	}
	if(x!='('&&x!=')')
	{
		printf("%c",x);
	}
	return -1;
}
int main()
{
	char a[50];
	gets(a);//suponiendo que la formula es una FBF(formula bien formada)
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		if(a[i]=='-' && a[i+1]!=' ')
		{
			printf("-"); // parche para numeros negativos...
			i++;
		}
		npi(a[i]);
	}
	if(!isEmpty(stack))
		vaciar();
		return 0;
}

        