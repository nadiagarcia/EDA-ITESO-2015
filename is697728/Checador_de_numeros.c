#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int contador=0,a,b,c,d,e,f,g,h,i;

int longi(int j){
	
	if(j<0)
		return 0;
	if(j<10)
		return 1;
	if(j<100)
		return 2;
	if(j<1000)
		return 3;
	if(j<10000)
		return 4;
	if(j<100000)
		return 5;
	if(j<1000000)
		return 6;
	if(j<10000000)
		return 7;
	if(j<100000000)
		return 8;
	if(j<1000000000)
		return 9;
		
	return -1;
	
}

int inicializar(){
	a=0;
	b=0;	
	c=0;
	d=0;
	e=0;
	f=0;
	g=0;
	h=0;
	i=0;
}

int revisar(int j,int original){
	
	inicializar();
	
	int actual;
	
	if(j == 0)
		printf("%d es valido\n",original);
				
	if(j%longi(j)==0){
		
		if(j%10!=0){
			
			actual=j%10;
			
			if(actual != a && actual != b && actual != c && actual != d && actual != e && actual != f&& actual != g && actual != h && actual != i){
				if(contador = 0){
					a = contador;
				}
				if(contador = 1){
					b = contador;
				}
				if(contador = 2){
					c = contador;
				}
				if(contador = 3){
					d = contador;
				}
				if(contador = 4){
					e = contador;
				}
				if(contador = 5){
					f = contador;
				}
				if(contador = 6){
					g = contador;
				}
				if(contador = 7){
					h = contador;
				}
				if(contador = 8){
					i = contador;
				}
				contador++;
				
				return revisar(j/10,original); 
				
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;
	
	
}

int main(){
	int i,copia;

	for(i = 1;i < 987654321;i++){
		revisar(i,i);	
	}
	
	return 0;
}