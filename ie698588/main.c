#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define PASS 12345

/*
Funciones para usuario:
    -Buscar: por pelicula o videojuego-----------------------------------------------
        Rentar o comprar
    -Imprimir: por pelicula o videojuego---------------------------------------------
        Rentar o comprar
    -Carrito de compra/renta
        Cantidad
        Costo total

Funciones para empleado:
    -Agregar: por pelicula o videojuego-----------------------------------------------
    -Borrar: por pelicula o videojuego
    -Contraseña-----------------------------------------------------------------------
    -Imprimir: por pelicula o videojuego----------------------------------------------
    -Alterar informacion:-----------------------------------------------------------

*/
struct pelicula
{
	char nombrep[25];
	char generop[15];
	int aniop;
	int costop;
	int dias_rentap;
	int cantidadp; //disponibilidad en la tienda
	struct pelicula *siguiente, *anterior;
}typedef PELICULA;

struct juego
{
	char nombrej[25];
	char consolaj[15];
	int anioj;
	int costoj;
	int dias_rentaj;
	int cantidadj; //disponibilidad en la tienda
	struct juego *siguiente, *anterior;
}typedef JUEGO;

void agregar (PELICULA **iniciop, JUEGO **inicioj){//Terminada

        PELICULA *actualp = *iniciop;
        JUEGO *actualj = *inicioj;
        int op, m, aux = 0, suma;

        printf("\tQue desea agregar?\n");
        printf("1.Pelicula  2.Videojuego");
        scanf("%d", &op);
        PELICULA *nuevop = (PELICULA*) malloc(sizeof(PELICULA));//Se declaran las variables tipo PELICULA
        JUEGO *nuevoj = (JUEGO*) malloc(sizeof(JUEGO));//Se declaran las varialbes tipo JUEGO
        nuevop->siguiente = NULL;//Se apunta a NULL
        nuevoj->siguiente = NULL;//Se apunta a NULL
        nuevop->anterior = NULL;
        nuevoj->anterior = NULL;
        system("cls");

        switch(op){
        case 1://Peliculas

            printf("\tAgregar una pelicula nueva\n");
            printf("\nNombre:");
            fflush(stdin);
            gets(nuevop->nombrep);
            printf("\nGenero:");
            fflush(stdin);
            gets(nuevop->generop);
            printf("\nAnio:");
            scanf("%d", &nuevop->aniop);
            printf("\nCosto:");
            scanf("%d",&nuevop->costop);
            printf("\nDias de renta a disponibilidad:");
            scanf("%d",&nuevop->dias_rentap);
            printf("\nNumero de elementos en la tienda:");
            scanf("%d",&nuevop->cantidadp);
            system("cls");

            if(*iniciop == NULL){//Si no hay aun elementos en la lista
                *iniciop = nuevop;
            }
            else {

                while(aux == 0){//mientras el primero se mas grande que el segundo
                    m = strcmp(nuevop->nombrep,actualp->nombrep);
                    if(m<0 && actualp == *iniciop){//Si el elemento nuevo es menor que todos incluyendo al inicio
                        nuevop->siguiente = actualp;
                        *iniciop = nuevop;
                        actualp->anterior = nuevop;
                        aux = 1;
                    }
                    else if(m == 0){//Si el elemento a agregar ya existe en la lista
                        actualp->cantidadp++;
                        aux = 1;
                    }
                    else if(m<0){//Hasta que ecuentre un actual mayor a nuevo
                        nuevop->siguiente = actualp;
                        nuevop->anterior = actualp->anterior;
                        actualp->anterior->siguiente = nuevop;
                        actualp->anterior = nuevop;
                        aux = 1;
                    }
                    else if(actualp->siguiente == NULL){//Si se tiene que agregar al final
                        actualp->siguiente = nuevop;
                        nuevop->anterior = actualp;
                        aux = 1;
                    }
                    actualp = actualp->siguiente;
                }
            }

        break;

        case 2://Videojuegos

            printf("\tAgregar un juego nuevo\n");
            printf("\nNombre:");
            fflush(stdin);
            gets(nuevoj->nombrej);
            printf("\nConsola:");
            fflush(stdin);
            gets(nuevoj->consolaj);
            printf("\nAnio:");
            scanf("%d", &nuevoj->anioj);
            printf("\nCosto:");
            scanf("%d",&nuevoj->costoj);
            printf("\nDias de renta a disponibilidad:");
            scanf("%d",&nuevoj->dias_rentaj);
            printf("\nNumero de elementos en la tienda:");
            scanf("%d",&nuevoj->cantidadj);
            system("cls");

            if(*inicioj == NULL){//Si no hay aun elementos en la lista
                *inicioj = nuevoj;
            }
            else {

                while(aux == 0){//mientras no se haya agregado
                    m = strcmp(nuevoj->nombrej,actualj->nombrej);
                    if(m<0 && actualj == *inicioj){//Si el elemento nuevo es menor que todos incluyendo al inicio
                        nuevoj->siguiente = actualj;
                        *inicioj = nuevoj;
                        actualj->anterior = nuevoj;
                        aux = 1;
                    }
                    else if(m == 0){//Si el elemento ya existe en la lista
                        actualj->cantidadj++;
                        aux = 1;
                    }
                    else if(m<0){//Hasta que ecuentre un actual mayor a nuevo
                        nuevoj->siguiente = actualj;
                        nuevoj->anterior = actualj->anterior;
                        actualj->anterior->siguiente = nuevoj;
                        actualj->anterior = nuevoj;
                        aux = 1;
                    }
                    else if(actualj->siguiente == NULL){//Si se tiene que agregar al final
                        actualj->siguiente = nuevoj;
                        nuevoj->anterior = actualj;
                        aux = 1;
                    }
                    actualj = actualj->siguiente;
                }
            }

        break;
        }
}

