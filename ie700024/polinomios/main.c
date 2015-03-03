#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct num{
    int coeficiente;
    int exponente;
    struct num *siguiente;
} NUMERO;

void ingresar_numero (NUMERO **num){
    NUMERO *variable = (NUMERO*)malloc(sizeof(NUMERO));

    printf("Ingrese el coeficiente de la variable: ");
    scanf("%d", &variable->coeficiente);
    printf("Ingrese el exponente de la variable: ");
    scanf("%d", &variable->exponente);
    variable->siguiente = NULL;

    variable->siguiente = *num;
    *num = variable;
}

void evaluar_polinomio (NUMERO **num, int evalua){
    int suma=0;
    int valor;

    NUMERO *actual = (NUMERO*)malloc(sizeof(NUMERO));
    actual->siguiente = num;

    while(actual!= NULL) {
        valor = pow(evalua, actual->exponente);
        valor = valor * actual->coeficiente;

        suma = +valor;
    }

    printf("El resultado del numero evaluado es: %d", &suma);
}

int main()
{
    NUMERO *valor = NULL;
    int evalua;

    ingresar_numero(&valor);

    printf("Ingrese el numero con el que quiere evaluar el polinomio: ");
    scanf("%d", &evalua);

    evaluar_polinomio(&valor, evalua);

    return 0;
}
