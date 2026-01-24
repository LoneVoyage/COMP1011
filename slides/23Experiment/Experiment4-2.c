#include<stdio.h>
int IsPrime(int i);
int main(void){
    int c,d,i,sum=0,prime1,prime2;
    scanf("%d,%d",&c,&d);
    for(i=c;i<=d;i++){
        if(i+2<=d){
            prime1=IsPrime(i);
            prime2=IsPrime(i+2);
            if(prime1==1&&prime2==1){
                printf("(%d,%d)",i,i+2);
                sum++;
            }
        }
    }
    printf("\n");
    printf("%d",sum);
    return 0;
}
int IsPrime(int i){
    int Prime=1,j;
		for(j=2;j<i;j++){
            if(i%j==0){
                Prime=0;
                break;
            }
		}
	return Prime;
}
