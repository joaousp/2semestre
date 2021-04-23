#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
struct pilha {
    int topo;
    elem items[TamPilha];
};
int main(){
    pilha_t *inverter;
    pilha_t *compra;
    pilha_t *descarte;
    pilha_t  *morto;
    int v, carta=1, aux;
    int n,i,rodada=0;
    scanf("%d", &n);
    //3
    //2 1 3
    inverter=create();
    compra=create();
    descarte=create();
    morto=create();
    for(i=0;i<n;i++){
        scanf("%d",&v);
        push(inverter,(elem)v);
    }
    while(!isEmpty(inverter)){
        pop(inverter,&aux);
        push(compra,aux);
    }
    destroy(inverter);   
    
    while(morto->topo!=n-1){
        pop(compra, &aux);
        
        //Aux=1
        if(aux==carta){
            i++;
            push(morto,aux);
            
            carta++;
            //printf("aux == carta %d\n",i);
        }
        else{
            i++;
            push(descarte,aux);
            //printf("aux != carta %d\n",i);
        }
        if(isEmpty(compra)==1){
            while(!isEmpty(descarte)){
                pop(descarte,&aux);
                push(compra, aux);
            }
            rodada++;
        }
    }
    printf("%d\n",rodada);
    
    destroy(compra);
    destroy(descarte);
    destroy(morto);
    return 0;
}