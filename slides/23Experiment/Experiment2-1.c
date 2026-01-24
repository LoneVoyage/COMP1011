#include<stdio.h>
#define P 3.14
#define N 20000

int main(void){
	int h,r,cnt;
	double v;
	scanf("%d %d",&h,&r);
	v=P*r*r*h;
	cnt=(int)(N/v);
	printf("%d",cnt+1);
	return 0;
}
