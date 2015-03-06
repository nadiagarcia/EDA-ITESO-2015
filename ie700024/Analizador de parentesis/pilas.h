#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int ELEMENTO;

typedef struct Pila {
    ELEMENTO iValor;
    struct Pila *siguiente;
} PILA;

int isEmpty(PILA *stack) { //regresa verdadero si la pila está vacia o faalso si contiene elementos
    if (stack == NULL)
        return 1;
    else
        return 0;
}

void empty(PILA **stack) { //vacia una pila
    if (stack != NULL) {
        PILA *aux;
            while (*stack != NULL) {
                aux = (*stack)->siguiente;
                free(*stack);
                *stack = aux;
            }
    }
}

ELEMENTO top(PILA *stack) { //regresa el valor del elemento que está hasta arriba de la pila
    if (stack == NULL) {
        printf("Error, pila vacia");
        return -1; //valor que indica un error al hacer top
    }

    return stack->iValor;
}

ELEMENTO pop(PILA **stack) { //Elimina un valor de la pila y regresa el de hasta arriba
    if (*stack == NULL) {
        printf("Error, pila vacia");
        return -1; //valor que indica un error al hacer top
    }

    ELEMENTO valor;

    PILA *aux = (*stack)->siguiente;
    valor = (*stack)->iValor;

    free(*stack);
    *stack = aux;

    return valor;
}

void push(PILA **stack, ELEMENTO e) { //añade un elemento a la cima de la pila
    PILA *nuevo = (PILA *) malloc(sizeof(PILA));
    nuevo->iValor = e;
    nuevo->siguiente = *stack;
    *stack = nuevo;
}


#endif // PILAS_H_INCLUDED
