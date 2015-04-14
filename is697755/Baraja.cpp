#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilas.h"
#include "colas.h"

// Valores

char As[] 	  = "As";
char dos[] 	  = "2";
char tres[]   = "3";
char cuatro[] = "4";
char cinco[]  = "5";
char seis[]   = "6";
char siete[]  = "7";
char ocho[]   = "8";
char nueve[]  = "9";
char diez[]   = "10";
char J[] 	  = "J";
char Q[] 	  = "Q";
char K[]	  = "K";

// Imágenes

char corazones[] = "Corazones";
char espadas[]   = "Espadas";
char diamantes[] = "Diamantes";
char treboles[]  = "Treboles";

void barajar_cartas(PILA **baraja){
	int random_c, n_cartas = 0, random_i, temp_v;
	char temp_carta[] = {12,12,12,12,12,12,12,12,12,12,12,12,12};
				//  A, 2, 3, 4, 5, 6, 7, 8, 9,10, J, Q, K
	char temp_img[13][4] = {
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3},
		{3, 3, 3, 3}
	};
	
	while(!isEmpty(*baraja)){
		pop(baraja);
	}
	while(n_cartas < 156){
		random_c = rand() % 13;
		random_i = rand() % 4;
		if(temp_carta[random_c] != 0 && temp_img[random_c][random_i] != 0){
			temp_carta[random_c] -= 1;
			temp_img[random_c][random_i] -= 1;
			temp_v = random_c;
			if(random_i == 0) ;							// Corazones
			else if(random_i == 1) temp_v += 100;		// Espadas
			else if(random_i == 2) temp_v += 200;		// Treboles
			else if(random_i == 3) temp_v += 300;		// Diamantes
			push(baraja, temp_v);
			n_cartas++;
		}
	}
}

void repartir_carta(PILA **baraja, char *valor, char *imagen){
	int temp = top(*baraja);
	
	if(temp < 100) strncpy(imagen, corazones, strlen(corazones)), imagen[strlen(corazones)] = '\0';
	else if(temp < 200) strncpy(imagen, espadas, strlen(espadas)), imagen[strlen(espadas)] = '\0', temp-= 100;
	else if(temp < 300) strncpy(imagen, treboles, strlen(treboles)), imagen[strlen(treboles)] = '\0', temp-= 200;
	else if(temp < 200) strncpy(imagen, diamantes, strlen(diamantes)), imagen[strlen(diamantes)] = '\0', temp-= 300;
	
	if(temp == 0) strncpy(valor, As, strlen(As)), valor[strlen(As)] = '\0';
	else if(temp == 1)  strncpy(valor, J, strlen(J)), valor[strlen(J)] = '\0';
	else if(temp == 2) strncpy(valor, dos, strlen(dos)), valor[strlen(dos)] = '\0';
	else if(temp == 3) strncpy(valor, tres, strlen(tres)), valor[strlen(tres)] = '\0';
	else if(temp == 4) strncpy(valor, cuatro, strlen(cuatro)), valor[strlen(cuatro)] = '\0';
	else if(temp == 5) strncpy(valor, cinco, strlen(cinco)), valor[strlen(cinco)] = '\0';
	else if(temp == 6) strncpy(valor, seis, strlen(seis)), valor[strlen(seis)] = '\0';
	else if(temp == 7) strncpy(valor, siete, strlen(siete)), valor[strlen(siete)] = '\0';
	else if(temp == 8) strncpy(valor, ocho, strlen(ocho)), valor[strlen(ocho)] = '\0';
	else if(temp == 9) strncpy(valor, nueve, strlen(nueve)), valor[strlen(nueve)] = '\0';
	else if(temp == 10) strncpy(valor, diez, strlen(diez)), valor[strlen(diez)] = '\0';
	else if(temp == 11) strncpy(valor, Q, strlen(Q)), valor[strlen(Q)] = '\0';
	else if(temp == 12) strncpy(valor, K, strlen(K)), valor[strlen(K)] = '\0';
		
}

int isNumber(char numero){
	if(numero>47&&numero<58) return 1;
	else return 0;
}

int main(){
	PILA *baraja = NULL;
	char valor[3];
	char imagen[10]; 
	int numero_carta = 1;
	barajar_cartas(&baraja);
	while(!isEmpty(baraja)){
		/*repartir_carta(&baraja, valor, imagen);	
		pop(&baraja);
		printf("%s, %s, %d\n", valor, imagen,numero_carta);	  
		numero_carta++;*/
		printf("%d\n", pop(&baraja));
	}
}
