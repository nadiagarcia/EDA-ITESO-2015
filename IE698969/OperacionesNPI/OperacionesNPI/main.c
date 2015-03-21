//
//  main.c
//  OperacionesNPI
//
//  El programa convierte de notacion in-fija a post-fija
//  Posteriormente realiza la operacion matematica una vez
//  convertida a Notacion Polaca Inversa.
//
//  Created by Felipe on 3/20/15.
//  Copyright (c) 2015 Felipe. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "pilas.h"
#include "colas.h"
#include "pilasfloat.h" //Pilas con tipo de dato float para las operaciones

//Defino mi jerarquia de las operaciones
#define SUMA 1
#define RESTA 1
#define MULTIPLICACION 2
#define DIVISION 2
#define EXPONENTE 3

int obtenerJerarquia(char topPila, char iElemento) {
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
    if (a > b) return 1;  //Si regresa 1 el topPila tiene mayor jerarquia
    if (a < b) return 2;  //Si regresa 2 el iElemento tiene mayor jerarquia
    if (a == b) return 3; //Si regresa 3 tienen igual jerarquia
    return 0; //Si regresa 0 hay error
}

int main(int argc, const char * argv[]) {
    PILA * operadores = NULL;
    COLA * postfija = NULL;
    PILAFLOAT * resolver = NULL;
    int i = 0;
    float x = 0, y = 0, n = 0;
    char basurero;
    char cadena[50];
    char expresionPostfija[50];
    char * postfijaSeparada;
    //Debug strcpy(cadena, "(6+2)*3/2^2-4");
    printf("Ingrese la expresion a calcular con NPI.\n");
    fgets(cadena, 50, stdin);
    printf("La expresion original es: %s\n", cadena);
    unsigned long longitud = strlen(cadena);
    
    /*Conversion de in-fija a post-fija*/
    for (i = 0; i < longitud; i++) {
        if (cadena[i] >= 48 && cadena[i] <= 57) { //Si es numero
            if (cadena[i-1] >= 48 && cadena[i-1] <= 57) { //Si elemento anterior tambien era numero
                //No hago nada
            } else { //Si el elemento anterior NO era numero
                pushQ(&postfija, ' '); //Agrego espacio
            }
            pushQ(&postfija, cadena[i]); //Si es numero se inserta a la lista
            //Debug printf("El elemento %d es un numero\n", i);
        }
        if (cadena[i] == '(') {
            push(&operadores, cadena[i]); //Se inserta en la pila
            //Debug printf("El elemento %d es un parentesis izquierdo\n", i);
        }
        if (cadena[i] == ')') {
            while (operadores != NULL && top(operadores) != '(') {
                pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                pushQ(&postfija, pop(&operadores)); //Se insertan todos operadores en la lista
            }
            if (top(operadores) == '(') {
                basurero = pop(&operadores); //Destruir parentesis izquierdo cuando lo encontremos
            } else {
                printf("Se ha presentado un error.  Error 1\n");
            }
            //Debug printf("El elemento %d es un parentesis derecho\n", i);
        }
        if (cadena[i] == '+') {
            if (obtenerJerarquia(top(operadores), '+') == 3){
                pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '+') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '+') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores y los metemos a la expresion
                while (operadores != NULL) {
                    pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            //Debug printf("El elemento %d es un signo de suma\n", i);
        }
        if (cadena[i] == '-') {
            if (obtenerJerarquia(top(operadores), '-') == 3){
                pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '-') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '-') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores y los metemos a la expresion
                while (operadores != NULL) {
                    pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            //Debug printf("El elemento %d es un signo de resta\n", i);
        }
        if (cadena[i] == '*') {
            if (obtenerJerarquia(top(operadores), '*') == 3){
                pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '*') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '*') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores y los metemos a la expresion
                while (operadores != NULL) {
                    pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            //Debug printf("El elemento %d es un signo de multiplicacion\n", i);
        }
        if (cadena[i] == '/') {
            if (obtenerJerarquia(top(operadores), '/') == 3){
                pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '/') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '/') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores y los metemos a la expresion
                while (operadores != NULL) {
                    pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            //Debug printf("El elemento %d es un signo de division\n", i);
        }
        if (cadena[i] == '^') {
            if (obtenerJerarquia(top(operadores), '^') == 3){
                pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                pushQ(&postfija, pop(&operadores));
                push(&operadores, cadena[i]);
                //Jerarquia igual se cambian
            }
            if (obtenerJerarquia(top(operadores), '^') == 2){
                //Elemento ingresado (iElemento) mayor jerarquia se agrega a la pila
                push(&operadores, cadena[i]);
            }
            if (obtenerJerarquia(top(operadores), '^') == 1){
                //Elemento ingresado (iElemento) menor jerarquia sacamos los operadores y los metemos a la expresion
                while (operadores != NULL) {
                    pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
                    pushQ(&postfija, pop(&operadores));
                }
                push(&operadores, cadena[i]);
            }
            //Debug printf("El elemento %d es un signo de potencia\n", i);
        }
    }
    while (operadores != NULL) {
        pushQ(&postfija, ' '); //Espacio que separa al operador que se agrega a continuacion
        pushQ(&postfija, pop(&operadores)); //Agrega a la expresion los operadores que quedaron en la pila
    }
    
    /*Imprimir expresion postfija*/
    printf("\n");
    printf("La expresion postfija es:\n");
    i = 0; //Para el contador siguiente
    while (postfija != NULL) {
        expresionPostfija[i] = topQ(postfija); //Al mismo tiempo la guardo en una cadena
        printf("%c", popQ(&postfija));
        i++;
    }
    expresionPostfija[i] = '\0'; //Agrego el caracter nulo a la cadena recien creada para marcar su fin
    printf("\n");
    
    /*Evaluar expresion postfija*/
    postfijaSeparada = strtok (expresionPostfija, " ");
    while (postfijaSeparada != NULL) {
        //printf ("postfijaSeparada vale %s\n", postfijaSeparada);
        if (postfijaSeparada[0] == '+') { //Es suma
            y = popF(&resolver);
            x = popF(&resolver);
            n = x + y;
            pushF(&resolver, n);
        } else if (postfijaSeparada[0] == '-') { //Es resta
            y = popF(&resolver);
            x = popF(&resolver);
            n = x - y;
            pushF(&resolver, n);
        } else if (postfijaSeparada[0] == '*') { //Es multiplicacion
            y = popF(&resolver);
            x = popF(&resolver);
            n = x * y;
            pushF(&resolver, n);
        } else if (postfijaSeparada[0] == '/') { //Es division
            y = popF(&resolver);
            x = popF(&resolver);
            n = x / y;
            //Debug printf("x es %f $ y es %f y n es %f", x, y, n);
            pushF(&resolver, n);
        } else if (postfijaSeparada[0] == '^') { //Es exponente
            y = popF(&resolver);
            x = popF(&resolver);
            n = pow(x, y); //Revisar orden
            pushF(&resolver, n);
        } else { //No es ningun operador, es un operando. Es numero.
            //Debug printf("Este numero es este %s\n", postfijaSeparada);
            n = atof(postfijaSeparada); //Convierto cadena a numero
            //Debug printf("Inserto n a la pila que es %f\n", n);
            pushF(&resolver, n); //Inserto numero a la pila
        }
        postfijaSeparada = strtok (NULL, " ");
    }
    
    /*Imprimo el resultado de mis operaciones*/
    printf("El resultado es: %.2f\n", popF(&resolver));
    return 0;
}
