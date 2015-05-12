#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int info;
    char letra;
    struct nodo *siguiente;
}typedef NODO;

int main(){
    setvbuf(stdout, NULL, _IONBF, 0);
    int op, nodo, car;
    NODO *actual;
    NODO *inicio = NULL;

    while (op != 4){
        printf("Que desea hacer?\n1.Ingresar un nodo 2.Imprimir un nodo 3.Cardinalidad del conjunto 4.Terminar programa");
        scanf("%d", &op);
        NODO *nuevo = (NODO*) malloc(sizeof(NODO));
        nuevo->siguiente = NULL;
        actual = inicio;
        car = 1;
        system("cls");

        switch(op){

            case 1:
                printf("Ingrese los datos del nodo");
                printf("\nNumero:");
                scanf("%d", &nuevo->info);
                printf("\nLetra:");
                fflush(stdin);
                scanf("%c", &nuevo->letra);

                if(inicio == NULL)
                    inicio = nuevo;
                else{
                    while(actual->siguiente != NULL){
                        actual = actual->siguiente;
                    }
                    actual->siguiente = nuevo;
                }
                system("cls");
                break;

            case 2:
                printf("Ingrese el numero del nodo");
                scanf("%d", &nodo);

                while(actual->info != nodo && actual->siguiente != NULL){
                    actual = actual->siguiente;
                }
                if(actual->info == nodo){
                    printf("\nNumero: %d", actual->info);
                    printf("\nLetra: %c", actual->letra);
                }
                else
                    printf("El nodo %d no se encuentra en la lista", nodo);

                getch();
                system("cls");
                break;

            case 3:
                printf("Ingrese el numero del nodo");
                scanf("%d", &nodo);

                while(actual->info != nodo && actual->siguiente != NULL){
                    actual = actual->siguiente;
                    car++;
                }
                printf("Cardinalidad: %d", car);

                getch();
                system("cls");
                break;

            case 4:
                break;
        }

    }
}

