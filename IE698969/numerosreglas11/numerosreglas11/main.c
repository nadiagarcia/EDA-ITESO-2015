//
//  main.c
//  numerosreglas11
//
//  Practica 11
//
//  Crea un programa que calcule todos los números de m dígitos (m<=9),
//  todas ellas diferentes a cero y entre sí de tal forma
//  que el número formado por las primeras n cifras sea múltiplo de n.
//
//  Created by Felipe on 3/12/15.
//  Copyright (c) 2015 Felipe. All rights reserved.
//

#include <stdio.h>

#define MAXIMO 381654729 //Mayor numero de interes. Ahorra tiempo de ejecucion.

int numero[9];

void inicializar() { //Pone todos los elementos del arreglo en 0
    int i;
    for (i = 0; i < 10; i++) {
        numero[i] = 0;
    }
}

int longitud(int x) { //Obtener numero de digitos
    if (x < 0) return 0;
    if (x < 10) return 1;
    if (x < 100) return 2;
    if (x < 1000) return 3;
    if (x < 10000) return 4;
    if (x < 100000) return 5;
    if (x < 1000000) return 6;
    if (x < 10000000) return 7;
    if (x < 100000000) return 8;
    if (x < 1000000000)	return 9;
    return -1; //Error
}

int valido (int n, int m) { //Si regresa 0 no cumple con las condiciones
    if (n % longitud(n) != 0) {
        return 0;
    }
    if (n % 10 == 0 && n != 0) {
        return 0;
    }
    if (numero[n % 10] == 1) {
        return 0;
    } else {
        numero[n % 10] = 1;
    }
    if (n == 0) { //Cumple con todas las condiciones
        printf ("%d\n", m);
    }else {
        return valido(n / 10, m); //Recursividad. Divide entre diez para pasar al siguiente digito.
    }
    return 1;
}

int main() {
    int i;
    printf("Numeros validos:\n");
    for (i = 1; i <= MAXIMO; i++) {
        valido(i,i);
        inicializar();
    }
    return 0;
}
