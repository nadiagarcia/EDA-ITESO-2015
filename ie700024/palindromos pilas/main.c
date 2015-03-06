#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"


int main(){

    PILA *analiza = NULL;
    PILA *compara = NULL;
    PILA *palindromo = NULL;

    char frase [50];
    int i=0, pal=0;
    printf("Ingrese una frase para analizar si es palindromo: ");
    gets(frase);

    while (frase[i] !=0){
        push(&analiza,frase[i]);
        push(&compara,frase[i]);
        i++;
    }

    while(analiza!=NULL){
        push(&palindromo, pop(&analiza));
    }

    while(palindromo!=NULL){
        printf("\n%s  ", compara);
        printf("%s", palindromo);
         pop(&palindromo);
         pop(&compara);
         }if(top(palindromo)!=top(compara)){
            pal=0;
         }else{
            pal=1;
    }

   if(pal==1){
        printf("\nLa frase es un palindromo");
   }else{
        printf("\nLa frase no es un palindromo");
   }


return 0;
}
