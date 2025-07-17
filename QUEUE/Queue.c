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
      printf("queue is empty");

    }

    while (first!=NULL)
    {
        printf("-|%d|-",first->data);
        first = first->next;
    }
}
int Count(PNODE first)
{
    int iCount = 0;
    while (first!=NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}
void Enqueue(PPNODE first , int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    if(*first==NULL)
    {
        *first = newn;
    }
    else
    {
        PNODE temp = *first;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
         temp->next=newn;
    }
}


int Dequeue(PPNODE first)
{
    int value = 0;
    if(*first==NULL)
    {
      printf("unable to remove\n");
      return -1;
    }
    else
    {
        PNODE temp = *first;
        value = temp->data;
        *first = (*first)->next;
        free(temp);
         return value;
    }
   
}
int main()
{
    PNODE head = NULL;
    int ch = 0;
    int iNo = 0;
    int iRet = 0;
    int ibret = 0;
    do {
    printf("\n");
    printf("------------Menu---------------\n");
    printf("1.ENQUEUE NUMBER\n");
    printf("2.DEQUEUE NUMBER\n");
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
       Enqueue(&head,iNo);
       break;
       case 2 :
       ibret=Dequeue(&head);
       printf("Element dequeue from queue:%d",ibret);
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