void borrar(PELICULA **iniciop, JUEGO **inicioj){//Terminada

    PELICULA *actualp = *iniciop;
    JUEGO *actualj = *inicioj;
    int op, m, aux = 0;
    char nombre_pelicula[25], nombre_juego[25];

    printf("Que desea borrar?\n");
    printf("1.Pelicula  2.Videojuego\n");
    scanf("%d", &op);
    system("cls");

    switch(op){

    case 1://Pelicula

        printf("\t***BORRAR PELICULAS***\n");
        printf("Ingrese el nombre de la pelicula\n");
        fflush(stdin);
        gets(nombre_pelicula);

        while(aux == 0){
            m = strcmp(nombre_pelicula,actualp->nombrep);

            if(m == 0 && actualp == *iniciop){//Cuando se elimina el primer elemento de la lista   LISTO
                *iniciop = actualp->siguiente;
                free(actualp);
                aux = 1;
                printf("\n%s ha sido eliminada con exito.", nombre_pelicula);
            }
            else if(m == 0 && actualp->siguiente != NULL){//Si el elemento esta en medio  de la lista   LISTO
                actualp->anterior->siguiente = actualp->siguiente;
                actualp->siguiente->anterior = actualp->anterior;
                free(actualp);
                aux = 1;
                printf("\n%s ha sido eliminada con exito.", nombre_pelicula);
            }
            else if(m == 0 && actualp->siguiente == NULL){//Si el elemento esta al final de la lista    LISTO
                actualp->anterior->siguiente = NULL;
                free(actualp);
                aux = 1;
                printf("\n%s ha sido eliminada con exito.", nombre_pelicula);
            }
            else if( actualp->siguiente == NULL && m != 0){//Si el elemento no se encuentra en la lista
                printf("\n%s no se encuentra en la lista", nombre_pelicula);
                aux = 1;
            }
            actualp = actualp->siguiente;
        }
        getch();

        break;

    case 2://Videojuego

        printf("\t***BORRAR VIDEOJUEGOS***\n");
        printf("Ingrese el nombre del videojuego\n");
        fflush(stdin);
        gets(nombre_juego);

        while(aux == 0){
            m = strcmp(nombre_juego,actualj->nombrej);

            if(m == 0 && actualj == *inicioj){//Cuando se elimina el primer elemento de la lista   LISTO
                *inicioj = actualj->siguiente;
                free(actualj);
                aux = 1;
                printf("\n%s ha sido eliminada con exito.", nombre_juego);
            }
            else if(m == 0 && actualj->siguiente != NULL){//Si el elemento esta en medio  de la lista   LISTO
                actualj->anterior->siguiente = actualj->siguiente;
                actualj->siguiente->anterior = actualj->anterior;
                free(actualj);
                aux = 1;
                printf("\n%s ha sido eliminada con exito.", nombre_juego);
            }
            else if(m == 0 && actualj->siguiente == NULL){//Si el elemento esta al final de la lista    LISTO
                actualj->anterior->siguiente = NULL;
                free(actualj);
                aux = 1;
                printf("\n%s ha sido eliminada con exito.", nombre_juego);
            }
            else if( actualj->siguiente == NULL && m != 0){//Si el elemento no se encuentra en la lista
                printf("\n%s no se encuentra en la lista", nombre_juego);
                aux = 1;
            }
            actualj = actualj->siguiente;
        }
        getch();
        break;
    }
}

