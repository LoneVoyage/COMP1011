#include<stdio.h>
#define N 40
int main(void){
struct student{
    char ID[10];
    int score[3];
    int sum;
    float aver;
	};
	int n,i,j;
    struct student stu[n];
    printf("Input the total number of the students(n<40):\n");
    printf("Input student¡¯s ID and score as: MT  EN  PH:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %d %d %d",&stu[i].ID,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
        stu[i].aver=stu[i].sum/3.0;
    }
    int sumscore[3]={0};
    float averscore[3];
    for(i=0;i<3;i++){
        for(j=0;j<n;j++){
            sumscore[i]+=stu[j].score[i];
        }
        averscore[i]=sumscore[i]/(float)n;
    }
    printf("Counting Result:\nStudent¡¯s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
    for(i=0;i<n;i++){
        printf("%12s\t%4d\t%4d\t%4d\t%4d\t%5.1f\n",stu[i].ID,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].aver);
    }
    printf("SumofCourse \t%4d\t%4d\t%4d\t",sumscore[0],sumscore[1],sumscore[2]);
    printf("\nAverofCourse\t%4.1f\t%4.1f\t%4.1f\t",averscore[0],averscore[1],averscore[2]);
    return 0;
}
