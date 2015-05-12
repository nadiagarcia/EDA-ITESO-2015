#include "pilas.h"
#include <stdio.h>

int main() {
    
    char operacion[100];
    int i = 0, error = 0;
    printf("Dame la operacion a revisar\n");
    
    scanf("%s",operacion);
    
    PILA *stack = NULL;
    
    while (operacion[i] && !error) {
        if (operacion[i] == '(' || operacion[i] == '[' || operacion[i] == '{') {
            push(&stack,operacion[i]);
        }else if(operacion[i] == ')' || operacion[i] == ']' || operacion[i] == '}'){
            char par = top(stack);
            if(par == '(' && operacion[i] == ')'){
                error = 0;
                pop(&stack);
            }
            else if(par == '[' && operacion[i] == ']'){
                error = 0;
                pop(&stack);
            }
            else if (par == '{' && operacion[i] == '}'){
                error = 0;
                pop(&stack);
            }
            else
                error = 1;
        }
        i++;
    }
    
    if(error){
        printf("La operacion esta mal formada\n");
    }else{
        if(!isEmpty(stack))
            printf("La operacion esta mal formada\n");
        else
            printf("La operacion esta bien formada\n");
    }
    
    return 0;
}
