#include<stdio.h>
#include<stdlib.h>

void quicksort(int v[], int c, int f){
    if (c>=f) return; ///caso base
    //fazer o pivo
    int m=(c+f)/2;
    int pivo=v[m];
    int i=c;
    int j=f;
    while(1){
        while(v[i]<pivo){
            i++;
        }//v[i]>=pivo
        while(v[j]>pivo){
            j--;
        }//v[j]<=pivo
        if(j<=i) break;
        int tmp=v[i];
        v[i]=v[j];
        v[j]=tmp;
        i++;
        j--;        
    }
}

void shell(int v[], int n) {
    int gap = 1;
    while(gap <= n) {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    while(gap > 0) {
        int i;
        int j;
        for (int k = 0; k < gap; k++){
            for (int i = k + gap; i < n; i += gap){
                int x = v[i];
                j = i - gap;
                while(j >= 0 && v[j] > x) {
                    v[j+gap] = v[j];
                    j-=gap;
                }
                v[j+gap] = x;
            }
        }
        gap /= 2;
    }
}

int main(){
    int n,*m;
    scanf("%d", &n);
    m=(int *)malloc((2*n)*sizeof(int)); 
    for(int i=0;i<n;i++){
        fflush(stdin);
        scanf("%d", &m[i]);
    }
    quicksort(m,0,n-1);
    for(int i=0;i<n;i++){
        
        printf("%d", m[i]);
    }
    return 0;
}