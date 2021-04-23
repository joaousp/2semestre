#include<stdio.h>
#include "arvore.h"

int main(){
    int n,ordem,aux;
    arvore_t *arvore;
    arvore=criar();
    scanf("%d",&n);
    while(n>0){
        scanf("%d",&ordem);
        switch (ordem){
            case 1:
            //insercao
                scanf("%d", &aux);
                inserir(arvore,aux);
                break;
            case 2:
            //sucessor
                scanf("%d", &aux);
                sucessor((arvore->raiz),aux);
                break;
            case 3:
            //predecessor
                scanf("%d", &aux);
                predecessor((arvore->raiz),aux);
                break;
            case 4:
            //maximo
                maximo((arvore->raiz));
                break;
            case 5:
            //minimo
                minimo((arvore->raiz));
                break;
            case 6:
            //pre-ordem
                pre_ordem(arvore->raiz);
                printf("\n");
                break;
            case 7:
                em_ordem(arvore->raiz);
                printf("\n");
                break;
            case 8:
                pos_ordem(arvore->raiz);
                printf("\n");
                break;
        }
        n--;
    }
    finalizar(arvore->raiz);
}