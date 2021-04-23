#include<stdio.h>
#include<stdlib.h>

#include"geek.h"
struct no{
    no_t *esq,*dir;
    elem info;
    //0 para preto 1 para vermelho
    int cor;
    
    //inserir o no do pai
    no_t *pai;
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
//codigo alterado para incluir as cores e o pai
no_t *rotacao_ee(no_t *desb){
    no_t *aux=(desb)->dir;
    (desb)->dir=(aux)->esq;
    (aux)->esq=(desb);
    (aux)->cor=(desb)->cor;
    (desb)->cor=1;
    return (aux);
}
//codigo alterado para incluir as cores e o pai
no_t *rotacao_dd(no_t *desb){
    no_t *aux=desb->esq;
    desb->esq=(aux)->dir;
    aux->dir=(desb);
    aux->cor=(desb)->cor;
    desb->cor=1;
    return (aux);
}
void rotacaodireita(no_t *desb, arvore_t *a){
    no_t *left=desb->esq;
    desb->esq=left->dir;
    if(desb->esq){
        desb->esq->pai=desb;
    }
    left->pai=desb->pai;
    if(!desb->pai){
        a->raiz=left;
    }else if(desb==desb->pai->esq){
        desb->pai->esq=left;
    }else{
        desb->pai->dir=left;
    }
    left->dir=desb;
    desb->pai=left;
}
void rotacaoesquerda(no_t *desb, arvore_t *a){
    no_t *right=desb->dir;
    desb->dir=right->dir;
    if(desb->dir){
        desb->dir->pai=desb;
    }
    right->pai=desb->pai;
    if(!desb->pai){
        a->raiz=right;
    }else if(desb==desb->pai->esq){
        desb->pai->esq=right;
    }else{
        desb->pai->dir=right;
    }
    right->esq=desb;
    desb->pai=right;
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
        if(aux->pai!=NULL&&aux->pai->info>x) printf("%d\n", aux->pai->info);
        else printf("erro\n");
    }
}
void predecessor(no_t *a, elem x){
    if(a==NULL){
        printf("erro\n");
        return;
    }
    no_t *aux=busca(a, x);
    if(aux!=NULL && aux->esq!=NULL) printf("%d\n", aux->esq->info);
    else{
        //casos
        //primeiro o nao tem no a esquerda, mas é filho a direita do pai
        if(aux->pai!=NULL&&aux->pai->info<x) printf("%d\n", aux->pai->info);
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


no_t *inserir_no(no_t *raiz, no_t *novo){
    //se a raiz for nula, inserir e retornar
    if(raiz==NULL)return novo;

    //caso contrario vou descendo a arvore
    if(raiz->info > novo->info){
        raiz->esq=inserir_no(raiz->esq,novo);
    }else if(raiz->info < novo->info){
        raiz->dir=inserir_no(raiz->dir,novo);
    }
    //apos feita as operacoes, retornar a raiz
    return raiz;
}
//apos feita a insercao, fazer o balanceamento
/*
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
*/

//funcao para corrigir os erros
void corrigir(arvore_t *a, no_t *raiz){
    //deixei em ingles pois ja utilizo no nó pai em portugues
    no_t *father=NULL;
    no_t *gfather=NULL;

    while((raiz!=a->raiz)&& (raiz->cor!=0)&&(raiz->pai->cor==1)){
        father=raiz->pai;
        gfather=raiz->pai->pai;

        //analisando casos
        //caso 1: o pai de raiz é o esquerdo do avo da raiz;
        if(father==gfather->esq){
            //incluir o tio
            no_t *uncle=gfather->dir;

            //caso 1.1:
            //o tio tbm é vermelho
            //resolucao, trocar as cores
            if(uncle!=NULL && uncle->cor ==1){
                gfather->cor=1;
                father->cor=0;
                uncle->cor=0;
                raiz=gfather;
                //mudanca de cor, ensinado na aula
            }
            else{
                //caso 1.2:
                //o pai é a crianca direita
                //resolucao rotacao para esquerda
                if(father->dir==raiz){
                    rotacaoesquerda(father,a);
                    raiz=father;
                    father=raiz->pai;
                }
                //caso 1.3:
                //raiz é a crianca esquerda do pai
                //resolucao rotacao para direita
                rotacaodireita(gfather,a);
                //salva a cor do pai
                int c=father->cor;
                father->cor=gfather->cor;
                gfather->cor=c;
                raiz=father;
            }
        }
        //fim do caso 1
        //caso 2:
        //o pai da raiz é a crianca a direta da raiz
        else{
            no_t *uncle=gfather->esq;
            //caso 2.1:
            //o tio de raiz tbm é vermelho
            //resolucao mudanca de cor
            if(uncle!=NULL && uncle->cor ==1){
                gfather->cor=1;
                father->cor=0;
                uncle->cor=0;
                raiz=gfather;
            }
            else{
                //caso 2.2:
                //raiz é o filho a esquerda do pai
                //resolucao rotacao a direita
                if(raiz==father->esq){
                    rotacaodireita(father,a);
                    raiz=father;
                    father=raiz->pai;
                }
                //caso 2.3:
                //raiz é a crianca a direita do pai
                //resolucao rotacao a esq
                rotacaoesquerda(gfather,a);
                int c=father->cor;
                father->cor=gfather->cor;
                gfather->cor=c;
                raiz=father;
            }
        }
    }
    a->raiz->cor=0;
}
void inserir(arvore_t *a, elem x){
    no_t *novo=(no_t *)malloc(sizeof(no_t));
    //no novo é inserido com vermelho
    novo->cor=1;
    novo->info=x;
    novo->esq=NULL;
    novo->dir=NULL;
    novo->pai=NULL;
    //no novo criado, envia para a funcao que o coloca na arvore
    a->raiz=inserir_no(a->raiz, novo);
    //feita a insercao, hora do balanceamento
    corrigir(a, a->raiz);
}