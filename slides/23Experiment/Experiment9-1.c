#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list{
	int ID;
	char name[11];
	int income;
	int expense;
}LIST;

void OutputMenu(void);
void Choice(LIST accounting[],int num,double averincome,double averexpense);
int Input(LIST accounting[]);
void Order(LIST accounting[],int num);
void Search(LIST accounting[],int num);
void Aver(LIST accounting[],int num,double*averincome,double*averexpense);
void OverAver(LIST accounting[],int num,double*averexpense);
void Output(LIST accounting[],int num);
void WriteToFile(LIST accounting[],int num);
void ReadFromFile(LIST accounting[],int num);

int main(void){
	LIST accounting[10];
	int num=0;
	double averincome=0,averexpense=0;
	OutputMenu();
    Choice(accounting,num,averincome,averexpense);
	return 0;
}

void OutputMenu(void){
    printf("Number:2023312909\nName:’≈≥Ω“„\nExperiment No.9 - program No.1\n\n");
    printf("1.Input record\n2.Sort and list records in alphabetical order by user name\n");
	printf("3.Search records by user name\n4.Calculate and list per capita income and expenses\n");
	printf("5.List records which have more expenses than per capita expenses\n6.List all records\n");
	printf("7.Write to a file\n8.Read from file\n0.Exit\n");
}

void Choice(LIST accounting[],int num,double averincome,double averexpense){
     while(1){
        printf("  Please enter your choice:");
    	int choice=0;
    	scanf("%d",&choice);
		if(choice!=1&&choice!=0&&num==0){
            printf("No accounting informations!\n");
		}
		else{
            switch(choice){
                case 1:
                    while(!num){
                        num=Input(accounting);
                    }
                    break;
                case 2:
                    Order(accounting,num);
                    break;
                case 3:
                    Search(accounting,num);
                    break;
                case 4:
                    Aver(accounting,num,&averincome,&averexpense);
                    break;
                case 5:
                    OverAver(accounting,num,&averexpense);
                    break;
                case 6:
                    Output(accounting,num);
                    break;
                case 7:
                    WriteToFile(accounting,num);
                    break;
                case 8:
                    ReadFromFile(accounting,num);
                    break;
                case 0:
                    exit(0);
                default:
                    printf("Please input right option!\n");
            }
		}
    }
}

int Input(LIST accounting[]){
	int i,j,num,ret;
	num=0;
	printf("Please input the number of users:");
	scanf("%d",&num);
	if(num<=10){
        for(i=0;i<num;i++){
            accounting[i].ID=0;
            accounting[i].income=0;
            accounting[i].expense=0;
            for(j=0;j<11;j++){
                accounting[i].name[j]='\0';
            }
            ret=scanf("%d %s %d %d",&accounting[i].ID,(char*)&accounting[i].name,&accounting[i].income,&accounting[i].expense);
            if(accounting[i].name[10]!='\0'){
                printf("the length of name is over 10!\n");
                i--;
            }
            if(ret!=4){
                printf("the ID or income or expense must be integer!\n");
                i--;
            }
            if(accounting[i].ID<0||accounting[i].income<0||accounting[i].expense<0){
                printf("the ID or income or expense must be positive number!\n");
                i--;
            }
            if(accounting[i].ID>99999||accounting[i].ID<10000){
                printf("the ID must be 5 digit numbers!\n");
                i--;
            }
        }
        return num;
	}
	else{
        printf("Please input a integer less than 10!\n");
        return 0;
	}
}

void Order(LIST accounting[],int num){
	int i,j;
	LIST temp;
	for(i=0;i<num-1;i++){
		for(j=1;j<num-i;j++){
			if(strcmp(accounting[j].name,accounting[j-1].name)<0){
				temp=accounting[j];
				accounting[j]=accounting[j-1];
				accounting[j-1]=temp;
			}
		}
	}
	printf("ID\tName\tIncome\tExpense\t\n");
	for(i=0;i<num;i++){
		printf("%d\t%s\t%d\t%d\t\n",accounting[i].ID,(char*)accounting[i].name,accounting[i].income,accounting[i].expense);
	}
}

void Search(LIST accounting[],int num){
	int i;
	char name[11]={'\0'};
	printf("Please input the user name:");
	scanf("%s",name);
	if(name[10]!='\0'){
        printf("the length of name is over 10!\n");
	}
	else{
        for(i=0;i<num;i++){
            if(strcmp(name,accounting[i].name)==0){
                printf("ID\tName\tIncome\tExpense\t\n");
                printf("%d\t%s\t%d\t%d\t\n",accounting[i].ID,(char*)accounting[i].name,accounting[i].income,accounting[i].expense);
                break;
            }
        }
        if(i==num){
            printf("Not found!\n");
        }
	}
}

void Aver(LIST accounting[],int num,double*averincome,double*averexpense){
	int i;
	for(i=0;i<num;i++){
		(*averincome)+=accounting[i].income;
		(*averexpense)+=accounting[i].expense;
	}
	(*averincome)/=num;
	(*averexpense)/=num;
	printf("Per capita income:\t%f\t\nPer capita expenses:\t%f\t\n",*averincome,*averexpense);
}

void OverAver(LIST accounting[],int num,double*averexpense){
	int i;
	if((*averexpense)==0){
        for(i=0;i<num;i++){
            (*averexpense)+=accounting[i].expense;
        }
        (*averexpense)/=num;
	}
	printf("ID\tName\tIncome\tExpense\t\n");
	for(i=0;i<num;i++){
		if(accounting[i].expense>(*averexpense)){
			printf("%d\t%s\t%d\t%d\t\n",accounting[i].ID,(char*)accounting[i].name,accounting[i].income,accounting[i].expense);
		}
	}
}

void Output(LIST accounting[],int num){
	int i,j;
	printf("ID\tName\tIncome\tExpense\t\n");
	LIST temp;
	for(i=0;i<num-1;i++){
		for(j=1;j<num-i;j++){
			if(accounting[j].ID<accounting[j-1].ID){
				temp=accounting[j];
				accounting[j]=accounting[j-1];
				accounting[j-1]=temp;
			}
		}
	}
	for(i=0;i<num;i++){
		printf("%d\t%s\t%d\t%d\t\n",accounting[i].ID,(char*)accounting[i].name,accounting[i].income,accounting[i].expense);
	}
}

void WriteToFile(LIST accounting[],int num){
    FILE*fp=NULL;
	if((fp=fopen("E:\\CLanguage\\Experiment\\accounting.txt","a"))==NULL){
        printf("Failure to open accounting.txt!\n");
        exit(0);
	}
	else{
        int i,flag;
        for(i=0;i<num;i++){
            flag=fprintf(fp,"%d %s %d %d\n",accounting[i].ID,accounting[i].name,accounting[i].income,accounting[i].expense);
        }
        if(flag>0){
            printf("Save successfully!\n");
        }
        fclose(fp);
	}
}

void ReadFromFile(LIST accounting[],int num){
    FILE*fp=NULL;
	if((fp=fopen("E:\\CLanguage\\Experiment\\accounting.txt","r"))==NULL){
        printf("Failure to open accounting.txt!\n");
	}
	else{
        int i;
        for(i=0;i<num;i++){
            fscanf(fp,"%d %s %d %d\n",&accounting[i].ID,(char*)accounting[i].name,&accounting[i].income,&accounting[i].expense);
            printf("%d %s %d %d\n",accounting[i].ID,accounting[i].name,accounting[i].income,accounting[i].expense);
        }
        fclose(fp);
	}
}
