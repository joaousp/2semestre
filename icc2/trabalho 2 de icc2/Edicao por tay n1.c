//atividade 2 de icc2
#include<stdio.h>
#include<stdlib.h>
//funcoes
void insertion(int v[], int n);
void merge(int v[], int c, int f);
void intercala(int v[], int c1, int f1, int c2, int f2);
//void libertar(int mat[][]);

int main(){
    //oque precisa ter:
    //uma declaracao de quantos vetores no comeco;
    int nvet, **mat, nelem,i;
    scanf("%d", &nvet);
    //depois disso, criar um vetor pra cada n
    //e a pessoa vai dizer quantos elementos tem em cada vetor;
    //da para pensar como matriz, acho q vai ser mais facil de escrever;

    //alocar a memoria
    mat= malloc(nvet*sizeof(int));
    for(i=0;i<nvet;i++){
        scanf("%d",&nelem);
        mat[i]=malloc(nelem*sizeof(int));
    }

    //liberar a memoria
    //libertar(mat);
    return 0;
}

//implementação insertion
void insertion(int v[], int n)
{
    for (int i=1; i<n; i++)
    {
        int x = v[i];
        int j = i-1;
        while (j>=0 && v[j]>x)
        {
            v[j+1]= v[j];
            j--;
        }
        v[j+1]= x;
    }
}

//iplemteção do merge
void merge(int v[], int c, int f)
{
    if (f>c)
    {
        int m = (c+f)/2;
        merge(v,c,m);
        merge(v,m+1,f);
        intercala(v,c,m,m+1,f);
    }
}

void intercala(int v[], int c1, int f1, int c2, int f2)
{
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




