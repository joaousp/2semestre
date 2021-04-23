#include<stdio.h>
#include<stdlib.h>
#include "banco.h"
int main(void){
    banco_t *b=criar();
    elem x;
    int i=0;
    for(i;i<5;i++){
        inserir(b,i);
    }
    while(!vazio(b)){
        remover(b,&x);
        printf("%d",x);
    }

    
    return 0;
}