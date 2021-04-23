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

void insertion(estrutura v, int n);
void merge(estrutura v, int c, int f);
void intercala(estrutura v, int c1, int f1, int c2, int f2);
int main()
{
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
        inser[i].vetor = malloc(aux*sizeof(int));
        mer[i].Nelem = aux;
        mer[i].vetor = calloc(aux,sizeof(int));
    }

    //copiando para um auxiliar
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
        printf("I %d %d %d\n", inser[i].Nelem, inser[i].troca, inser[i].comparacao);

        //chamando e imprimindo do merge
        merge(mer[i], 0, (mer[i].Nelem -1));
        printf("M %d %d %d\n", mer[i].Nelem, mer[i].troca, mer[i].comparacao);
    }
    for(i=0;i<nvet;i++){
        for(j=0;j<inser[i].Nelem;j++){
            printf("%d", inser[i].vetor[j]);
        }printf("\n");
    }
    
    for(i=0;i<nvet;i++){
        for(j=0;j<mer[i].Nelem;j++){
            printf("%d", mer[i].vetor[j]);
        }printf("\n");
    }
    for(i=0;i<nvet;i++){
        free(inser[i].vetor);
        free(mer[i].vetor);
    }

}

//função ordena pelo insertion
void insertion(estrutura v, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = v.vetor[i];
        int j = i - 1;
        while (j >= 0 && v.vetor[j] > x)
        {
            v.vetor[j + 1] = v.vetor[j];
            j--;
            v.troca++;
        }
        v.vetor[j + 1] = x;
        v.comparacao++;
    }
}

//função ordena pelo merge
void merge(estrutura v, int c, int f)
{  
    if (f - c + 1 <= 1){}
    else
    {
        int m = (c + f) / 2;
        merge(v, c, m);
        merge(v, m + 1, f);
        intercala(v, c, m, m + 1, f);
    }
    
}

void intercala(estrutura v, int c1, int f1, int c2, int f2)
{
    int len = (f1 - c1 + 1) + (f2 - c2 + 1);
    int a[len];
    int i1 = c1;
    int i2 = c2;
    int k = 0;
    while (i1 <= f1 && i2 <= f2)
    {
        if (v.vetor[i1] <= v.vetor[i2])
        {

            a[k++] = v.vetor[i1++];
        }
        else
        {

            a[k++] = v.vetor[i2++];
        }
    }
    while (i2 <= f2)
    {
        a[k++] = v.vetor[i2++];
    }
    for (int i = c1, k = 0; i <= f2; i++, k++)
    {
        v.vetor[i] = a[k];
    }
}
