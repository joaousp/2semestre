#include <stdio.h>
#include<stdlib.h>

void imprimir(int *a, int tam){
    int i=0;
    //printf("{");
    for(i=0;i<tam;i++){
        printf("%d ", a[i]);
    }
    //printf("\b}");
}

void selection(int *v, int tam){
    int i, j, minimo, aux;
    if(tam<=1)
        return;
    else{
        for(i=0;i<tam;i++){
            minimo=i;
            for(j=i+1;j<tam;j++){
            	printf("C %d %d\n", i, j);
                if(v[j]<v[minimo])
                    minimo=j;
            }
            if(v[i]!=v[minimo]){
                aux=v[i];
                v[i]=v[minimo];
                v[minimo]=aux;
                printf("T %d %d\n", i, minimo);
            }
        }
    }
}

int main(){
    int tam,i;
	int *vetor;
	char *modo;
	scanf("%s", modo);
//	int tam=4;
//	int vetor[]={3,6,5,2};
    scanf("%d", &tam);
    vetor=(int *)malloc(tam*sizeof(int));
    for(i=0;i<tam;i++){
        scanf("%d", &vetor[i]);
    }
    selection(vetor, tam);
    imprimir(vetor, tam);
    return 0;
}
