#include<stdio.h>
#include "arvore.h"

int main(){
    int n;
    int pai, dir,esq;
    arvore_t *arvore;
    arvore=criar();
    scanf("%d",&n);
    while(n>0){
        scanf("%d %d %d",&pai,&esq,&dir);
        inserir_esq(arvore,esq,pai);
        inserir_dir(arvore,dir,pai);
    }
    imprimir(arvore);
}