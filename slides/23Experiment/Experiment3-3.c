#include<stdio.h>
int PrimeSum(int a[],int n){
    int i,j,sum=0;
    for(i=0;i<n;i++){
        int IsPrime=1;
        for(j=2;j<a[i];j++){
            if(a[i]%j==0){
                IsPrime=0;
                break;
            }
        }
        if(IsPrime==1&&a[i]!=1){
            sum+=a[i];
        }
    }
    return sum;
}
int main(void){
    int m,i;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        int N,j;
        scanf("%d",&n);
        int arr[n];
        for(j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        printf("%d\n",PrimeSum(arr,n));
    }
    return 0;
}
