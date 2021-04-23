#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"arvore.h"


//estrutura da arvore, adaptada de arvore binaria de busca e max heap
struct no{
    no_t *esq,*dir;
    //adaptei o fator de balanceamento para ser a prioridade
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
//formas de impressao pedidas no trabalho
void pre_ordem(no_t *raiz){
    if(raiz!=NULL){
        printf("(%d, %d) ",raiz->info,raiz->fb);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}
void em_ordem(no_t *raiz){
     if(raiz!=NULL){
        em_ordem(raiz->esq);
        printf("(%d, %d) ",raiz->info,raiz->fb);
        em_ordem(raiz->dir);
    }

}
void pos_ordem(no_t *raiz){
     if(raiz!=NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("(%d, %d) ",raiz->info,raiz->fb);
    }
}
//funcao de busca, retorna o no pedido
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
//funcao de rotacao, é a unica utilizada no trabalho junto da DD
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
//inserir no
//baseada na arvore binaria de busca
//atraves da recursao garante que consegue fazer os balanceamentos de max heap
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
        //parte do balanceamento, compara a raiz com o no filho e os faz a rotacao se for preciso
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
//fila usada para a funcao largura
//emprestada e adaptada do codigo do professor manzato
typedef struct fila{
    int inicio, fim, total;
    //estou utilizando um vetor de nó, pois tenho uma nocao da quantidade maxima de valores no trabalho
    //porem, poderia adaptar o programa para mallocar a quantidade nescessaria
    no_t *no[100];
}fila_t;

int inserir_fila(fila_t *f, no_t *raiz){
    f->no[f->fim]=raiz;
    f->fim=(f->fim +1);
    f->total++;
    return 1;
}

int isEmpty(fila_t *f){
    
    if(f->total ==0){
        return 1;
    }
    return 0;
}

void destruir_fila(fila_t *f){
    if(f!=NULL){
        free(f);
    }
}

no_t * remover_fila(fila_t *f){
    
    if(isEmpty(f)==1)return 0;
    no_t *x;
    x=f->no[f->inicio];
    f->inicio=(f->inicio+1);
    f->total--;
    return x;
}

void largura(arvore_t *a ){
    fila_t *f;
    no_t *aux;
    f = (fila_t *)malloc(sizeof(fila_t));
    f->total=0;
    f->inicio=0;
    f->fim=0;
    f->no[0]=NULL;
    if(a->raiz!=NULL)inserir_fila(f,a->raiz);
    else return;
    while(!isEmpty(f)){
        aux=remover_fila(f);
        printf("(%d, %d) ", aux->info, aux->fb);
        if(aux->esq!=NULL){
            inserir_fila(f,aux->esq);
        }
        if(aux->dir!=NULL){
            inserir_fila(f,aux->dir);
        }
    }
    destruir_fila(f);

}

//funcao de insercao
//faz a busca antes para verificar se o no ja existe
void inserir_t(arvore_t *a, elem x,int fb){
    no_t *aux=busca(a->raiz,x);
    if(aux==NULL)a->raiz=inserir_no(a->raiz,x,fb);
    else{
        printf("Elemento ja existente\n");
    }
}
//deletar o no
//segundo as regras do trabalho, após encontrar o no
//segue fazendo rotacoes a esquerda ate ele se tornar uma folha ou
//uma semifolha
no_t *deletar_no(no_t *raiz, elem x, int *i){
    no_t *aux;
    if(raiz==NULL) return raiz;
    else if(x<raiz->info){
        raiz->esq=deletar_no(raiz->esq,x,i);
    }else if(x>raiz->info){
        raiz->dir=deletar_no(raiz->dir,x,i);
    }else{
        if(raiz->dir==NULL){
            aux=raiz;
            raiz=raiz->esq;
            free(aux);
            *i=1;
        }else if(raiz->esq==NULL){
            aux=raiz;
            raiz=raiz->dir;
            free(aux);
            *i=1;
        }else{
           raiz=rotacao_ee(raiz);
           raiz->esq=deletar_no(raiz->esq,x,i);
           *i=1;
        }
    }
    return raiz;
}
//base da funcao deletar, fiz um pouco diferente da insercao
//porem tbm poderia ter procurado
void deletar(arvore_t *a, elem x){
    int i=0;
    a->raiz=deletar_no(a->raiz,x,&i);
    if(i==0)printf("Chave nao localizada\n");
}
