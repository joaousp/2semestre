#include<stdio.h>
#include<stdlib.h>
#include "biblioteca.h"

int main(){
    char letra='a';
    int n,j,tempo=0;
    lista_t *l;
    l=cria();
    while(letra!='f'){
        scanf("%c", &letra);
        if(letra=='i'){
            
            scanf("%d %d", &n,&j);
            inserir(l,n,j,tempo);
            tempo++;
        }
        if(letra=='r'){
            scanf("%d", &n);
            remove_elemento(l,n);
            tempo++;
        }
    }
    imprimir(l);
    
    return 0;
    }

