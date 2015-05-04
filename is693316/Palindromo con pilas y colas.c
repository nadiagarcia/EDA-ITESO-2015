//
//  main.c
//  Palindromo con pilas y colas
//
//  Created by Víctor David Rivera Ramírez on 04/05/15.
//  Copyright (c) 2015 Víctor David Rivera Ramírez. All rights reserved.
//

#include <stdio.h>
#include "pilas.h"
#include "colas.h"

int esLetra(char caracter){
    if (caracter >= 65 && caracter <= 90){
        return 1;
    }else if(caracter >= 97 && caracter <= 122){
        return 1;
    }else{
        return 0;
    }
}

int main (){
    setvbuf(stdout, NULL, _IONBF, 0);
    char frase[100];
    PILA * pila = NULL;
    COLA * cola = NULL;
    int palindromo = 1;
    int i = 0;
    
    printf("Ingrese frase;\n");
    gets(frase);
    
    while(frase[i]){
        if(esLetra(frase[i])){
            push(&pila,frase[i]);
            pushQ(&cola,frase[i]);
        }
        i++;
    }
    
    while(!isEmpty(pila) && palindromo){
        if(top(pila) != topQ(cola)){
            palindromo = 0;
        }else{
            pop(&pila);
            popQ(&cola);
        }
    }
    
    if(palindromo){
        printf("La frase \"%s\" es palindroma\n", frase);
    }else{
        printf("La frase \"%s\" no es palindroma\n", frase);
    }
    return 0;
}