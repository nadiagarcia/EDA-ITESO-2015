//
//  main.c
//  practica5Palabras1
//
//  Dado un texto, leído de un archivo, se requiere crear una
//  lista enlazada ordenada de palabras que informe la linea
//  en la que aparece dicha palabra por primera vez.
//
//  Created by Felipe on 2/28/15.
//  Copyright (c) 2015 Felipe. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Crear mi estructura para la lista de palabras
typedef struct palabra {
    char palabraOrdenada[30];
    struct palabra *siguiente;
    struct palabra *anterior;
} PALABRA;

int main (int argc, char* argv[]) {
    PALABRA *actual;
    PALABRA *nuevo;
    PALABRA *inicio = NULL;
    
    FILE * archivoPalabras; //FILE es el objeto que contiene informacion para controlar un stream
    char cadena[100];
    char * cadenaSeparada;
    int encontrado = 0;
    //Abrir texto.txt en modo lectura
    archivoPalabras = fopen("texto.txt", "r"); //fopen regresa un apuntador a un objeto FILE, si no lo encuentra a NULL
    
    if (archivoPalabras == NULL) {
        printf("El archivo no existe.\n");
    } else {
        while (! feof(archivoPalabras)) { //feof regresa 0 si no existe el end-of-file
            //Obtenemos la cadena
            fgets(cadena, 10000, archivoPalabras); //Se detiene en 10000 o en EOF. Se guarda en "cadena".
            //Con strtok separamos cada vez que se encuentre un espacio
            cadenaSeparada = strtok(cadena, " ");
            while (cadenaSeparada != NULL) {
                nuevo = (PALABRA *) malloc (sizeof (PALABRA)); //Inicializar nuevo
                nuevo->siguiente = NULL;
                nuevo->anterior = NULL;
                strcpy(nuevo->palabraOrdenada, cadenaSeparada);
                
                //Ordenar palabras
                
                if (inicio == NULL) {
                    inicio = nuevo;
                } else {
                    actual = inicio;
                    printf("Justo antes del while\n");
                    while (actual != NULL && !encontrado) {
                        if (strcmp(nuevo->palabraOrdenada, actual->palabraOrdenada) <= 0) {
                            //Ordenar palabras
                        }
                        actual = actual->siguiente;
                    }
                    printf("Saliendo del while\n");
                }
                printf ("Cadena separada: %s\n",cadenaSeparada); //Imprime cada cadenaSeparada
                cadenaSeparada = strtok (NULL, " ");//Para que siga dividiendo donde se quedo
            }
        }
    }
    
    fclose(archivoPalabras);
    
    //Imprimimos palabras en orden alfabetico de nuestra lista:
    actual = inicio;
    while (actual != NULL) {
        printf("Palabra desde la lista: %s\n", actual->palabraOrdenada);
        actual = actual->siguiente;
    }
    
    return 0;	
}