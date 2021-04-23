//atividade 2 de icc2
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *vetor;
    int Nelem;
    int troca;
    int comparacao;
} estrutura;


void insertion(estrutura v, int n)
{
    for (int i = 1; i < n; i++)
    {
        v.comparacao++;
        int x = v.vetor[i];
        int j = i - 1;
        while (j >= 0 && v.vetor[j] > x)
        {
            v.vetor[j + 1] = v.vetor[j];
            j--;
            v.troca++;
            v.comparacao++;
        }
        v.vetor[j + 1] = x;
    }
    printf("I %d %d %d\n", v.Nelem, v.troca, v.comparacao);

}


void intercala (int p, int q, int r, int v[]) {
   
   int *w;                                 
   w = malloc ((r-p) * sizeof (int));      
   int i = p, j = q;                       
   int k = 0;                              

   while (i < q && j < r) {                
      if (v[i] <= v[j])  w[k++] = v[i++];  
      else  w[k++] = v[j++];               
   }                                       
   while (i < q){
       w[k++] = v[i++];
       }         
   while (j < r){
      w[k++] = v[j++];
    }         
    for (i = p; i < r; ++i)  v[i] = w[i-p]; 
    free (w);                               
}
void mergesort_i (int n, int v[])
{
   int b = 1;
   while (b < n) {
      int p = 0;
      while (p + b < n) {
         int r = p + 2*b;
         if (r > n) r = n;
         intercala (p, p+b, r, v);
         p = p + 2*b; 
      }
      b = 2*b;
   }
}

int main(){
    
    //oque precisa ter:
    //uma declaracao de quantos vetores no comeco;
    int nvet, i, j, aux;
    scanf("%d", &nvet);
    estrutura inser[nvet], mer[nvet];

    //numero de vetores
    for (i = 0; i < nvet; i++)
    {
        scanf("%d", &aux);
        inser[i].Nelem = aux;
        inser[i].vetor = malloc(aux * sizeof(int));
        mer[i].Nelem = aux;
        mer[i].vetor = malloc(aux * sizeof(int));
    }
    for (i = 0; i < nvet; i++)
    {
        for (j = 0; j < inser[i].Nelem; j++)
        {
            scanf("%d", &aux);
            inser[i].vetor[j] = aux;
            mer[i].vetor[j] = aux;

                //zerando nossos contadores
                inser[i].troca = 0;
                inser[i].comparacao = 0;
                mer[i].troca = 0;
                mer[i].comparacao = 0;
        }
    }
    //onde tudo acontece
    for (i = 0; i < nvet; i++)
    {
        //chamando e imprimindo o insertion
        insertion(inser[i], inser[i].Nelem);
        //printf("I %d %d %d\n", inser[i].Nelem, inser[i].troca, inser[i].comparacao);

        //chamando e imprimindo do merge
        mergesort_i(mer[i].Nelem,mer[i].vetor);
        printf("M %d %d %d\n", mer[i].Nelem, mer[i].troca, mer[i].comparacao);
    }
    for(i=0;i<nvet;i++){
        free(inser[i].vetor);
        free(mer[i].vetor);
    }


}