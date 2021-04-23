//atividade 2 de icc2
#include<stdio.h>
#include<stdlib.h>
//funcoes
void insertion(int v[], int n, int *trocas, int *comparacao);
void merge(int v[], int c, int f, int *trocas, int *comparacao);
void intercala(int v[], int c1, int f1, int c2, int f2, int *trocas, int *comparacao);

int main(){
    //oque precisa ter:
    //uma declaracao de quantos vetores no comeco;
    int nvet, **mat, *nelem,i,j,*trocas,*comparacao;
    scanf("%d", &nvet);
    //depois disso, criar um vetor pra cada n
    //e a pessoa vai dizer quantos elementos tem em cada vetor;
    //da para pensar como matriz, acho q vai ser mais facil de escrever;

    //alocar a memoria
    mat= (int **)malloc(nvet*sizeof(int));
    nelem=(int *)malloc(nvet*sizeof(int));
    for(i=0;i<nvet;i++){
        scanf("%d",&nelem[i]);
        mat[i]=(int *)malloc(nelem[i]*sizeof(int));
    }
    for(i=0;i<nvet;i++){
        for(j=0;j<nelem[i];j++){
            scanf("%d",&mat[i][j]);
        }
    }
    for(i=0;i<nvet;i++){
        insertion(mat[i],nelem[i],trocas,comparacao);
        printf("I %d %d %d\n", nelem[i], *trocas, *comparacao );
        merge(mat[i],mat[i][0],mat[i][nelem[i]-1],trocas,comparacao);
        printf("M %d %d %d\n", nelem[i], *trocas, *comparacao );

    }

    for(i=0;i<nvet;i++){
        free(mat[i]);
    }
    free(mat);
    return 0;
}

//implementação insertion
void insertion(int v[], int n, int *trocas, int *comparacao)
{
    comparacao=0;
    trocas=0;
    for (int i=1; i<n; i++)
    {
        int x = v[i];
        int j = i-1;
        while (j>=0 && v[j]>x)
        {
            v[j+1]= v[j];
            j--;
            trocas++;
        }
        v[j+1]= x;
        comparacao++;
    }
}

//iplemteção do merge
void merge(int v[], int c, int f, int *trocas, int *comparacao)
{
    if (f>c)
    {
        int m = (c+f)/2;
        merge(v,c,m,trocas,comparacao);
        merge(v,m+1,f,trocas,comparacao);
        intercala(v,c,m,m+1,f,trocas, comparacao);
    }
}

void intercala(int v[], int c1, int f1, int c2, int f2, int *trocas, int *comparacao)
{   
    trocas=0;
    comparacao=0;
   int len = (f1-c1+1)+(f2+c2+1);
   int a[len];
   int i1 =c1;
   int i2=c2;
   int k=0;
   while(i1<=f1&& i2<= f2)
   {
       if (v[i1]<=v[i2])
       {    
         
           a[k++]=v[i1++];
       } else {
          
           a[k++]=v[i2++];
       }
   } 
   while(i2<=f2)
   {
       a[k++]= v[i2++];
   }
   for(int i=c1, k=0; i<=f2; i++, k++)
   {
       v[i]=a[k];
   }
}




