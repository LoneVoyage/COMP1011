#include<stdio.h>
long long int Pell(int i);
int main(void){
    int group,data;
    long long int a;
    scanf("%d",&group);
    for(int i=1;i<=group;i++){
        scanf("%d",&data);
        a=Pell(data);
        printf("%d\n",a%32767);
    }
    return 0;
}
long long int Pell(int i){
    int a;
    if(i==1)
    a=1;
    else if(i==2)
    a=2;
    else
    a=2*Pell(i-1)+Pell(i-2);
    return a;
}
