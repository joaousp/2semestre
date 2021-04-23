#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"numero.h"

int main(){
    lista_t *numero_a,*numero_b;
    char ordem[4];
    char num1[20],num2[20];
    int n,neg1,neg2;
    char c=0;
    int aux;
    int i=0,j;
    numero_a=criar();
    numero_b=criar();
    
    scanf("%d", &n);

    for( j=0;j<n;j++){
        scanf(" %s %s %s",ordem,num1,num2);
    
        neg1=1;
        neg2=1;
        i=0;
       
        while(i<strlen(num1)){
        
            if(num1[i]=='-'){
                neg1=-1;
                i++;
            }
          
            aux=num1[i]-'0';
            inserir(numero_a,aux);
            i++;
        }
        aux=0;
        i=0;
        
        
        while(i<strlen(num2)){
            if(num2[i]=='-'){
                neg2=-1;
                i++;
            }
            
            aux=num2[i]-'0';
            inserir(numero_b,aux);
            i++;
        }
        aux=0;
        

        
        
        if(strcmp(ordem,"sum")==0){
            printf("Resultado %d: ",j+1);
            sum(numero_a,numero_b,neg1,neg2);
            
            
        }
        
        if(strcmp(ordem,"sml")==0){
            aux=sml(numero_a,numero_b,neg1,neg2);
            printf("Resultado %d: %d\n",j+1,aux);
        }
        
        
        if(strcmp(ordem,"eql")==0){
            aux=eql(numero_a,numero_b,neg1,neg2);
           printf("Resultado %d: %d\n",j+1,aux);
        }
        if(strcmp(ordem,"big")==0){
            aux=big(numero_a,numero_b,neg1,neg2);
            printf("Resultado %d: %d\n",j+1,aux);
        }
        
        numero_a=limpar(numero_a);
        numero_b=limpar(numero_b);
        
    }

    liberar(numero_a);
    liberar(numero_b);
   
    return 0;
}

