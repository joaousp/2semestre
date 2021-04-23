#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int elem;
typedef struct no no_t;
typedef struct arvore{
    no_t *raiz;
}arvore_t;

arvore_t *criar();
int esta_vazia(no_t *raiz);
void finalizar(no_t *raiz);
void imprimir(no_t *raiz);
int altura(no_t *raiz);
no_t *busca(no_t *raiz, elem x);
void pre_ordem(no_t *raiz);
void em_ordem(no_t *raiz);
void pos_ordem(no_t *raiz);
void inserir(arvore_t *a,elem x );
void remover(arvore_t *a,elem x);
void inserir_t(arvore_t *a, elem x,int fb);
void deletar(arvore_t *a, elem x);

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
        printf("(%d,%d) ",raiz->info,raiz->fb);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}
void em_ordem(no_t *raiz){
     if(raiz!=NULL){
        em_ordem(raiz->esq);
        printf("(%d,%d) ",raiz->info,raiz->fb);
        em_ordem(raiz->dir);
    }

}
void pos_ordem(no_t *raiz){
     if(raiz!=NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("(%d,%d) ",raiz->info,raiz->fb);
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

no_t *inserir_no(no_t *raiz,elem x, int fb){
    if(raiz==NULL){
         raiz=(no_t *)malloc(sizeof(no_t));
        raiz->info=x;
        raiz->esq=NULL;
        raiz->dir=NULL;
        raiz->fb=fb;
    }
    if(x<raiz->info){
        raiz->esq=inserir_no(raiz->esq,x,fb);
        if(raiz->esq->fb>raiz->fb){
            raiz=rotacao_dd(raiz);
        }
    }
    else if(x>raiz->info){
        raiz->dir=inserir_no(raiz->dir,x,fb);
        if(raiz->dir->fb>raiz->fb){
            raiz=rotacao_ee(raiz);
        }
    }
    
    return raiz;

}

void inserir_t(arvore_t *a, elem x,int fb){
    no_t *aux=busca(a->raiz,x);
    if(aux==NULL)a->raiz=inserir_no(a->raiz,x,fb);
    else{
        printf("Elemento ja existente\n");
    }
}
no_t *deletar_no(no_t *raiz, elem x){
    no_t *aux;
    if(raiz==NULL) return NULL;
    else if(x<raiz->info){
        raiz->esq=deletar_no(raiz->esq,x);
    }else if(x>raiz->info){
        raiz->dir=deletar_no(raiz->dir,x);
    }else{
        if(raiz->dir==NULL){
            aux=raiz;
            raiz=raiz->esq;
            free(aux);
        }else if(raiz->esq==NULL){
            aux=raiz;
            raiz=raiz->dir;
            free(aux);
        }else{
            while(raiz->esq!=NULL ||raiz->dir!=NULL){
                raiz=rotacao_ee(raiz);
                raiz=raiz->esq;
            }
            raiz=raiz->esq;
            if(raiz->dir==NULL){
            aux=raiz;
            raiz=raiz->esq;
            free(aux);
            }else if(raiz->esq==NULL){
            aux=raiz;
            raiz=raiz->dir;
            free(aux);
            }
            
        }
    }
    
    return raiz;
}
void deletar(arvore_t *a, elem x){
    no_t *aux=busca(a->raiz,x);
    deletar_no(aux,x);
}



void inserir_pilha(no_t *raiz, no_t *original){
    no_t *aux=(no_t *)malloc(sizeof(no_t));
    aux->info=original->info;
    aux->fb=original->fb;
    aux->esq=NULL;
    aux->dir=NULL;
    raiz->esq=aux;
}

void imprimir_largura(no_t *raiz,no_t *aux[],int numero){
    if(raiz->esq!=NULL){
        inserir_pilha(aux[numero+1],raiz->esq);
        imprimir_largura(raiz->esq,aux,numero+1);
    }
    if(raiz->dir!=NULL){
        inserir_pilha(aux[numero+1],raiz->dir);
        imprimir_largura(raiz->dir,aux,numero+1);
    }
}
void largura(arvore_t *a,int m ){
    //improvisar uma pilha com a arvore
    no_t *aux[m];
    aux[0]=a->raiz;
    imprimir_largura(a->raiz,aux,0);
    int i=0;
    while(i<m){
        if(aux[i]!=NULL){
            printf("(%d,%d) ",aux[i]->info, aux[i]->fb);
            aux[i]=aux[i]->esq;
        }
        else{
            finalizar(aux[i]);
            i++;
        }
    }
    
}

int main(){
    int n;
    int pai, dir,esq;
    arvore_t *arvore;
    char ordem[10], tipo[15];
    int x,y;
    arvore=criar();
    scanf("%d",&n);
    while(n>0){
        scanf(" %s",ordem);
        if(strcmp("insercao",ordem)==0){
            scanf("%d %d", &x, &y);
            inserir_t(arvore,x,y);
        }
        if(strcmp("remocao",ordem)==0){
            scanf("%d",&x);
            deletar(arvore,x);
        }
        if(strcmp("impressao",ordem)==0){
            scanf(" %s",tipo);
            if(strcmp(tipo,"ordem")==0){
                    em_ordem(arvore->raiz);
                    printf("\n");       
            }
            else if(strcmp(tipo,"posordem")==0){
                    pos_ordem(arvore->raiz);printf("\n");
                    }
            else if(strcmp(tipo,"preordem")==0){
                    pre_ordem(arvore->raiz);
                    printf("\n");
                    }
            else if(strcmp(tipo, "largura")==0){
                    printf("ainda nao feito\n");
                    }
        }
        if(strcmp("buscar",ordem)==0){
            scanf("%d", &x);
            no_t *aux=busca(arvore->raiz,x);
            if(aux==NULL) printf("0\n");
            else printf("1\n");
        }

        n--;
    }
    return 0;
}


