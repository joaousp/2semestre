#include<stdio.h>
#include<stdlib.h>
#include "biblioteca.h"
#include <assert.h>

struct no{
    int info;
    no_t *proximo,*anterior;
    int tempo;
    no_t *back;
};

struct lista{
    no_t *inicio ;
    no_t *fim ;
};
lista_t *cria(){
    lista_t *l;
    l=(lista_t *)malloc(sizeof(lista_t));
    assert(l!=NULL);
    l->fim=NULL;
    l->inicio=NULL;
    return l;
}

void inserir(lista_t *p, int n,int j,int tempo){
    no_t *aux=(no_t *)malloc(sizeof(no_t));
    aux->info=n;
    aux->tempo=tempo;
    aux->proximo=NULL;
    aux->anterior=NULL;
    aux->back=NULL;
    if(j>0){
        no_t *b=(no_t *)malloc(sizeof(no_t));
        b=p->fim;
        while(j>1){
            b=b->anterior;
            j--;
        }
        aux->back=b;
    }
    if(p->inicio==NULL){
        p->inicio=aux;
        p->fim=aux;
    }
    else{
        p->fim->proximo=aux;
        aux->anterior=p->fim;
        p->fim=aux;
    }
}

void imprimir_posicao_back(lista_t *p, no_t *back){
    no_t *atual=p->inicio;
    int contador=0;
    while(atual!=NULL){
        if(back==atual) break;
        contador++;
        atual=atual->proximo;
    }
    printf("%d] ", contador);
}

void imprimir(lista_t *p){
    no_t *q=p->inicio;
    if(p->inicio==NULL){
        printf("-1");
        return;
    }
    while(q!=NULL){
        printf("[");
        if(q->back==NULL){
            printf("%d,%d] ",q->info,q->tempo);
        }
        else{
            printf("%d,%d,",q->info,q->tempo);
            imprimir_posicao_back(p,q->back);
        }
        q=q->proximo;
    }

 
}

void retirar(lista_t *p, int n){
    no_t *aux,*atual;
    if(p->inicio==NULL){
        return;

    }
    atual=p->inicio;
    if(p->inicio->info==n){
        p->inicio=p->inicio->proximo;
    }
    no_t *b;
    b=p->inicio;
    while(atual!=NULL && atual->info!=n){
        atual=atual->proximo;
        if(atual==NULL){
            return;
        }
        else{
            while(b!=p->fim){
                if(b->back->info==n){
                    b->back=NULL;
                    free(b->back);
                }
                b=b->proximo;
            }
            aux=atual;
            if(atual->anterior!=NULL){
                aux->anterior->proximo=atual->proximo;
            }
            if(atual->proximo!=NULL){
                atual->proximo->anterior=atual->anterior;
            }
            free(aux);
        }

    }
}

void remove_inicio(lista_t *l){
    if(l==NULL)
        return;
    lista_t *q=l;
    no_t *aux=l->inicio;
    while(1){
        if(aux==NULL) break;
        if(aux->back==l->inicio){
            aux->back=NULL;
        }
        aux=aux->proximo;
    }
    l->fim=q->inicio->proximo;
    if(q->inicio->proximo!=NULL){
        q->inicio->proximo->anterior=NULL;}
    free(aux);
     

}

void remove_lista_final(lista_t *l){
    if(l==NULL) return;
    no_t *fim=l->fim;
    l->fim=l->fim->anterior;
    fim->anterior->proximo=NULL;
    fim->anterior=NULL;
    free(fim);
}

void remove_elemento(lista_t *l, int n){
    if(l==NULL) return;
    no_t *no=l->inicio,*back=l->inicio;
    while(no!=NULL&&no->info!=n){
        no=no->proximo;
    }
    while(back!=NULL){
        if(back->back==no)back->back=NULL;
        back=back->proximo;
    }
    if(no==NULL){
        return;
    }
    if(no->anterior==NULL) l->inicio=l->inicio->proximo;
    else no->anterior->proximo=no->proximo;
    if(no->proximo!=NULL){
        no->proximo->anterior=no->anterior;
    }
    free(no);
    return;
}
