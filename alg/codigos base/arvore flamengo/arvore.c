#include<stdio.h>
#include<stdlib.h>

#include"arvore.h"
struct no{
    no_t *esq,*dir;
    elem info;
    //0 para preto 1 para vermelho
    int cor;
};
//criar a raiz
arvore_t *criar(){
    arvore_t *a = (arvore_t *)malloc(sizeof(arvore_t));
    a->raiz=NULL;
    return a;
}
int esta_vazia(no_t *raiz){
    //assert(raiz!=NULL);
    if(raiz==NULL){
        return 1;
    }
    return 0;
}

//quando obter 2 vermelhos, trocar as cores
void troca_cor(no_t *raiz){
    raiz->cor=1;
    raiz->esq->cor=0;
    raiz->dir->cor=0;
}
//codigo alterado para incluir as cores
no_t *rotacao_ee(no_t *desb){
    no_t *aux=(desb)->dir;
    (desb)->dir=(aux)->esq;
    (aux)->esq=(desb);
    (aux)->cor=(desb)->cor;
    (desb)->cor=1;
    return (aux);
}
//codigo alterado para incluir as cores
no_t *rotacao_dd(no_t *desb){
    no_t *aux=desb->esq;
    desb->esq=(aux)->dir;
    aux->dir=(desb);
    aux->cor=(desb)->cor;
    desb->cor=1;
    return (aux);
}
/*
no_t *rotacao_ed(no_t *desb){
    desb->esq=rotacao_ee(desb->esq);
    desb=rotacao_dd(desb);
    return desb;
}

no_t *rotacao_de(no_t **desb){
    (*desb)->dir=rotacao_dd(&(*desb)->dir);
    (*desb)=rotacao_ee(&(*desb));
    return (*desb);
}
*/
no_t *busca_pai(no_t *raiz, elem x){
    if(raiz==NULL) return NULL;
    if(raiz->esq!=NULL && raiz->esq->info==x)
        return raiz;
    if(raiz->dir!=NULL && raiz->dir->info==x)
        return raiz;
    no_t *p=busca_pai(raiz->esq,x);
    if(p==NULL)
        p=busca_pai(raiz->dir,x);
    return p;

}

void sucessor(no_t *a, elem x){
    if(a==NULL) {
        printf("erro\n");
        return;
    }
    no_t *aux=busca(a, x);
    if(aux!=NULL&&aux->dir!=NULL) printf("%d\n", aux->dir->info);
    else {
        //casos
        //primeiro o nao tem no a direita, mas é filho a esquerda do pai
        no_t *pai=busca_pai(a,x);
        if(pai->esq->info==x) printf("%d\n", pai->esq->info);
        else printf("erro\n");
    }
}
void predecessor(no_t *a, elem x){
    if(a==NULL){
        printf("erro\n");
        return;
    }
    no_t *aux=busca(a, x);
    if(aux->esq!=NULL) printf("%d\n", aux->esq->info);
    else{
        //casos
        //primeiro o nao tem no a esquerda, mas é filho a direita do pai
        no_t *pai=busca_pai(a,x);
        if(pai!=NULL&&pai->dir->info==x) printf("%d\n", pai->dir->info);
        else printf("erro\n");
    }
}




void maximo(no_t *a){
    if(a==NULL) {
        printf("erro\n");
        return;
    }
    no_t *aux=a;
    while(aux->dir!=NULL){
        aux=aux->dir;
    }
    printf("%d\n", aux->info);
}
void minimo(no_t *a){
    if(a==NULL) {
        printf("erro\n");
        return;
    }
    no_t *aux=a;
    while(aux->esq!=NULL){
        aux=aux->esq;
    }
    printf("%d\n", aux->info);
}

void finalizar(no_t *raiz){
    if(raiz!=NULL){
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }

}
void imprimir(no_t *raiz){
    if(raiz!=NULL){
        printf("%d(",raiz->info);
        imprimir(raiz->esq);
        printf(",");
        imprimir(raiz->dir);
        printf(")");
    }else{
        printf("null");
    }

}
int altura(no_t *raiz){
    if(raiz==NULL) return 0;
    int alt_esq=1+altura(raiz->esq);
    int alt_dir=1+altura(raiz->dir);
    if(alt_esq>alt_dir){
        return alt_esq;
    }
    if(alt_esq<alt_dir){
        return alt_dir;
    }
}
void pre_ordem(no_t *raiz){
    if(raiz!=NULL){
        printf("%d ",raiz->info);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}
void em_ordem(no_t *raiz){
     if(raiz!=NULL){
        em_ordem(raiz->esq);
        printf("%d ",raiz->info);
        em_ordem(raiz->dir);
    }

}
void pos_ordem(no_t *raiz){
     if(raiz!=NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ",raiz->info);
    }
}

no_t *busca(no_t *raiz, elem x){
  if(raiz==NULL){
      return NULL;
  }else if(raiz->info==x){
      return raiz;
  }else if(x<raiz->info){
      return busca(raiz->esq,x);
  }else{
      return busca(raiz->dir,x);
  }
}
/*
int remover(no_t **raiz, elem x){
    if((*raiz)==NULL){
        return 0;
    }else if(x<(*raiz)->info){
        return remover(&(*raiz)->esq,x);
    }else if(x>(*raiz)->info){
        return remover(&(*raiz)->dir,x);
    }else{
        if((*raiz)->esq==NULL&&(*raiz)->dir==NULL){
            free(*raiz);
            *raiz=NULL;
            return 1;
        }
        else if((*raiz)->esq==NULL){
            no_t *aux=*raiz;
            *raiz=(*raiz)->dir;
            free(aux);
            return 1;
        }
        else if((*raiz)->dir==NULL){
            no_t *aux=*raiz;
            *raiz=(*raiz)->esq;
            free(aux);
            return 1;
        }
        else{
            no_t *aux=*raiz;
            while((aux->dir!=NULL)){
                aux=aux->dir;
            }
            (*raiz)->info=aux->info;
            return remover(&(*raiz)->esq,aux->info);
        }
    }
}
*/

int color(no_t **raiz){
    //segundo o tutorial é bom definir como preto nos nulos
    if(*raiz==NULL) return 0;

    return (*raiz)->cor;
}



int inserir(no_t **raiz, elem x){
    if(*raiz==NULL){
        *raiz=(no_t *)malloc(sizeof(no_t));
        (*raiz)->info=x;
        (*raiz)->esq=NULL;
        (*raiz)->dir=NULL;
        (*raiz)->cor=1;
        
    }else if(x==(*raiz)->info){
       return 0;
    }else if(x<(*raiz)->info){
        return inserir( &(*raiz)->esq,x);
    }else{
        return inserir( &(*raiz)->dir,x);
    }
    //balanceamento
    if(color(&(*raiz)->dir) && !color(&(*raiz)->esq)) (*raiz)=rotacao_ee((*raiz));
    if(color(&(*raiz)->esq) && color(&(*raiz)->esq->esq)) (*raiz)=rotacao_dd((*raiz));
    if(color(&(*raiz)->dir) && color(&(*raiz)->esq)) troca_cor((*raiz));
    return 1;
}
