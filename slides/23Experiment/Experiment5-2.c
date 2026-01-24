#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
void sort(int a[],int n)
 {
 	int i;
 	int j;
 	int t;
 	for(i=0;i<n-1;i++){
 		for(j=i+1;j<n;j++){
 			if(a[i]>a[j]){
 				t=a[i];
 				a[i]=a[j];
 				a[j]=t;
 			}
 		}
 	}
 }
 int main()
 {
 	int n;
 	int t;
 	int i;
 	int j;
 	int a[102];
 	int visit[1002];
 	while(scanf("%d",&n)!=EOF){
 		memset(visit,0,sizeof(visit));
 		for(i=0,j=0;i<n;i++){
 			scanf("%d",&t);
 			if(visit[t]==0){
 				a[j++]=t;
 				visit[t]=1;
 			}
 		}
 		sort(a,j);
 		printf("%d\n",j);
 		for(i=0;i<j-1;i++){
 			printf("%d ",a[i]);
 		}
 		printf("%d",a[i]);
 	}
 	 printf(" ");
     return 0;
 }
