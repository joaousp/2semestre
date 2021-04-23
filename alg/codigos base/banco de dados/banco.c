#include<stdio.h>
#include<stdlib.h>
#include "banco.h"

struct no{
    elem info;
    int prox;
};
typedef struct no no_t;
struct banco{
    no_t v[TAM];
    int inicio,fim,pvazio;
};
int obter_no(banco_t *b){
    if(b->pvazio==-1){
        return-1;
    }
    else{
        int pos=b->pvazio;
        b->pvazio=b->v[pos].prox;
        b->v[pos].prox=-1;
        return pos;
    }

}
void liberar_no(banco_t *b, int pos){
    b->v[pos].prox=b->pvazio;
    b->pvazio=pos;
}
banco_t *criar(){
    banco_t *b =(banco_t*)malloc(sizeof(banco_t));
    assert(b!=NULL);
    int i;
    for( i=0;i<(TAM-1);i++){
        b->v[i].prox=i+1;
    }
    b->v[TAM-1].prox=-1;
    b->pvazio=0;
    b->inicio=-1;
    b->fim=-1;
    return b;
}
int vazio(banco_t *b){
assert(b!=NULL);
return b->inicio==-1;

}
int cheio(banco_t *b){
assert(b!=NULL);
return b->pvazio==-1;
}
int inserir(banco_t *b,elem x){
    int pos=obter_no(b);
    if(pos==-1){
        return 0;
    }
    b->v[pos].info=x;
    b->v[b->fim].prox=pos;
    b->fim=pos;
    if(b->inicio==-1){
        b->inicio=pos;
    }
    return 1;
}
int remover(banco_t *b,elem *x){
    assert(b!=NULL);
    if (b->inicio==-1){
        return 0;
    }
    *x=b->v[b->inicio].info;
    int pos=b->inicio;
    b->inicio=b->v[pos].prox;
    liberar_no(b,pos);
    return 1;
}
void liberar(banco_t *b){
    free(b);
}