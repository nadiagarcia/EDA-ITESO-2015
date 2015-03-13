//
//  main.c
//  infijapostfija
//
//  P. 8: in-fija a post-fija
//  Created by Felipe on 3/9/15.
//  Copyright (c) 2015 Felipe. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "pilas.h"
#include "colas.h"

//Defino mi jerarquia de las operaciones
#define SUMA 1
#define RESTA 1
#define MULTIPLICACION 2
#define DIVISION 2
#define EXPONENTE 3

int obtenerJerarquia(char topPila, char iElemento);

int main(int argc, const char * argv[]) {
    PILA * operadores = NULL;
    COLA * postfija = NULL;
    int i = 0;
    char basurero;
    char cadena[50];
    strcpy(cadena, "(6+2)*3/2^2-4");
    printf("La expresion es: %s\n", cadena);
    unsigned long longitud = strlen(cadena);

    for (i = 0; i < longitud; i++) {
        if (cadena[i] >= 48 && cadena[i] <= 57) { //Compruebo que es numero
            pushQ(&postfija, cadena[i]);
            printf("El elemento %d es un numero\n", i);
        }/*else{
            printf("El elemento %d no es un numero\n", i);
        }*/
        if (cadena[i] == '(') {
            push(&operadores, cadena[i]);
            printf("El elemento %d es un parentesis izquierdo\n", i);
        }
        if (cadena[i] == ')') {
            while (operadores != NULL && top(operadores) != '(') {
                pushQ(&postfija, pop(&operadores));
            }
            if (top(operadores) == '(') {
                basurero = pop(&operadores);
            } else {
                printf("Se ha presentado un error.  Error 1\n");
            }
            printf("El elemento %d es un parentesis derecho\n", i);
        }
        if (cadena[i] == '+') {
            if (obtenerJerarquia(top(operadores), '+') == 3){
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '+') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '+') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores
                while (operadores != NULL) {
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            printf("El elemento %d es un signo de suma\n", i);
        }
        if (cadena[i] == '-') {
            if (obtenerJerarquia(top(operadores), '-') == 3){
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '-') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '-') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores
                while (operadores != NULL) {
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            printf("El elemento %d es un signo de resta\n", i);
        }
        if (cadena[i] == '*') {
            if (obtenerJerarquia(top(operadores), '*') == 3){
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '*') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '*') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores
                while (operadores != NULL) {
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            printf("El elemento %d es un signo de multiplicacion\n", i);
        }
        if (cadena[i] == '/') {
            if (obtenerJerarquia(top(operadores), '/') == 3){
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '/') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '/') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores
                while (operadores != NULL) {
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            printf("El elemento %d es un signo de division\n", i);
        }
        if (cadena[i] == '^') {
            if (obtenerJerarquia(top(operadores), '^') == 3){
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '^') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '^') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores
                while (operadores != NULL) {
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            printf("El elemento %d es un signo de potencia\n", i);
        }
    }
    while (operadores != NULL) {
        pushQ(&postfija, pop(&operadores));
    }
    //Imprimir expresion postfija
    printf("\n");
    printf("La expresion postfija es:\n");
    while (postfija != NULL) {
        char caracter = popQ(&postfija);
        printf("%c", caracter);
    }
    printf("\n");
    return 0;
}

int obtenerJerarquia(char topPila, char iElemento){
    //Si regresa 1 el topPila tiene mayor jerarquia
    //Si regresa 2 el iElemento tiene mayor jerarquia
    //Si regresa 3 tienen igual jerarquia
    int a = 0, b = 0;
    //Jerarquia de topPila
    if (topPila == '+') a = SUMA;
    if (topPila == '-') a = RESTA;
    if (topPila == '*') a = MULTIPLICACION;
    if (topPila == '/') a = DIVISION;
    if (topPila == '^') a = EXPONENTE;
    //Jerarquia de iElemento
    if (iElemento == '+') b = SUMA;
    if (iElemento == '-') b = RESTA;
    if (iElemento == '*') b = MULTIPLICACION;
    if (iElemento == '/') b = DIVISION;
    if (iElemento == '^') b = EXPONENTE;
    //Respuesta
    if (a > b) return 1;
    if (a < b) return 2;
    if (a == b) return 3;
    
    return 0;
}
