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
estrutura merge(estrutura v, int c, int f);
estrutura intercala(estrutura v, int c1, int f1, int c2, int f2);
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
        inser[i].vetor = malloc(aux * sizeof(int));
        mer[i].Nelem = aux;
        mer[i].vetor = malloc(aux * sizeof(int));
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

        //chamando e imprimindo do merge
        mer[i]=merge(mer[i], 0, mer[i].Nelem - 1);
        printf("M %d %d %d\n", mer[i].Nelem, mer[i].troca, mer[i].comparacao);
    }

    for (i = 0; i < nvet; i++)
    {
        free(inser[i].vetor);
        free(mer[i].vetor);
    }
}

//função ordena pelo insertion
void insertion(estrutura v, int n)
{
    v.comparacao = 0;
    v.troca = 0;

    for (int i = 1; i < n; i++)
    {
        int x = v.vetor[i];
        int j = i - 1;
        v.troca++;
        while (j >= 0 && v.vetor[j] > x)
        {
            v.vetor[j + 1] = v.vetor[j];
            j--;
            v.troca++;
            v.comparacao++;
        }

        if ((v.vetor[j] <= x) && (j >= 0))
            v.comparacao++;

        v.vetor[j + 1] = x;
        v.troca++;
    }
    printf("I %d %d %d\n", v.Nelem, v.troca, v.comparacao);
}

//função ordena pelo merge
estrutura merge(estrutura v, int c, int f)
{

    if (f > c)
    {
        int m = (c + f) / 2;
        v= merge(v, c, m);
        v= merge(v, m + 1, f);
        v= intercala(v, c, m, m + 1, f);
    }
    
    return v;
}

estrutura intercala(estrutura v, int c1, int f1, int c2, int f2)
{
    int len = (f1 - c1 + 1) + (f2 + c2 + 1);
    int a[len];
    int i1 = c1;
    int i2 = c2;
    int k = 0;
    while (i1 <= f1 && i2 <= f2)
    {
        if (v.vetor[i1] <= v.vetor[i2])
        {
            v.comparacao++;
            a[k++] = v.vetor[i1++];
        }
        else
        {
             v.comparacao++;
            a[k++] = v.vetor[i2++];
        }
    }
    while (i1 <= f1)
    { v.comparacao++;
        a[k++] = v.vetor[i1++];
    }
    while (i2 <= f2)
    { v.troca++;

        a[k++] = v.vetor[i2++];
    }
    for (int i = c1, k = 0; i <= f2; i++, k++)
    { v.troca++;
        v.vetor[i] = a[k];
    }
    
    return v;
}
