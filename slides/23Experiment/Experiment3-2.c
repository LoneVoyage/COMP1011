#include<stdio.h>
int Max(int a[],int n){
    int i,max;
    for(i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
int Min(int a[],int n){
    int i,min;
    for(i=0;i<n;i++){
        if(a[i]<min){
            min=a[i];
        }
    }
    return min;
}
int main(void){
    int n;
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",Max(arr,n)-Min(arr,n));
    return 0;
}
