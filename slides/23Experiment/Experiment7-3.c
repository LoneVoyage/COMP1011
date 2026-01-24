#include<stdio.h>
#define N 80
int main(void){
	char a[N],b[N];
	gets(a);
	gets(b);
	int i,j,flag=0;
	for(i=0;a[i]!='\0';i++){
		if(b[0]==a[i]){
			for(j=0;b[j]!='\0';j++){
				if(b[j]!=a[i+j]){
					break;
				}
			}
			if(b[j]=='\0'){
				flag=1;
			}
            break;
        }
	}
	if(flag){
		printf("Yes");
	}else{
		printf("No");
	}
	return 0;
}
