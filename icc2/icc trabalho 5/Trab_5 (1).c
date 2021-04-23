#include<stdio.h>
#include<stdlib.h>

void shell(int v[], int n);
void quick(int v[], int c, int f);//recursivo

int contQuick = 0;
int contShell = 0;

int main(){

    int n=1,*m1,*m2,j;
    scanf("%d", &n);
    int i;
    m1=(int *)malloc(n*sizeof(int)); 
    m2=(int *)malloc(n*sizeof(int)); 
    int *m3=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d", &m1[i]);
        
    }
    for(i=1;i<=n;i++){
        for(j=0;j<i;j++){
        m2[j]=m1[j];
        m3[j]=m1[j];
        }
    	contQuick = 0;
		contShell = 0;
        shell(m2,i);
        quick(m3,0,i-1);
        if(contShell==contQuick) printf("- ");
        else if(contShell>contQuick) printf("Q ");
        else if(contShell<contQuick) printf("S ");
	}
    return 0;

}


void shell(int v[], int n) {
    int gap = 1;
    int k,i,j;          
 
    while(gap <= n) {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    while(gap > 0) {
        for ( k = 0; k < gap; k++){
            for (i = k + gap; i < n; i += gap){
            	contShell++;
                int x = v[i];
                j = i - gap;
                if(j>=0) contShell++;
                while(j >= 0 && v[j] > x) {
                    v[j+gap] = v[j];
                    contShell++;
                    j-=gap;
                    if(j>=0) contShell++;
                }
                v[j+gap] = x;
                contShell++;
            }
        }
        gap /= 2;
    }
}

void quick(int v[], int c, int f){
    if(c >= f) return;
    int m = (c+f)/ 2; 
    int pivo = v[m]; 
    contQuick++;
    int i = c;
    int j = f;
    while(1){
    	contQuick++;
        while(v[i]< pivo){
            i++;
            contQuick++;
        } 
        contQuick++;
        while(v[j]> pivo){
            j--;
            contQuick++;
        }
        if(j<=i) {
    		break;
    	}
		contQuick+=3;	
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
        i++;
        j--;
    }
    quick(v,c,j);
    quick(v,j+1,f);
}



