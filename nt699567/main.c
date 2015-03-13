//
//  main.c
//  suma9
//
//  Created by Dante on 3/12/15.
//  Copyright (c) 2015 Dante. All rights reserved.
//

#include <stdio.h>

int Cantidad_Digitos(int Num){
    int cantdig=0;
    while(Num!=0)
    {
        Num=Num/10;
        cantdig=cantdig+1;
    } 
    return cantdig;
}

int odiolasfunciones(int num2){
    
    int k=1, resto[6], deshonra=num2, i=0, r=0;
    
    while(!(deshonra>=10&&deshonra<=19)){
        
        resto[i]=deshonra%10;
        deshonra=deshonra/10;
        i++;
    }
    
    i=0;
    
    while(k<Cantidad_Digitos(num2)||r!=0) {
        r=deshonra%k;
        k++;
        deshonra=(deshonra*10)+resto[i];
        i++;
    }
    
    return 0;
}

int digitos(int numero){
    
    int n=numero, j[9], i=0, cont[9];
    
    while(n>0){
        j[i]=n%10;
        n=n/10;
        i++;
    }
    
    for(i=0;i<8;i++){
        if (j[i] == '1') cont[0]++;
        if (j[i] == '2') cont[1]++;
        if (j[i] == '3') cont[2]++;
        if (j[i] == '4') cont[3]++;
        if (j[i] == '5') cont[4]++;
        if (j[i] == '6') cont[5]++;
        if (j[i] == '7') cont[6]++;
        if (j[i] == '8') cont[7]++;
        if (j[i] == '9') cont[8]++;
    }
    
    if((cont[0]==1)&&(cont[1]==1)&&(cont[2]==1)&&(cont[3]==1)&&(cont[4]==1)&&(cont[5]==1)&&(cont[6]==1)&&(cont[7]==1)&&(cont[8]==1)){
    
    if(odiolasfunciones(numero)==0){
        printf("%i/n", numero);
        }
    }
    
    return digitos(numero+1);
}

int main(){
    
    int x=1, i;
    
    for(i=1;i<=987654321;i++){
        digitos(x);
    }
    return 1;
    
}
