#include<stdio.h>
#include<stdlib.h>
#include"numero.h"
#include<assert.h>

typedef struct no no_t;
struct no{
    elem info;
    no_t *prox;
};

struct lista{
    no_t *ini, *fim;
    int tam;
};
lista_t *criar(){
    lista_t *l;
    l=(lista_t *)malloc(sizeof(lista_t));
    assert(l!=NULL);
    l->ini=NULL;
    l->fim=NULL;
    l->tam=0;
    return l;
}
void liberar(lista_t *l){
    if(l!=NULL){
        no_t *p =l->ini;
    
        while(p!=NULL){
            l->ini=p->prox;
            free(p);
            p=l->ini;
        }
    free(l);
    }
}
void inserir(lista_t *l, elem x){
    assert (l!=NULL);
    no_t *p=(no_t *)malloc(sizeof(no_t));
    p->info=x;
    p->prox=NULL;
    if(l->ini==NULL){
        l->ini=p;
        l->fim=p;
    }else{
        l->fim->prox=p;
        l->fim=p;
    }
    l->tam++;
}
int tamanho(lista_t *l){
    assert(l!=NULL);
    return(l->tam);
   
}
void imprimir(lista_t *l){
    assert(l!=NULL);
    no_t *p=l->ini;
    while(p!=NULL){
        printf("%d", p->info);
        p=p->prox;
    }
    printf("\n");
}

void inverteElementos (no_t *e, no_t *ant){
    if(e->prox!=NULL)
        inverteElementos(e->prox, e);
    e->prox = ant;
}

void inverter (lista_t *p){
    inverteElementos(p->ini, NULL);

    //Inverte inicio com fim
    no_t *aux = p->ini;
    p->ini = p->fim;
    p->fim = aux;
}



void* sum(lista_t *a,lista_t *b,int n1, int n2){
    lista_t *aux1=a,*aux2=b;
    lista_t *resultado;
    
    no_t *x1,*x2;
    int aux=0;
    resultado=criar();
    int n,m;
    int fim1=0,fim2=0;
    inverter(aux1);
    inverter(aux2);
    x1=aux1->ini;
    x2=aux2->ini;
    int resto=0;
    while(fim1==0 || fim2==0){
        n=0;
        m=0;
        if(fim1==0)n=x1->info;
        if(fim2==0)m=x2->info;
        aux=resto+n+m;
        
        if(aux/10==0){
            inserir(resultado,aux);
            resto=0;
        }
        else{
            resto=aux%10;
            aux=(aux-resto)/10;
            inserir(resultado,resto);
            resto=aux;
        }
        
        if(x1->prox!=NULL&&fim1==0){
            x1=x1->prox;
        }
        else{
            fim1=1;
        }
        if(x2->prox!=NULL&&fim2==0){
            x2=x2->prox;
        }
        else{
            
            fim2=1;
        }
    
    }
    if(resto!=0)inserir(resultado,resto);
    
    inverter(resultado);
    while(resultado->ini->info==0){
        resultado->ini=resultado->ini->prox;
    }
    imprimir(resultado);
    
}

int eql(lista_t *a,lista_t *b,int n1, int n2){
    int max1=a->tam,max2=b->tam;
    max1=(n1)*max1;
    max2=(n2)*max2;
    if(max1<max2) return 0;
    else if(max1>max2) return 0;
    no_t *fim=a->fim;
    no_t *ini=a->ini;
    no_t *a1=ini;
    no_t *b1=b->ini;
   while(1){
        if((n1)*a1->info!=(n2)*b1->info) return 0;
        if(ini==fim) break;
        a1=a1->prox;
        b1=b1->prox;
        ini=ini->prox;
    }
    return 1;
}


int sml(lista_t *a,lista_t *b,int n1, int n2){
    int max1=a->tam,max2=b->tam;
  
    max1=(n1)*max1;
    max2=(n2)*max2;
    if(max1<max2) return 1;
    else if(max1>max2) return 0;
    if(eql(a,b,n1,n2)==1)return 0;
    no_t *fim=a->fim;
    no_t *ini=a->ini;
    no_t *a1=ini;
    no_t *b1=b->ini;
    while(1){
        if((n1)*a1->info > (n2)*b1->info) return 0;
        if(ini==fim) break;
        a1=a1->prox;
        b1=b1->prox;
        ini=ini->prox;
    }
    return 1;
}
int big(lista_t *a,lista_t *b,int n1, int n2){
    int max1=a->tam,max2=b->tam;
     max1=(n1)*max1;
    max2=(n2)*max2;
    if(max1>max2) return 1;
    else if(max1<max2) return 0;
    if(eql(a,b,n1,n2)==1)return 0;
    no_t *fim=a->fim;
    no_t *ini=a->ini;
    no_t *a1=ini;
    no_t *b1=b->ini;
    while(1){
        if((n1)*a1->info < (n2)*b1->info) return 0;
        if(ini==fim) break;
        a1=a1->prox;
        b1=b1->prox;
        ini=ini->prox;
    }
    return 1;
}

lista_t* limpar(lista_t *a){
    lista_t *nova;
    nova=criar();
    liberar(a);
    return nova;    
}