#include<stdio.h>

int main(void)
{
	int R,M,Y;
    double N;
	scanf("%d %d %d",&R,&M,&Y);
	int i;
    double b=1.0;
    for(i=1;i<=Y;i++){
        b*=(1+R/100.0);
    }
    N=M*b;
	printf("%.0f",N);
	return 0;
}
