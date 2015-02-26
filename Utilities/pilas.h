#include <stdio.h>
#include <stdlib.h>

typedef int ELEMENTO;

typedef struct Pila{
	ELEMENTO iValor;
	struct Pila siguiente;
}PILA;

int isEmpty(PILA *stack){
	if(stack == NULL)
		return 1;
	else
		return 0;
}

void empty(PILA **stack){
	if(stack != NULL){
		PILA *aux;
		while(*stack != NULL){
			aux = (*stack)->siguiente;
			free(*stack);
			*stack = aux;
		}
	}		
}

ELEMENTO top(PILA *stack){
	return stack->valor;
}

ELEMENTO pop(PILA **stack){

	ELEMENTO valor;
		
	PILA *aux = (*stack)->siguiente;
	valor = (*stack)->valor;
	
	free(*stack);
	*stack = aux;
	
	return valor;
}

void push(PILA **stack, ELEMENTO e){
	PILA *nuevo = (PILA *) malloc(sizeof(PILA));
	nuevo->valor = e;
	nuevo->siguiente = *stack;
	*stack = nuevo;
}


