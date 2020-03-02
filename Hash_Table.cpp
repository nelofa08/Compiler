//HashTable Implementation
#include<bits/stdc++.h>
using namespace std;
struct pair
{
    int value;
    int key;
    struct pair *next;
};
//void search(struct pair[],int size);
void insert(struct pair[],int size);
void display(struct pair[],int size);

void main()
{
    int inp,i,j,temp;
    printf("Enter The Size of the Table::");
    scanf("%d",&inp);
    struct pair hash_table[inp];
    while(j<inp)
    {
        hash_table[j].next=NULL;
        j++;
    }
    j=0;
    while(j<inp)
    {
        hash_table[j].value=-1;
        j++;
    }
    printf("Enter The Element::");
    for(i=0;i<inp;i++)
    {
        scanf("%d",&temp);
        hash_table[temp % inp].value=temp;
        hash_table[temp%inp].key=temp%inp;
    }
    printf("\n");
    display(hash_table,inp);
    insert(hash_table,inp);
    display(hash_table,inp);

    int a=0;
}

void search(struct pair ar[], int size)
{
    int se;
    printf("Enter The Element You Want to Search::");
    scanf("%d",&se);
    if(ar[se%size].value==se)
        printf("Element is at %d",se%size);
    else
        printf("Element Not Found");
}

void insert(struct pair ar[],int size)
{
    int inp;
    printf("Insert Element::");
    scanf("%d",&inp);
    if(ar[inp%size].value==-1)
        ar[inp%size].value=inp;
    else
    {
        struct pair *kvpair;
        kvpair=(struct pair *) malloc(sizeof(struct pair *));
        kvpair->value=inp;
        kvpair->next=NULL;
        ar[inp%size].next= kvpair;
    }
}

void display(struct pair hash_table[], int size)
{
    int i;
    printf("KEY\tVALUE\n")
    for(i=0;i<size;i++)
    {
        printf("%d\t%d\n",hash_table[i].key,hash_table[i].value);
        struct pair *ptr;
        ptr= hash_table[i].next;
        while(ptr!= NULL)
        {
            printf("%d\t",ptr->value);
            ptr= ptr->next;
        }
        printf("\n");

    }
}
