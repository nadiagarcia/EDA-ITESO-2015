/*
 * pilas1.c
 *
 *  Revisar si una operacion es correcta
 *
 *  Created on: 03/03/2015
 *      Author: ie698969
 */

#include <stdio.h>
#include "pilas.h"

int main() {
    setvbuf(stdout, NULL, _IONBF, 0); //Codigo eclipse
    PILA * stack = NULL;
    char operacion[100];
    int i = 0, error = 0;
    char par;

    printf("Dame la operacion a revisar\n");
    gets(operacion);

    while (operacion[i] && !error && i<100) {
        if (operacion[i] == '(' || operacion[i] == '[' || operacion[i] == '{') {
            push(&stack, operacion[i]);
        } else if (operacion[i] == ')' || operacion[i] == ']' || operacion[i] == '}') {
            par = top(stack);
            if (par == '(' && operacion[i] == ')') {
                error = 0;
                pop(&stack);
            } else if (par == '[' && operacion[i] == ']') {
                error = 0;
                pop(&stack);
            } else if (par == '{' && operacion[i] == '}') {
                error = 0;
                pop(&stack);
            } else{
                error = 1;
            }
        }
        i++;
    }

    if(error){
        printf("La operacion esta mal formada\n");
    }else{
        if(isEmpty(stack)){
            printf("La operacion esta bien formada\n");
        }else{
            printf("La operacion esta mal formada\n");
        }
    }

    return 0;
}
