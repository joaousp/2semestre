#include<stdio.h>
#include<stdlib.h>

int **aloca(int m);
void libera(int **v,int m);
void inserir(int **v,int aux, int resto,int m);
void remover(int **v,int aux, int resto,int m);
void busca(int **v,int aux, int resto,int m);

int main(){
    //n,d,b
    int m,n,d,b;
    int i;
    int aux;
    int resto;
    int **v;
    //lendo n
    scanf("%d",&m);

    //por matrix
    v=aloca(m);
    scanf("%d", &n);
    for (i=0;i<n;i++){
        scanf("%d", &aux);
        resto=aux%m;
        inserir(v,aux,resto, m);
    }

    scanf("%d", &d);
    for (i=0;i<d;i++){
        scanf("%d", &aux);
        resto=aux%n;
        remover(v,aux,resto, m);
    }
    scanf("%d", &b);
    for (i=0;i<d;i++){
        scanf("%d", &aux);
        resto=aux%n;
        busca(v,aux,resto, m);
    }
    libera(v,m);
    return 0;
}

 
int **aloca(int m){
  int **M;
  int i;
 
  M = (int **)malloc(sizeof(int *)*m);
  if(M == NULL){
    printf("Memoria insuficiente.\n");
    exit(1);
  }
  for(i = 0; i < m; i++){
    M[i] = (int *)malloc(sizeof(int)*m);
    if(M[i] == NULL){
      printf("Memoria insuficiente.\n");
      exit(1);
    }
  }
  return M;
}

void libera(int **v, int m){
  int i;
  for(i = 0; i < m; i++)
    free(v[i]);
  free(v);
}

void inserir(int **v,int aux, int resto,int m){
    if(v[0][resto]==NULL){
        v[0][resto]=aux;
        return;
    }else{
        int i=0;
        while(i<m){
            if(v[i][resto]==NULL){
                v[i][resto]=aux;
                return;
            }
            i++;
        }
        printf("colocar mais memoria\n");
        return;
    }
}

void remover(int **v,int aux, int resto,int m){
    int j;
    if(v[0][resto]==aux){
        v[0][resto]=NULL;
        j=0;
        while(j<m&&v[j+1][resto]!=NULL){
            v[j][resto]=v[j+1][resto];
            j++;
        }
        //puxar
        return;
    }else{
        int i=0;
        while(i<m&&v[i][resto]!=NULL){
            if(v[i][resto]==aux){
                v[i][resto]=NULL;
                //puxar
                j=i;
                while(j<m && v[j+1][resto]!=NULL){
                    v[j][resto]=v[j+1][resto];
                    j++;
                }
                return;
            }
            i++;
        }
        printf("Nao existe\n");
        return;
    }
}
void busca(int **v,int aux, int resto,int m){
    if(v[0][resto]==aux){
        printf("%d ",resto);
        return;
    }else{
        int i=0;
        while(i<m&&v[i][resto]!=NULL){
            if(v[i][resto]==aux){
                printf("%d ",resto);
                return;
            }
            i++;
        }
        printf("-1 ");
        return;
    }
}
