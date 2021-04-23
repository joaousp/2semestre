#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"arvore.h"
struct no{
    no_t *esq,*dir;
    int fb;
    elem info;
};
arvore_t *criar(){
    arvore_t *a = (arvore_t *)malloc(sizeof(arvore_t));
    a->raiz=NULL;
    return a;
}
int esta_vazia(no_t *raiz){
    assert(raiz!=NULL);
    if(raiz==NULL){
        return 1;

    }
    return 0;
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
no_t *rotacao_ee(no_t *desb){
    no_t*aux=desb->dir;
    desb->dir=aux->esq;
    aux->esq=desb;
    return aux;
}

no_t *rotacao_dd(no_t *desb){
    no_t*aux=desb->esq;
    desb->esq=aux->dir;
    aux->dir=desb;
    return aux;
}

no_t *rotacao_ed(no_t *desb){
    desb->esq=rotacao_ee(desb->esq);
    desb=rotacao_dd(desb);
    return desb;
}

no_t *rotacao_de(no_t *desb){
    desb->dir=rotacao_dd(desb->dir);
    desb=rotacao_ee(desb);
    return desb;
}


no_t *inserir_avl(no_t *raiz,elem x,int *flag){
    if(raiz!=NULL){
        if(x<raiz->info){
            raiz->esq=inserir_avl(raiz->esq,x,flag);
            if(*flag==1){
                switch(raiz->fb){
                        case -1:
                            raiz->fb=0;
                            *flag=0;
                            break;
                        case 0:
                            raiz->fb=1;
                            *flag=1;
                            break;
                        case 1:
                            if(raiz->esq->fb==1){
                                raiz=rotacao_dd(raiz);
                                raiz->dir->fb=0;
                                raiz->fb=0;
                            }else{
                                raiz=rotacao_ed(raiz);
                                if(raiz->fb==-1){
                                    raiz->esq->fb=1;
                                    raiz->dir->fb=0;
                                    raiz->fb=0;

                                }else if(raiz->fb==1){
                                    raiz->esq->fb=0;
                                    raiz->dir->fb=-1;
                                    raiz->fb=0;
                                }else{
                                    raiz->esq->fb=0;
                                    raiz->dir->fb=0;
                                    raiz->fb=0;

                                }
                            }
                            *flag=0;
                            break;
                        }
        }else if(x>raiz->info){
            raiz->dir=inserir_avl(raiz->dir,x,flag);
            if(*flag==1){
                switch(raiz->fb){
                        case 1:
                            raiz->fb=0;
                            *flag=0;
                            break;
                        case 0:
                            raiz->fb=-1;
                            *flag=1;
                            break;
                        case -1:
                            if(raiz->dir->fb==-1){
                                raiz=rotacao_ee(raiz);
                                raiz->esq->fb=0;
                                raiz->fb=0;
                            }else{
                                raiz=rotacao_de(raiz);
                                if(raiz->fb==-1){
                                    raiz->esq->fb=1;
                                    raiz->dir->fb=0;
                                    raiz->fb=0;

                                }else if(raiz->fb==1){
                                    raiz->esq->fb=0;
                                    raiz->dir->fb=-1;
                                    raiz->fb=0;
                                }else{
                                    raiz->esq->fb=0;
                                    raiz->dir->fb=0;
                                    raiz->fb=0;

                                }
                            }
                            *flag=0;
                            break;
                        }
        }
            }
        }else{
            printf("ELEMENTO JA EXISTE!\n");
            
        }   
    }else{
        raiz=(no_t *)malloc(sizeof(no_t));
        raiz->info=x;
        raiz->esq=NULL;
        raiz->dir=NULL;
        raiz->fb=0;
        *flag=1;

    }
    return raiz;
}
void inserir(arvore_t *a, elem x){
    int flag=0;
    a->raiz=inserir_avl(a->raiz,x,&flag);
}
no_t *balanceamento_esq(no_t *p,int *h){
    printf("balanceamento para o lado esq");
    switch (p->fb){
        case 1:
            p->fb=0;
            break;
        case 0:
            p->fb=-1;
            *h=0;
            break;
        case -1:
            if(p->dir->fb<=0){
                p=rotacao_ee(p);
                if(p->fb==0){
                    p->esq->fb=-1;
                    p->fb=1;
                    *h=0;
                }else{
                    p->esq->fb=0;
                    p->fb=0;
                }
            }else{
                p=rotacao_de(p);
                if(p->fb==1){
                    p->esq->fb=0;
                    p->dir->fb=-1;
                }else if(p->fb==-1){
                    p->esq->fb=1;
                    p->dir->fb=0;
                }else{
                    p->esq->fb=0;
                    p->dir->fb=0;
                }
                p->fb=0;
            }

    }
    return p;

}no_t *balanceamento_dir(no_t *p,int *h){
    printf("balanceamento para o lado dir");
    switch (p->fb){
        case -1:
            p->fb=0;
            break;
        case 0:
            p->fb=1;
            *h=0;
            break;
        case 1:
            if(p->esq->fb>=0){
                p=rotacao_dd(p);
                if(p->fb==0){
                    p->dir->fb=1;
                    p->fb=-1;
                    *h=0;
                }else{
                    p->esq->fb=0;
                    p->fb=0;
                }
            }else{
                p=rotacao_ed(p);
                if(p->fb==1){
                    p->esq->fb=0;
                    p->dir->fb=-1;
                }else if(p->fb==-1){
                    p->esq->fb=1;
                    p->dir->fb=0;
                }else{
                    p->esq->fb=0;
                    p->dir->fb=0;
                }
                p->fb=0;
            }

    }
    return p;

}

no_t *busca_remove(no_t *p,no_t *no_chave,int *h){
    no_t *aux;
    if(p->dir!=NULL){
        p->dir=busca_remove(p->dir,no_chave,h);
        if(*h==1){
            p=balanceamento_dir(p,h);
        }
    }else{
        no_chave->info=p->info;
        aux=p;
        p=p->esq;
        free(aux);
        *h=1;
    }
    return p;   
}

no_t *remove_avl(no_t *raiz, elem x, int *h){
    no_t *aux;
    if(raiz==NULL){
        printf("chave nao foi encontrada!\n");
        *h=0;

    }else if(x<raiz->info){
        raiz->esq=remove_avl(raiz->esq, x,h);
        if(h==1){
            raiz=balanceamento_esq(raiz,h);
        }

    }else if(x>raiz->info){
        raiz->dir=remove_avl(raiz->dir,x,h);
        if(h==1){
            raiz=balanceamento_dir(raiz,h);
        }
    }
    else{
        if(raiz->dir==NULL){
            aux=raiz;
            raiz=raiz->esq;
            free(aux);
            *h=1;
        }else if(raiz->esq==NULL){
            aux=raiz;
            raiz=raiz->dir;
            //free(aux);
            *h=1;
        }else{
            raiz->esq=busca_remove(raiz->esq,raiz,h);
            if(*h==1){
                raiz=balanceamento_esq(raiz,h);
            }
        }

    }
    return raiz;
}

void remover(arvore_t *a,elem x){
    int flag=0;
    a->raiz=remove_avl(a->raiz,x,&flag);
}