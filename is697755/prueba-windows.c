#include <conio.h>
#include <stdio.h>																
#include <stdlib.h>

typedef struct numero{
	int numero;
	struct numero *siguiente;
	struct numero *anterior;
}NUMERO;

int main(){
	
   	char c = 0;
	int n;
	// NUMERO 1 ========================================================
	NUMERO *numero1=(NUMERO *)malloc(sizeof(NUMERO));
	numero1->numero=0;
	numero1->siguiente=NULL;
	numero1->anterior=NULL;
	NUMERO *actual = numero1;
	printf("Dame el numero 1\n");
	
	while(c != 13){

    	c = getch();
    	n = c-48;
    	
    	if(n>=0 && n<=9){
		
	    	actual->siguiente = (NUMERO *)malloc(sizeof(NUMERO));
	    	actual->siguiente->anterior = actual;
	    	actual = actual->siguiente;
	    	actual->numero = n;
	    	actual->siguiente = NULL;
	    	
	    	printf("%d",n);
		}
   	}
   	
   	// NUMERO 2 ========================================================
   	c = 0;
	printf("\nDame el numero 2\n");
   	
	NUMERO *numero2=(NUMERO *)malloc(sizeof(NUMERO));
	numero2->numero=0;
	numero2->siguiente=NULL;
	numero2->anterior=NULL;
	actual = numero2;
	
	
	while(c != 13){

    	c = getch();
    	n = c-48;
    	
    	if(n>=0 && n<=9){
	    	actual->siguiente = (NUMERO *)malloc(sizeof(NUMERO));
	    	actual->siguiente->anterior = actual;
	    	actual = actual->siguiente;
	    	actual->numero = n;
	    	actual->siguiente = NULL;
	    	
	    	printf("%d",n);
		}
   	}
   	
   	printf("\nLos numeros: \n");
   	NUMERO *actual_num1=numero1;
   	
   	printf("Numero 1: ");	
	while(actual_num1->siguiente!= NULL){      //Hicimos el otro apuntador porque vamos a aprovechar que ya llegamos al final de la lista
   												// para luego poder sumarlo
		printf("%d", actual_num1->numero);
   		actual_num1=actual_num1->siguiente;
	}
	   
	printf("%d\n",actual_num1->numero);    //porque en el ciclo no se imprime el último dígito
	   
	NUMERO *actual_num2=numero2;
   	
   	printf("Numero 2: ");
	while(actual_num2->siguiente!= NULL){
   		printf("%d", actual_num2->numero);
   		actual_num2=actual_num2->siguiente;
	}
	   
	printf("%d\n",actual_num2->numero);   

   //suma
   NUMERO *resultado;
   int carry=0;
   int suma;
   
   while(actual_num2 !=NULL){
   		suma = carry + actual_num1->numero + actual_num2->numero;
   		resultado = (NUMERO *)malloc(sizeof(NUMERO));
   		resultado->siguiente=NULL;
   		resultado->anterior=NULL;
   		if(suma>9){
   			carry=1;
		}
   }
   
   
	return 0;
}
