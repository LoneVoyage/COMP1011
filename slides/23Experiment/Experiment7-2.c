#include<stdio.h>
int Kablek(int a,int count);
int main(void){
	int a,c,count=1;
	scanf("%d",&a);
	while(a!=6174){
		a=Kablek(a,count);
		count++;
	}
	return 0;
}
int Kablek(int a,int count){
	int b[4],i,j,temp,max,min,c;
	b[0]=a/1000;
	b[1]=a%1000/100;
	b[2]=a%100/10;
	b[3]=a%10;
	for(i=0;i<3;i++){
		for(j=1;j<4-i;j++){
			if(b[j]<b[j-1]){
				temp=b[j];
				b[j]=b[j-1];
				b[j-1]=temp;
			}
		}
	}
	max=b[0]+b[1]*10+b[2]*100+b[3]*1000;
	min=b[3]+b[2]*10+b[1]*100+b[0]*1000;
	c=max-min;
	printf("[%d]:%d-%d=%d\n",count,max,min,c);
	return c;
}
