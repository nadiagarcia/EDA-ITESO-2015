//
//  main.c
//  palindromopilas
//  Comprobar que una cadena de texto es palindormo a partir del uso de pilas.
//
//  Created by Felipe on 3/5/15.
//  Copyright (c) 2015 Felipe. All rights reserved.
//

#include <stdio.h>
#include "pilas.h"

int main() {
    int i = 0, j = 0, palindromo = 0;
    char cadena[100];
    char caracter; //Para comprobar caracter por caracter
    PILA * palabra = NULL;
    gets(cadena);
    
    for (i = 0; cadena[i] != NULL; i++)
        push (&palabra, cadena[i]);
    
    while (!isEmpty(palabra)) {
        caracter = pop(&palabra);
        if (caracter != cadena[j]) palindromo = 1;
        j++;
    }
    empty (&palabra);
    if (palindromo == 1){
        printf ("%s si es palindromo\n", &cadena);
    } else {
        printf ("%s no es palindromo\n", &cadena);
    }
}