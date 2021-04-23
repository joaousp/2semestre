#include<stdio.h>
#include<string.h>

void bubble(int v[], int n){
	int i=1,j,aux, sentinela=0;
    do{
		for(i=0,j=1;j<n;i++,j++){
			printf("C %d %d\n",i,j);
			if(v[i]>v[j]){
				aux = v[j];
				v[j] = v[i];
				v[i] = aux;
				printf("T %d %d\n",i,j);
                sentinela=0;
			} else {
                sentinela += 1;
            }
		}
		if(sentinela > 0)
            n = n - sentinela - 1;
        else
            n--;
	}while(n > 1);
}

void selection(int v[],int n){
	int i,j=0,aux,menor,tamanho;
	tamanho = n;
	while(n!=j){
		menor = j;
		for(i=j+1;i<tamanho;i++){
			printf("C %d %d\n",menor,i);
			if(v[menor]>v[i]){
				menor = i;
			}
		}
		if(menor!=j){
			printf("T %d %d\n",j,menor);
			aux = v[j];
			v[j] = v[menor];
			v[menor] = aux;
		}
		j++;
	}

}

void tela(int v[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",v[i]);
	}
}

int main(){
	int i,n;
	char metodo[8];
	scanf("%s",metodo);
	scanf("%d",&n);
	int v[n];
	for(i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	if((strcmp(metodo,"selecao"))==0)
		selection(v,n);
	else if((strcmp(metodo,"bolha"))==0)
		bubble(v,n);
	tela(v,n);
	return 0;
}
