#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void Display(PNODE first)
{
     if(first==NULL)
    {
        printf("Stack is Empty\n");
          return;
    }
    while (first!=NULL)
    {
        printf("|%d|\n",first->data);
        first=first->next;
    }
}
void Push(PPNODE first,int no)
{
    PNODE newn  = (PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    if(*first==NULL)
    {
       *first = newn;
    }
    else
    {
        newn->next=*first;
        *first=newn;
    }
}

int Pop(PPNODE first)
{
    if(*first==NULL)
    {
          return 0;
    }
    else {
        PNODE temp = *first;
        *first = (*first)->next;    
       return temp->data;
       free (temp);
    }
}
int Count(PNODE first)
{
    int iCount=0;
    while (first!=NULL)
    {
        iCount++;
        first=first->next;
    }
    return iCount;
}
int main()
{
    PNODE head = NULL;
    int ch = 0;
    int iNo = 0;
    int iRet = 0;
    int iPop = 0;
    do {
    printf("\n");
    printf("------------Menu---------------\n");
    printf("1.PUSH NUMBER\n");
    printf("2.POP NUMBER\n");
    printf("3.SHOW NO OF ELEMENTS\n");
    printf("4.DISPLAY\n");
    printf("5.EXIT\n");
    printf("Enter Your Choice:");
    scanf("%d",&ch);
    if(ch<1 || ch>5)
    {
        printf("INVALID INPUT");
    }
   
    switch (ch)
    {
       case 1:
       printf("Enter number you want to insert");
       scanf("%d",&iNo);
       Push(&head,iNo);
       break;
       case 2 :
       iPop=Pop(&head);
       printf("Element poped from stack:%d",iPop);
       break;
       case 3 :
       iRet = Count(head);
       printf("Number of elements :%d",iRet);
       break;
       case 4:
       Display(head);
       break;
       case 5:
       printf("Exisiting program....");
       break;
    }
    }while(ch!=5);
    return 0;
}
