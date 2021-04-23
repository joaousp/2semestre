#include<stdio.h>
#include<stdlib.h>
int quicksort(int v[], int c, int f,int contador);
int shell(int v[], int n);

int main(){
    int n,*m, *copia, *copia2;
    scanf("%d", &n);
    
    int i, j;
    int contadors, contadorq;
    m=(int *)malloc((2*n)*sizeof(int)); 

    copia=(int *)malloc((2*n)*sizeof(int));
   
    copia2=(int *)malloc((2*n)*sizeof(int));
  
    for(i=0;i<n;i++){
        fflush(stdin);
        scanf("%d", &m[i]);
    }
    j=0;
    do{
        for(i=0;i<=j;i++){
            copia[i]=m[i];
            copia2[i]=m[i];
        }
        contadors=0;
        contadorq=0;
        contadors=shell(copia,j+1);
        contadorq=quicksort(copia2,0,j,0);
        if(contadorq==contadors) printf("- ");
        else if(contadorq<contadors) printf("Q ");
        else if(contadorq>contadors) printf("S ");
       
        j++;
       
    }while(j<n);
    return 0;

}


int shell(int v[], int n) {
    int gap = 1;
    int x;
    int contador=0;
    while(gap <= n) {
        gap *= 2;
        //printf("gap%d\n",gap);
    }
    
    gap = (gap / 2) - 1;
    //printf("gap%d\n",gap);
    while(gap > 0) {
        int j;
        for (int k = 0; k < gap; k++){
            for (int i = k + gap; i < n; i += gap){
                x = v[i];
                contador++;
                //printf("contador shell copia para x %d\n",contador);
                j = i - gap;
                while(j >= 0 && v[j] > x) {
                    v[j+gap] = v[j];
                    contador++;
                    //printf("contador shell dentro do while copia %d\n",contador);
                    j-=gap;   
                    contador++;
                   // printf("contador shell dentro do while comparacao %d\n",contador);    
                }
                if(j>=0&&v[j]>x){
                    contador++;
                    //printf("contador shell caso saia do while pq v[j]>x %d\n",contador);
                    }
                v[j+gap] = x;
                contador++;
                //printf("contador shell copia %d\n",contador);
               
            }contador++;
        }contador++;
        gap /= 2;
    }
   // printf("contador shell %d",contador);
  //  printf("\n");

    return contador;
}

int quicksort(int v[], int c, int f,int contador){
    
    if (c>=f) {
        return 0;
        } ///caso base
    //fazer o pivo
    int m=(c+f)/2;
    int pivo=v[m];
    contador++;
    //printf("contador quick pivo %d\n",contador);
    int i=c;
    int j=f;
    while(1){
        //contador++;
        //printf("contador quick por entrar no while %d\n",contador);
        while(v[i]<pivo){
            i++;
            contador++;
            //printf("contador quick comparacao v<pivo %d\n",contador);
            
        }//v[i]>=pivo
        contador++;
        //printf("contador quick comparacao v<pivo saiu do while %d\n",contador);
        while(v[j]>pivo){
            j--;
            contador++;
            //printf("contador quick v>pivo %d\n",contador);
            
        }//v[j]<=pivo
        contador++;
        //printf("contador quick v>pivo saiu do while %d\n",contador);
       
        if(j<=i) break;
        int tmp=v[i];
        v[i]=v[j];
        v[j]=tmp;
        contador=contador+3;
        //printf("contador quick troca com 3 copias %d\n",contador);
        i++;
        j--;        
    }
    
    int s1=quicksort(v,c,j,0);
    int s2=quicksort(v,j+1,f,0);
    
    //printf("contador quick %d %d %d\n",contador,s1,s2);
    return (s1+s2+contador);
}