void buscar (PELICULA **iniciop, JUEGO **inicioj){//Terminada junto con Rentar
    //Declaracion de punteros actuales (auxiliares)
    PELICULA *actualp = *iniciop;
    JUEGO *actualj = *inicioj;
    //Declaracion de variables
    char nombre_pelicula[25], nombre_juego[25];
    int op, m, aux = 0, renta, existente = 1;
    system("cls");

    printf("\tQue desea buscar?\n");
    printf("\n1.Peliculas  2.Videojuegos");
    scanf("%d",&op);
    system("cls");

    switch(op){

    case 1://Peliculas
        if(*iniciop == NULL){
            printf("\nAun no hay elementos en la tienda.");
        }
        else{

            printf("\tIngrese el nombre de la pelicula:");
            fflush(stdin);
            gets(nombre_pelicula);
            system("cls");

            while(aux == 0){
                m = strcmp(nombre_pelicula, actualp->nombrep);

                if(m == 0){
                    printf("\t%s\n", nombre_pelicula);
                    printf("\nNombre: %s",actualp->nombrep);
                    printf("\nGenero: %s",actualp->generop);
                    printf("\nAnio: %d",actualp->aniop);
                    printf("\nCosto: %d",actualp->costop);
                    printf("\nDias de renta: %d",actualp->dias_rentap);
                    printf("\nElementos en la tienda: %d\n", actualp->cantidadp);
                    aux = 1;
                }
                else if(m != 0 && actualp->siguiente == NULL){//si el elemento no esta en la lista
                    printf("\n%s no se encuentra en la tienda.", nombre_pelicula);
                    existente = 0;
                    aux = 1;
                }
                actualp = actualp->siguiente;
            }
            if(existente){
                printf("\nDesea rentarla?");
                printf("\n1.Si / 0.No");
                scanf("%d", &renta);
                if(renta){//El usuario desea rentar la pelicula
                    actualp = actualp->anterior;
                    actualp->cantidadp = actualp->cantidadp-1;
                }
            }
        }
        break;

    case 2://Videojuegos

        if(*inicioj == NULL){
            printf("\nAun no hay elementos en la tienda.");
        }
        else{

            printf("\tIngrese el nombre del videojuego:");
            fflush(stdin);
            gets(nombre_juego);
            system("cls");

            while(aux == 0){
                m = strcmp(nombre_juego, actualj->nombrej);

                if(m == 0){
                    printf("\t%s\n", nombre_juego);
                    printf("\nNombre: %s",actualj->nombrej);
                    printf("\nGenero: %s",actualj->consolaj);
                    printf("\nAnio: %d",actualj->anioj);
                    printf("\nCosto: %d",actualj->costoj);
                    printf("\nDias de renta: %d",actualj->dias_rentaj);
                    printf("\nElementos en la tienda: %d\n", actualj->cantidadj);
                    aux = 1;
                }
                else if(m != 0 && actualj->siguiente == NULL){//si el elemento no esta en la lista
                    printf("\n%s no se encuentra en la tienda.", nombre_juego);
                    existente = 0;
                    aux = 1;
                }
                actualj = actualj->siguiente;
            }
            if(existente){
                printf("\nDesea rentarlo?");
                printf("\n1.Si / 0.No");
                scanf("%d", &renta);
                if(renta){//El usuario desea rentar la pelicula
                    actualj = actualj->anterior;
                    actualj->cantidadj = actualj->cantidadj-1;
                }
            }
        }
        break;
    }
    getch();

}

