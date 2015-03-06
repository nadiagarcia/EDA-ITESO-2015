#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"
int main(){
    char analizador[20];
    int j=0, falso=0;
    printf("Ingrese la operacion a revisar\n");
    gets(analizador);
    PILA *operacion = NULL;

    while (analizador[j] && !falso) {
        if (analizador[j] == '(' || analizador[j] == '[' || analizador[j] == '{') {
            push(&operacion,analizador[j]);
        }
        else if(analizador[j] == ')' || analizador[j] == ']' || analizador[j] == '}'){
            char par = top(operacion);
            if(par == '(' && analizador[j] == ')'){
                pop(&operacion);
            }
            else if(par == '[' && analizador[j] == ']'){
                pop(&operacion);
            }
            else if (par == '{' && analizador[j] == '}'){
                pop(&operacion);
            }
            else
                falso = 1;
        }
            j++;
    }
        if(falso){
            printf("La operacion es incorrecta");
        }
        else{
            if(!isEmpty(operacion))
            printf("La operacion es incorrecta");
        else
            printf("La operacion es correcta");
        }

    return 0;
}
