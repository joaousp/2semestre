#include<stdio.h>
#include<stdlib.h>
#include"listac.h"
#include<assert.h>




int main(){
    int n, k;
    int t;
    elem f;
    int j=1;
    lista_t **l;
    scanf("%d", &t);
    l=(lista_t **)malloc(t*sizeof(lista_t*));
    while (j<=t)
    {   
        
        l[j]=criar();
        scanf("%d", &n);
        scanf("%d", &k);
        for(int i=1;i<=n;i++){
            inserir(l[j],i);
        }
      
        f=fun(l[j],k);
        
        printf("Caso %d: %d\n",j, f);       
        //liberar(l[j]);
        j++;
    }
   
    return 0;
}

