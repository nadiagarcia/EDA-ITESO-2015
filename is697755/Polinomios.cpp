#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct polinomio{
	int signo;
	int coeficiente;
	int exponente;
	struct polinomio *siguiente;
}POLI;

int main(){
	
	system("color F");
	
	char c=0;
	int n;
	int i=0;
	int found_m;
	int found_e;
	int evaluar;
	int resultado=0;
	int multiplicar=0;
	
	
	POLI *inicio = NULL;
	POLI *nuevo;
	POLI *actual=inicio;
	
	printf("Manera ineficiente, pero queria ver si podia practicar aqui el strtok.\n\n\n");
	
	char str[100];
  	char * pch;
  	printf("Ingresa el polinomio en 'x' con sus respectivos signos, cada termino separado por comas.\n*Si");
  	printf(" se quieren usar coeficientes mayores a 9 tienen que separarse los terminos (Por ejemplo:\"x^2,+9x,+5x-2\")\n");
  	scanf("%s",str);
  	printf("Con que numero quieres evaluar 'x'?\n");
  	scanf("%d",&evaluar);
  	printf ("Splitting string \"%s\" into tokens:\n",str);
  	pch = strtok (str," ,");
  	
  	// guardar en la estructura
  	
  	
	while (pch != NULL){
		
		found_m=0;
		found_e=0;
		i=0;
		multiplicar=0;
		
    	printf ("%s\n",pch);
    	nuevo=(POLI *)malloc(sizeof(POLI));
    	nuevo->siguiente=NULL;
    	
    	// Ver si tiene que sustituirse algo
		
		while(pch[i]!=NULL){
			if(pch[i]=='x'){
				multiplicar=1;
				found_m=1;
			}
			i++;
		}	
		i=0;
	
    	
    	// Encontrar el exponente
		if(found_m==0){
			nuevo->exponente=0;
			printf("Exponente de 'x': %d\n",nuevo->exponente);
		}
		else{
			while(pch[i]!=NULL||pch[i-1]=='^'){
				if(pch[i]=='^'){
					nuevo->exponente=pch[i+1]-48;
					printf("Exponente: %d\n",nuevo->exponente);
					found_e=1;
				}
				i++;
			}
			
			if(multiplicar==1&&found_e==0){
				nuevo->exponente=1;
				printf("Exponente de 'x': %d\n",nuevo->exponente);
			}
		
		}
		i=0;
		// Encontrar el coeficiente
		
		if(pch[1]!='x'&&pch[1]!='^'&&pch[1]!=NULL){
			nuevo->coeficiente=pch[1]-48;
			printf("Coeficiente: %d\n",nuevo->coeficiente);
		}else if(pch[0]!='+'&&pch[0]!='-'&&pch[0]!='x'){
			nuevo->coeficiente=pch[0]-48;
			printf("Coeficiente: %d\n",nuevo->coeficiente);
		}
		else{
			nuevo->coeficiente=1;
			printf("Coeficiente: %d\n",nuevo->coeficiente);
		}
	
		
		// Encontrar el signo y sumar/restar al resultado
		
		if(pch[0]=='+'||pch[0]!='-'){
			nuevo->signo=1;
			printf("Signo: positivo.\n");
			resultado+= pow(evaluar,nuevo->exponente) * nuevo->coeficiente;
		}
		else{
			nuevo->signo=0;
			printf("Signo: negativo.\n");
			resultado-= pow(evaluar,nuevo->exponente) * nuevo->coeficiente;
		}
		
		printf("Suma: %d\n",resultado);
		
    	pch = strtok (NULL, " ,");
    	if(inicio==NULL){
			inicio=nuevo;
		}	
		else{
			nuevo->siguiente=inicio;
			inicio=nuevo;
		}
  	}
	
	printf("Resultado final: %d\n",resultado);
	
	return 0;
}
