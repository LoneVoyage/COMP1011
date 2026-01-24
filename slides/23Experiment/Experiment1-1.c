#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:2023312909\nName:’≈≥Ω“„\nExperiment No.1 - Program No.1");
    char a;
    int b;
    short c;
    float d;
    double e;
    printf("Please input char a:");
    scanf("%c",&a);
    printf("char a=%c,size of char is %d\n",a,sizeof(a));
    printf("Please input int b:");
    scanf("%d",&b);
    printf("int b=%d,size of int is %d\n",b,sizeof(b));
    printf("Please input short c:");
    scanf("%hd",&c);
    printf("short c=%d,size of short is %d\n",c,sizeof(c));
    printf("Please input float d:");
    scanf("%f",&d);
    printf("float d=%f,size of float is %d\n",d,sizeof(d));
    printf("Please input double e:");
    scanf("%lf",&e);
    printf("double e=%f,size of double is %d\n",e,sizeof(e));
    return 0;
}