void imprimir(PELICULA **iniciop, JUEGO **inicioj){  //Terminada

void carrito (){//El usuario podra ver que lleva rentado y cuanto le costara


}

    PELICULA *actualp = *iniciop;
    JUEGO *actualj = *inicioj;
    int op;
    system("cls");

    printf("Que desea imprimir?\n");
    printf("1.Pelicula  2.Videojuego\n");
    scanf("%d", &op);
    system("cls");

    switch(op){

    case 1://Pelicula

        printf("\t***PELICULAS***\n");

        if(actualp == NULL){
            printf("\nNo hay peliculas");
        }
        else{
            while(actualp != NULL){
            printf("\nNombre: %s",actualp->nombrep);
            printf("\nGenero: %s",actualp->generop);
            printf("\nAnio: %d",actualp->aniop);
            printf("\nCosto: %d",actualp->costop);
            printf("\nDias de renta: %d",actualp->dias_rentap);
            printf("\nElementos en la tienda: %d\n", actualp->cantidadp);

            actualp = actualp->siguiente;
            }
        }
        getch();
        break;

    case 2://Videojuego

        printf("\t***VIDEOJUEGOS***\n");

        if(actualj == NULL){
            printf("No hay videojuegos");
        }
        else{
            while(actualj != NULL){
            printf("\nNombre: %s",actualj->nombrej);
            printf("\nConsola: %s", actualj->consolaj);
            printf("\nAnio: %d",actualj->anioj);
            printf("\nCosto: %d",actualj->costoj);
            printf("\nDias de renta: %d",actualj->dias_rentaj);
            printf("\nElementos en la tienda: %d\n", actualj->cantidadj);

            actualj = actualj->siguiente;
            }
        }
        getch();
        break;
    }
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	//Declaracion de variables de main
	int op, out, id, password, op_usuario;
	//Declaracion de punteros inicio de las dos listas
	PELICULA * iniciop = NULL;
	JUEGO * inicioj = NULL;

    while(out){
        printf("\t   *** BIENVENIDO BLOCK BLISTER ***\n\n\n");
        printf("\t\tDECIDA MODO DE INGRESO\n\n");
        printf("\t  1.Usuario              0.Administrador\n");
        scanf("%d", &id);
        system("cls");
        if(id){//modo usuario
            printf("\t<<<MODO USUARIO>>>\n\n\t\t");
            printf("\n\n\tQue desea hacer?\n");
            printf("\n1.Imprimir todos los elementos \n2.Buscar un elemento");
            scanf("%d",&op_usuario);
            if(op_usuario == 1)//Si usuario elige imprimir elementos
                imprimir(&iniciop,&inicioj);
            else //Si usuario elige buscar elementos
                buscar(&iniciop, &inicioj);
        }
        else{//modo empleado
            int cont = 3;
			 while(cont!=0){
                printf("\n\n\nIngrese la contrasenia: ");
                scanf("%i", &password);

                if (password==PASS){
                    system("cls");
                    do{
                        system("cls");
                        printf("\n\t\tIngrese la opcion deseada\n\n");
                        printf("\t1.Agregar un elemento\n\t2.Borrar un elemento\n\t3.Buscar un elemento\n\t4.Imprimir todo\n\t5.Salir");
                        scanf("%d", &op);
                        system("cls");

                        switch(op){
                        case 1:

                            agregar(&iniciop, &inicioj);
                        break;

                        case 2:

                            borrar(&iniciop, &inicioj);
                        break;

                        case 3:

                            buscar(&iniciop, &inicioj);
                        break;

                        case 4:

                            imprimir(&iniciop, &inicioj);
                        break;

                        }
                    }while(op != 5);
                }
                else{
                    system("cls");
                    cont--;
                    printf("\n\n>>>>CONTRASENIA INCORRECTA<<<<\nUsted tiene %i opciones mas", cont);
                }
			}
       }
        printf("\n\nDesea Salir? (0.SI/1.NO)");
        scanf("%d", &out);
        system("cls");
    }
	return 0;

}
