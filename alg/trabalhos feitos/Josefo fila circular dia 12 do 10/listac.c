#include<stdio.h>
#include<stdlib.h>
#include"listac.h"
#include<assert.h>

typedef struct no no_t;
struct no{
    elem info;
    no_t *prox;
    no_t *ant;
};

struct lista{
    no_t *sent;
    int tam;
    int tempo;
};
lista_t *criar(){
    lista_t *l;
    l=(lista_t *)malloc(sizeof(lista_t));
    assert(l!=NULL);
    l->sent=NULL;
    l->tam=0;
    l->tempo=0;
    return l;
}
void liberar(lista_t *l){
    if(l!=NULL){
        no_t *p;
    
        if(l->sent==NULL){
            free(l);
            return ;
        }
    p = l->sent->prox;
    no_t *aux;
    while (p!=l->sent)
    {
        aux=p;
        p=p->prox;
        free(aux);
        /* code */
    }
    free(l->sent);
    free(l);
    }
}
void inserir(lista_t *l, elem x,int j){
    assert (l!=NULL);
    if(busca(l,x)==1){
        return ;
    }
    no_t *p=(no_t *)malloc(sizeof(no_t));
    p->info=x;
    if(l->sent==NULL){
        p->prox=p;
    }else{
        p->prox=l->sent->prox;
        l->sent->prox=p;
    }
    if(j==0) p->ant=NULL;
    else{
        while(j!=0){
        p=p->ant;
        j--;
        }
    }
    l->sent=p;
    l->tam++;
    l->tempo++;
    free(p);
    return ;
}
int tamanho(lista_t *l){
    if(l!=NULL)
    return(l->tam);
    return -1;
}
void imprimir(lista_t *l){
    assert(l!=NULL);
    no_t *p;
    if(l->sent==NULL){
        return ;
    }
    p=l->sent->prox;
    do{
        printf("%d ", p->info);
        p=p->prox;
    }while(p!=l->sent->prox);
    printf("\n");
}
int busca(lista_t *l, elem x){
    assert(l!=NULL);
    no_t *p;
    if(l->sent==NULL){
        return 0;
    }
    p=l->sent;
    do{
        if(p->info ==x){
            return 1;
        }
        p=p->prox;
    }while(p!=l->sent);
    return 0;
}/*
int remover(lista_t *l, elem x){
    assert (l!=NULL);
    no_t *atual, *aux;
    aux=l->sent;
    if(l->sent==NULL){
        return 0;
    }
    if((l->sent->info==x)){
        l->sent=l->sent->prox;
        free(aux);
        free(atual);
        return 1;
    }
    do{
        atual=aux;
        aux=aux->prox;
        if(aux&&aux->info==x){
            atual->prox=aux->prox;
            l->sent=atual;
            free(aux);
            return 1;
        }
    }while(atual!=l->sent->prox);
    return 0;
}*/
int remover(lista_t *l, elem x){
    assert (l!=NULL);
    no_t *atual, *aux;
    if(l->sent==NULL){
        return 0;
    }
    aux=l->sent;
    atual=l->sent->prox;
    //imprimir(l);
    do{
        if(x==atual->info){
            aux->prox=atual->prox;
            if(atual==l->sent){
                l->sent==aux;
                //printf("atual ");
              //  imprimir(l);
            }
            if(atual==aux){
                l->sent=NULL;
                //printf("aux ");
                //imprimir(l);
            }
            l->tam--;
            l->tempo++;
            free(atual);
            return 1;
        }
        aux=atual;
        atual=atual->prox;
        
    }while(atual!=l->sent->prox);
   // imprimir(l);
    return 0;
}
elem fun(lista_t *l, int k){
    assert (l!=NULL);
    assert(l->sent!=NULL);
    int i;
    while(tamanho(l)>1){
    for(i=0;i<k;i++){
        l->sent=l->sent->prox;
        }
  
    remover(l,l->sent->info);
    }
     
    //remover(l,l->sent->info);
  
    //printf("%d",l->sent->info);
    return l->sent->prox->info;
}