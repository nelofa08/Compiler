#include<bits/stdc++.h>
using namespace std;

struct table
{
    char var[10];
    int value;
};

struct table sym_tbl[20];
int i,j,n;
void create();
int search(char variable[],int n);
void display();

int main()
{
    int choice,result=0;
    char v[20];

    do
    {
        printf("\nEnter your choice:\n1.Create\n2.Search\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                printf("Enter the variable to be searched:: ");
                scanf("%s",&v);
                result=search(v,n);
                if(result==0)
                    printf("The variable does not belong to the table\n");
                else
                    printf("Location of variable is %d",result);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
        }
    }
    while(choice!=4);
        int getch();
}


void create()
{
    printf("Enter the number of Entries:: ");
    scanf("%d",&n);
    printf("Enter the Variable & Value::\n");
    for(i=1;i<=n;i++)
    {
        scanf("%s %d",sym_tbl[i].var,&sym_tbl[i].value);
        label_check:
        if(sym_tbl[i].var[0]>='0' && sym_tbl[i].var[0]<='9')
        {
            printf("The variable should start with an alphabet\nEnter the correct variable name\n");
            scanf("%s%d",sym_tbl[i].var,&sym_tbl[i].value);
            goto label_check;
        }
    }
    printf("The table after creation is:: \n");
    display();
}

int search(char variable[],int n)
{
    int counter;
    for(i=1;i<=n;i++)
    {
        if(strcmp(sym_tbl[i].var,variable)==0)
        {
            counter=1;
            break;
        }
    }
    if(counter==1)
        return i;
    else
        return 0;
}


void display()
{
    printf("VARIABLE\tVALUE\n");
    for(i=1;i<=n;i++)
    printf("%s\t\t%d\n",sym_tbl[i].var,sym_tbl[i].value);
}
