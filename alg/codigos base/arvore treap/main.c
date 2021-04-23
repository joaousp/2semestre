#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"arvore.h"

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
                    largura(arvore);
                    printf("\n");
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
    finalizar(arvore->raiz);
    return 0;
}


