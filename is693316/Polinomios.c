//
//  main.c
//  Polinomios nadia
//
//  Created by Víctor David Rivera Ramírez on 08/03/15.
//  Copyright (c) 2015 Víctor David Rivera Ramírez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct termino {
    int coeficiente, exponente;
    struct termino *siguiente;
} TERMINO;

void agregarTermino(TERMINO **polinomio, int coef, int exp) {
    
    TERMINO *actual = *polinomio;
    TERMINO *nuevo = (TERMINO *) malloc(sizeof(TERMINO));
    nuevo->siguiente = NULL;
    nuevo->coeficiente = coef;
    nuevo->exponente = exp;
    
    if (actual == NULL) {
        *polinomio = nuevo;
        
    } else {
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        
        actual->siguiente = nuevo;
    }
    
}

void imprimirPolinomio(TERMINO *polinomio) {
    TERMINO *actual = polinomio;
    
    if (actual != NULL) {
        do {
            if (actual->coeficiente > 0)
                printf("+%dx^%d ", actual->coeficiente, actual->exponente);
            else
                printf("%dx^%d ", actual->coeficiente, actual->exponente);
            
            actual = actual->siguiente;
        } while (actual != NULL);
    }
    
}

float evaluarPolinomio(TERMINO *polinomio, float valor){
    float resultado = 0;
    TERMINO *actual = polinomio;
    
    while(actual != NULL){
        resultado += actual->coeficiente * pow(valor,actual->exponente);
        actual = actual->siguiente;
    }
    
    return resultado;
}

int main() {
    TERMINO *polinomio = NULL;
    
    int opcion;
    int exponente, coeficiente;
    float valor;
    
    do {
        printf("Que quieres hacer?\n");
        printf("1. Agregar terminos al polinomio\n");
        printf("2. Ver polinomio\n");
        printf("3. Evaluar polinomio\n");
        printf("0. Salir\n");
        scanf("%d",&opcion);
        
        switch(opcion){
            case 1:
                printf("Coeficiente: ");
                scanf("%d",&coeficiente);
                printf("Exponente: ");
                scanf("%d",&exponente);
                agregarTermino(&polinomio,coeficiente,exponente);
                break;
            case 2:
                imprimirPolinomio(polinomio);
                break;
            case 3:
                printf("Cual es el valor a evaluar?");
                scanf("%f",&valor);
                printf("Resultado: %f\n",evaluarPolinomio(polinomio,valor));
                break;
            case 0:
                break;
            default:
                printf("Opcion no válida\n");
        }
        
    } while (opcion != 0);
    
    return 0;
}