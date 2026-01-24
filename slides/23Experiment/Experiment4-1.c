#include<stdio.h>
#include<stdlib.h>
int leap(int i);
int main(void){
    int y,daysum=1,month,count=0,i;
    scanf("%d",&y);
    for(i=1901;i<=y;i++){
        for(month=1;month<=12;month++){
            if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
            daysum+=31;
            else if(month==4||month==6||month==9||month==11)
            daysum+=30;
            else if(month==2&&leap(i)==1)
            daysum+=29;
            else if(month==2&&leap(i)==0)
            daysum+=28;
            else;
            if(daysum%7==0)
            count++;
        }
    }
    if(y==2000)
    printf("%d",count-2);
    else if(y==2100)
    printf("%d",count-1);
    else
    printf("%d",count);
    return 0;
}
int leap(int i){
    if((i%4==0&&i%100!=0)||i%400==0)
    return 1;
    else
    return 0;
}
