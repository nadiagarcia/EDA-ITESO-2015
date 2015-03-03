#include <stdio.h>
#include <stdlib.h>


typedef struct numero{
    int numero;
    struct numero *anterior;
    struct numero *siguiente;
}NUMERO;

int main()
{
    char c=0;
    int n;

    NUMERO *numero1 = (NUMERO*)malloc(sizeof(NUMERO));
    numero1->numero = 0;
    numero1->anterior = NULL;
    numero1->siguiente = NULL;
    NUMERO *actual=numero1;


    printf("Dame el numero 1\n");
    while (c !=13){

        c=getch();
        n=c-48;

        if(n>=0 && n<=9){
            actual->siguiente = (NUMERO*)malloc(sizeof(NUMERO));
            actual->siguiente->anterior = actual;
            actual = actual->siguiente;
            actual->numero = n;
            actual->siguiente = NULL;

            printf("%d ",n);
        }
    }

    c=0;
    NUMERO *numero2 = (NUMERO*)malloc(sizeof(NUMERO));
    numero2->numero = 0;
    numero2->anterior = NULL;
    numero2->siguiente = NULL;
    actual = numero2;

    printf("\nDame el numero 2\n");
    while (c !=13){

        c=getch();
        n=c-48;

        if(n>=0 && n<=9){
        actual->siguiente = (NUMERO*)malloc(sizeof(NUMERO));
        actual->siguiente->anterior = actual;
        actual = actual->siguiente;
        actual->numero=n;
        actual->siguiente = NULL;

        printf("%d ",n);
        }
    }

    NUMERO *actual_num1 = numero1;

    printf("\nNumero 1: ");
    while (actual_num1->siguiente !=NULL){
        printf("%d", actual_num1->numero);
        actual_num1 = actual_num1->siguiente;
    }
    printf("%d\n", actual_num1->numero);

    NUMERO *actual_num2 = numero2;

    printf("Numero 2: ");
    while (actual_num2->siguiente !=NULL){
        printf("%d", actual_num2->numero);
        actual_num2 = actual_num2->siguiente;
    }
    printf("%d", actual_num2->numero);

   /* while (actual != NULL);{
        printf("%d", actual->numero);
    }*/

    //SUMA

    NUMERO *resultado = (NUMERO *) malloc(sizeof(NUMERO));
    resultado->siguiente = NULL;
    resultado->anterior = NULL;
    actual = resultado;
    int carry =0;
    int suma;

    while(actual_num2 !=NULL){
        suma = carry + actual_num1->numero + actual_num2->numero;
        NUMERO *nuevo = (NUMERO *) malloc(sizeof(NUMERO));
        actual->anterior = nuevo;
        nuevo->siguiente = actual;
        nuevo->anterior = NULL;
        nuevo->numero = suma%10;
        actual = actual->anterior;

        if(suma>9){
            carry = 1;
        } else{
            carry = 0;
        }
        actual_num2 =actual_num2->anterior;
        actual_num1 =actual_num1->anterior;

    }

    resultado->anterior->siguiente = NULL;
    resultado->anterior = NULL;
    free(resultado);
    resultado = actual;
    printf("\nResultado: %d", resultado);


    return 0;
}
