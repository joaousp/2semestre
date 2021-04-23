#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "fila.h"



int main() {
    
    int i,n;
    char entrada[10], nome[20];
    int idade, agravante;
    fila_t *idoso_agravante;
    fila_t *agravantes;
    fila_t *idoso;
    fila_t *padrao;
    elem x;
    idoso_agravante=criar();
    agravantes=criar();
    idoso=criar();
    padrao=criar();
    scanf("%d", &n);
    while(n>=1){
        fflush(stdin);
        scanf("%s", entrada);
        if(strcmp(entrada,"SAI")==0){
            //printf("%d", isEmpty(idoso_agravante));
            if(isEmpty(idoso_agravante)==0){
                remover(idoso_agravante, &agravante, &idade, nome);
                printf("%s %d %d", nome, idade, agravante);
                //tirar desse
                printf("\n");
            }
            else if(!isEmpty(agravantes)){
                remover(agravantes, &agravante, &idade, nome);
                printf("%s %d %d", nome, idade, agravante);
                //tirar desse
                printf("\n");
            }else if(!isEmpty(idoso)){
                remover(idoso, &agravante, &idade, nome);
                printf("%s %d %d", nome, idade, agravante);
                //tirar desse
                printf("\n");
            }else if(!isEmpty(padrao)) {
                remover(padrao, &agravante, &idade, nome);
                printf("%s %d %d", nome, idade, agravante);
                //tirar desse
                printf("\n");
            }else{
                printf("FILA VAZIA");
                printf("\n");
            }
            
        }else if(strcmp(entrada,"ENTRA")==0){
            fflush(stdin);
            scanf("%s", nome);
            fflush(stdin);
            scanf("%d", &idade);
            scanf("%d", &agravante);
            //printf("%s %d %d", nome, idade, agravante);
            if(idade>=60&&agravante==1){
                //printf("%s %d %d", nome, idade, agravante);
                inserir(idoso_agravante,agravante, idade, nome);
                //por no agravante e idoso
            }else if(agravante==1){
                //printf("%s %d %d", nome, idade, agravante);
                inserir(agravantes,agravante, idade, nome);
                //por no agravante 
            }else if(idade>=60){
                //printf("%s %d %d", nome, idade, agravante);
                inserir(idoso,agravante, idade, nome);
                //por no idoso
            }else{
                //printf("%s %d %d", nome, idade, agravante);
                inserir(padrao,agravante, idade, nome);
                //por no padrao
            }
        }
       

        n--;
    }
    destruir(idoso_agravante);
    destruir(agravantes);
    destruir(idoso);
    destruir(padrao);
    return 0;
}