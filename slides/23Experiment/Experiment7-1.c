#include<stdio.h>
#define N 50
void reversearr(int a[],int count);
void addarr(int a[],int b[],int sum[]);
void printsum(int sum[]);
int main(void){
	int a[N]={0},b[N]={0},sum[N+1]={0},count1=0,count2=0;
	char a0[N]={0},b0[N]={0};
	scanf("%s\n%s",a0,b0);
	int i;
	for(i=0;a0[i]!='\0';i++){
		a[i]=a0[i]-48;
		count1++;
	}
	for(i=0;b0[i]!='\0';i++){
		b[i]=b0[i]-48;
		count2++;
	}
	reversearr(a,count1);
	reversearr(b,count2);
	addarr(a,b,sum);
	printsum(sum);
	return 0;
}
int readarr(int a[]){

}
void reversearr(int a[],int count){
	int i;
	for(i=0;i<count/2;i++){
	    int temp;
        temp=a[i];
        a[i]=a[count-1-i];
        a[count-1-i]=temp;
	}
}
void addarr(int a[],int b[],int sum[]){
	int i;
	for(i=0;i<N;i++){
		sum[i]+=a[i]+b[i];
		sum[i+1]=sum[i]/10;
		sum[i]%=10;
	}
}
void printsum(int sum[]){
	int i,flag=0;
	for(i=N;i>=0;i--){
		if(sum[i]){
			flag=1;
		}
		if(flag){
			printf("%d",sum[i]);
		}
	}
}
