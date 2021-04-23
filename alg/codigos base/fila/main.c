#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "fila.h"

int main(){
    fila_t *f;
    int i;
    int n;
    f=criar();
    for(i=0;i<10;i++){
        inserir(f,i);
    } 
    while(i>0){
        remover(f,&n);
        printf("%d", n);
        i--;
    }
    destruir(f);
}