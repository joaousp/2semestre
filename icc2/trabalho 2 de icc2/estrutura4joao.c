//atividade 2 de icc2

#include <stdio.h>
#include <stdlib.h>
//estrutura que iremos usar
typedef struct
{
    int *vetor;
    int Nelem;
    int troca;
    int comparacao;
} estrutura;
//funcoes que iremos usar.
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
    //zerando os contadores por precaução
    v.comparacao = 0;
    v.troca = 0;

    for (int i = 1; i < n; i++)
    {
        int x = v.vetor[i];
        int j = i - 1;
        //primeira troca
        v.troca++;
        while (j >= 0 && v.vetor[j] > x)
        {
            v.vetor[j + 1] = v.vetor[j];
            j--;
            //troca e comparacao
            v.troca++;
            v.comparacao++;
        }

        if ((v.vetor[j] <= x) && (j >= 0)){
            //verificacao para comparacao
            v.comparacao++;
            }

        v.vetor[j + 1] = x;
        //ultima troca do ciclo
        v.troca++;
    }
    //como o insertion é uma funcao simples, achamos mais facil printar dentro
    printf("I %d %d %d\n", v.Nelem, v.troca, v.comparacao);
}

//função ordena pelo merge
//como merge é uma funcao recursiva, achamos mais facil fazer ela retornar a estrutura ao invez de implementar um ponteiro
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
            //nesse laço ocorre troca e comparacao
            v.comparacao++;
            a[k++] = v.vetor[i1++];
            v.troca++;
        }
        else
        {   
            //mesma coisa do de cima
            v.comparacao++;
            a[k++] = v.vetor[i2++];
            v.troca++;
        }
    }
    while (i1 <= f1)
    {   //nesse laço, so ocorrem trocas
        v.troca++;
        a[k++] = v.vetor[i1++];
    }
    while (i2 <= f2)
    {   //nesse laco, so trocas
        v.troca++;
        a[k++] = v.vetor[i2++];
    }
    for (int i = c1, k = 0; i <= f2; i++, k++)
    {   //ocorrem trocas entre o vetor auxiliar e o real
        v.troca++;
        v.vetor[i] = a[k];
    }
    //retorna o vetor real
    return v;
}
