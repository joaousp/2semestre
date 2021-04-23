#include<stdio.h>
#include<math.h>



float distancia(float x1, float y1, float x2, float y2){
    float d=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return d;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(float arr[], float arr2[], int l, int m, int r)
{
    int i, j, k;
    int n1 = (int)m - l + 1;
    int n2 = (int)r - m;
 
    /* create temp arrays */
    float L[n1], R[n2];
    float L2[n1], R2[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
        L2[i] = arr2[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
        R2[j] = arr2[m + 1 + j];
    }
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            arr2[k]=L2[i];
            i++;
        }
        else {
            arr[k] = R[j];
            arr2[k]=R2[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        arr2[k]=L2[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        arr2[k]=R2[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(float arr[],   float l, float r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m =(int) l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
/*
float distancia_rec(float x[], float y[], int p, int r){
    if(r<=p+1){
        //resolver
    }
    else{
        int q=(p+r)/2;
        float de=distancia_rec(x,y,p,q);
        float dd=distancia_rec(x,y,q+1,r);

        return combine();
    }
}

float funcao(float x[], float y[], int n){
    mergesort(x,y,0,n-1);
    return distancia_rec(x,y,0,n-1);
}
*/
int main(){
    int n;
    scanf("%d",&n);
    float x[n],y[n];
    int i=0;  
    float dist;
    float dx,dy;
    for( i=0;i<n;i++){
        scanf("%f %f",&x[i],&y[i]);
    }
    

    int k,m;
    mergeSort(x,y,0,n-1);
    for(i=1;i<n;i++){
        dist=x[i]-x[i-1];
        if(dist<dx){
            dx=dist;
            k=i;
        }
    }
    mergesort(y,x,0,n-1);
    for(i=1;i<n;i++){
        dist=y[i]-y[i-1];
        if(dist<dy){
            dy=dist;
            m=i;
        }
    }
    printf("%.6f", distancia(x[k],y[k],x[m],y[m]));
    //codigo bruto
    /*
    for(i=0;i<n;i++){
        for(j=1;j<n;j++){
            if(i!=j)dist=distancia(x[i],y[i],x[j],y[j]);
            if(dist<d){
                d=dist;
            }
        }
    }
   printf("%f",d);
   */
    

}