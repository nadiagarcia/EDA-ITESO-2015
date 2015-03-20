#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nombres
{
    char nombre1[20];
    struct nombres* siguiente;
} NOMBRES;
int main()
{
    int num=1;
    char nombre1[20];
    NOMBRES* inicio = NULL;
    NOMBRES* actual = inicio;
    NOMBRES* atras = NULL;
    NOMBRES* nuevo = NULL;

    while(num!=0)
    {

        printf("cual es el nombre de tu amigo:\n");

        if(inicio==NULL)
        {
            inicio=(NOMBRES *)malloc(sizeof(NOMBRES));
            scanf("%s",inicio->nombre1);
            fflush(stdin);
            inicio->siguiente=NULL;

        }
        else
        {
            int insertado=0;
            scanf("%s",&nombre1);
            fflush(stdin);
            actual=inicio;
            while(actual!=NULL &&  insertado==0)
            {
                //necesitabamos obtener la diferencia entre el nombre ingresado y el que ya teniamos asi que si se ingresaba un nombre igual en el ciclo se volvia a imprimir//
                if(strcmp(actual->nombre1,nombre1)>=0)
                {
                    if(actual==inicio)
                    {
                        NOMBRES* nuevo=(NOMBRES *)malloc(sizeof(NOMBRES));
                        strcpy(nuevo->nombre1,nombre1);
                        nuevo->siguiente=inicio;
                        inicio=nuevo;
                        insertado=1;
                    }
                    else
                    {
                        NOMBRES* nuevo=(NOMBRES *)malloc(sizeof(NOMBRES));
                        strcpy(nuevo->nombre1,nombre1);
                        nuevo->siguiente=actual;
                        atras->siguiente=nuevo;
                        insertado=1;
                    }


                }
                atras=actual;
                actual=actual->siguiente;
            }

            if(actual==NULL)
            {
                NOMBRES* nuevo=(NOMBRES *)malloc(sizeof(NOMBRES));
                strcpy(nuevo->nombre1,nombre1);
                nuevo->siguiente=NULL;
                atras->siguiente=nuevo;

            }
        }

        scanf("%d",&num);
        fflush(stdin);
    }

    actual=inicio;
    while(actual!=NULL)
    {
        printf("%s\n",actual->nombre1);
        actual=actual->siguiente;
    }

    return 0;
}
