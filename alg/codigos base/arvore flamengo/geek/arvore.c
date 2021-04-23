//joao paulo garcia
//11816056
//projeto 2
#include<stdio.h>
#include<stdlib.h>
#include"arvore.h"
//declaracao do no, seguindo a logica de arvore de busca
struct no{
    no_t *esq,*dir;
    elem info;
    //0 para preto 1 para vermelho
    int cor;
    //inserir o no do pai
    //no_t *pai;
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
//as 3 funcoes de balanceamento:
//quando obter 2 vermelhos, trocar as cores
void troca_cor(no_t *raiz){
    if(raiz==NULL || raiz->esq==NULL ||raiz->dir==NULL)return;
    raiz->cor=1;
    raiz->esq->cor=0;
    raiz->dir->cor=0;
}
//codigo alterado para incluir as cores
//rotacao para a esquerda
no_t *rotacao_ee(no_t *desb){
    if(desb==NULL) return NULL;
    no_t *aux=desb->dir;
    desb->dir=aux->esq;
    aux->esq=desb;
    //adicionei as cores ao codigo disbolinibilizado pelo professor
    aux->cor=desb->cor;
    desb->cor=1;
    return (aux);
}
//codigo alterado para incluir as cores
//rotacao para direita
no_t *rotacao_dd(no_t *desb){
    if(desb==NULL) return NULL;
    no_t *aux=desb->esq;
    desb->esq=aux->dir;
    aux->dir=desb;
    //adicionei as cores ao codigo disbolinibilizado pelo professor
    aux->cor=desb->cor;
    desb->cor=1;
    return (aux);
}
//funcao para buscar o pai do no atual, utilizada em sucessor e predescessor

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
//funcao que busca o elemento proximo a x
void sucessor(no_t *a, elem x){
    if(a==NULL) {
        printf("erro\n");
        return;
    }
    no_t *aux=busca(a, x);
    //apos encontrar x, encaminha em 2 possibilidades
    if(aux!=NULL&&aux->dir!=NULL){
        //possibilidade 1:
        //existe um flho a direita
        //verificar se existe um filho a esquerda
        no_t *filhos=aux->dir;
        if(filhos->esq!=NULL){
        while(1){
            if(filhos->esq!=NULL){
                filhos=filhos->esq;
            }else{
                break;
            }
            //terminar printando o neto a esquerda do filho a direita do avo
        }printf("%d\n",filhos->info);
        return;
        }
        //caso contrario, printa o filho a direita
        printf("%d\n",aux->dir->info);
        return;
        

    }
    else {
        //caso 2:
        //primeiro no nao tem filho a direita, mas possui um pai
        no_t *pai=busca_pai(a,x);
        if(pai!=NULL&&pai->info>x){ 
            //verificar se esta a direita ou a esquerda
            if(pai->dir==aux){
                //caso esteja a direita, verificar os avos a esquerda do pai ate encontrar o sucessor
                if(pai->info<x){
                no_t *avo=busca_pai(a,pai->info);
                //comparar o avo com o pai
                if(avo!=NULL){
                    while(avo!=NULL){
                        if(avo->info>x){
                            //printar o sucessor direto
                            printf("%d\n",avo->info);
                            return;
                        }
                        avo=busca_pai(a,avo->info);
                    }
                }
            }
            //caso esteja a direita e seja o sucessor direto
            //eu sei que poderia estar melhor desenvolvido, porem foi a forma que consegui realizar
            }if(pai->info>x)printf("%d\n", pai->info);
        else printf("erro\n");
        }else printf("erro\n");
    }

}
//vale o mesmo do sucessor, porem realizando o caminho inverso
void predecessor(no_t *a, elem x){
    if(a==NULL){
        printf("erro\n");
        return;
    }
    no_t *aux=busca(a, x);
    if(aux!=NULL && aux->esq!=NULL){
        //caso 1:
        //no encontrado e possui um filho a esquerda
        no_t *filhos=aux->esq;
        if(filhos->dir!=NULL){
        while(1){
            if(filhos->dir!=NULL){
                filhos=filhos->dir;
            }else{
                break;
            }
        }printf("%d\n",filhos->info);
        return;
        }
        printf("%d\n",aux->esq->info);
        return;
    }else{
        //caso 2:
        //primeiro o nao tem no a esquerda, mas é filho a direita do pai
        no_t *pai=busca_pai(a,x);
        if(pai!=NULL&&pai->info>x){
            if(pai->esq==aux){
                if(pai->info>x){
                no_t *avo=busca_pai(a,pai->info);
                while(avo!=NULL){
                    if(avo->info<x){
                        printf("%d\n",avo->info);
                        return;
                    }
                    avo=busca_pai(a,avo->info);
                }
            
            }
             }if(pai->info<x)printf("%d\n", pai->info);
        else printf("erro\n");
        }
        else printf("erro\n");
    }

}


//maximo e minimo,
//seguem procurando o filho mais a esquerda/direita da raiz

void maximo(no_t *a){
    if(a==NULL) {
        printf("erro\n");
        return;
    }
    no_t *aux=a;
    while(aux->dir!=NULL){
        aux=aux->dir;
    }
    printf("%d \n", aux->info);
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
    printf("%d \n", aux->info);
}

//finalizar libera a memoria
void finalizar(no_t *raiz){
    if(raiz!=NULL){
        finalizar(raiz->esq);
        finalizar(raiz->dir);
        free(raiz);
    }

}
//imprimir foi usado para verificar o balanceamento;
//atualmente sem uso
void imprimir(no_t *raiz){
    if(raiz!=NULL){
        printf("%d cor:%d(",raiz->info,raiz->cor);
        imprimir(raiz->esq);
        printf(",");
        imprimir(raiz->dir);
        printf(")");
    }else{
        printf("null");
    }
}
//altura nao foi utilizado
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

//funcoes de impressao usadas:
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

//a busca e a mesma da arvore binaria
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
//funcao para verificar a cor,
//por definicao, trato no nulo como preto
int color(no_t *teste){
    if(teste==NULL) return 0;
    return teste->cor;

}

//funcao de insercao de no
//semelhante a de arvore de busca
no_t *inserir_no(no_t *raiz, elem x){
    if(raiz==NULL){
        raiz=(no_t *)malloc(sizeof(no_t));
        raiz->info=x;
        raiz->esq=NULL;
        raiz->dir=NULL;
        raiz->cor=1;

    }else if(x==raiz->info){
       return raiz;
    }else if(raiz->info > x){
        raiz->esq=inserir_no(raiz->esq,x);
        
    }else if(raiz->info < x){
        raiz->dir=inserir_no(raiz->dir,x);
        
    }
    //a mudanca se encontra no balanceamento,
    //feito por meio destas 3 funcoes
    if(color(raiz->dir)&& !color(raiz->esq)) raiz=rotacao_ee(raiz);
    if(color(raiz->esq)&&color(raiz->esq->esq)) raiz=rotacao_dd(raiz);
    if(color(raiz->esq)&&color(raiz->dir)) troca_cor(raiz);
    return raiz;
}

void inserir(arvore_t *a, elem x){
    //esta é atualmente uma funcao sem proposito,
    //originalmente era usada para verificar se existia erros na implementacao,
    //poderia ser melhor otimizada se o programa nao a utilizasse
    //envia para a funcao que o coloca na arvore
    a->raiz=inserir_no(a->raiz, x);
    //altura(a->raiz);
    //printf("\n");
    //imprimir(a);
    //printf("\n");
}
