//
//  main.c
//  palindromo
//
//  Created by Víctor David Rivera Ramírez on 03/03/15.
//  Copyright (c) 2015 Víctor David Rivera Ramírez. All rights reserved.
//

#include <stdio.h>
#include "pilas.h"

int main() {
    
    char operacion[100];
    
    int i = 0, error = 0;
    
    printf("Dame la operacion a revisar: \n");
    fflush(stdin);
    scanf("%s", &operacion);
    
    PILA *stack = NULL;
    
    while (operacion[i] && !error) {
        if (operacion[i] == '(' || operacion[i] == '[' || operacion[i] == '{') {
            push(&stack, operacion[i]);
        }else if (operacion[i] == ')' || operacion[i] == ']' || operacion[i] == '}'){
            char par = top(stack);
            if (par == '(' && operacion[i] == ')') {
                error = 0;
            }else if (par == '[' && operacion[i] == ']'){
                error = 0;
            }else if (par == '{' && operacion[i] == '}'){
                error = 0;
            }else
                error = 1;
        }
    }
    
    if (error) {
        printf("La operacion esta mal formada\n");
    }else{
        if (!isEmpty(stack)) {
            printf("La operacion esta mal formada\n");
        }
    }
    
    printf("\n");
    return 0;
}
