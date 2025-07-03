#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node * next;
   struct Node * prev;
};
typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;
void Display(PNODE first)
{
    printf("NULL <=>");
    while (first!=NULL)
    {   
        printf(" | %d | <=> ",first->data);
        first=first->next;
    }
    printf("NULL");
}
int Count(PNODE first)
{
    int iCount = 0;
    while(first!=NULL)
    {
        iCount++;
        first=first->next;
    }
    return iCount;
}
void insertFirst(PPNODE first,int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data= iNo;
    newn->next= NULL;
    newn->prev= NULL;
    if(*first==NULL)
    {
        *first = newn;
        newn->next=NULL;
    }
    else
    {
        newn->next=*first;
        *first=newn;
        newn->next->prev=newn;
    }
}
void insertLast(PPNODE first , int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data= iNo;
    newn->next= NULL;
    newn->prev= NULL;
    if(*first==NULL)
    {
        *first = newn;
        newn->next=NULL;
    }
    else
    {
        PNODE temp = *first;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
}

void insertAtpos(PPNODE first, int iNo , int pos)
{
    int iCount = Count(*first);
    if(pos<1||pos>iCount+1)
    {
        return;
    }
    if(pos==1)
    {
      insertFirst(first,iNo);
    }
    else if(pos==iCount+1)
    {
      insertLast(first,iNo);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn->data= iNo;
        newn->next= NULL;
        newn->prev= NULL;
        PNODE temp = *first;
        for(int iCnt = 1 ; iCnt<=pos-2;iCnt++)
        {
            temp = temp ->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
    } 
}
void DeleteFirst(PPNODE first)
{
    if(*first==NULL)
    {
         return;
    }
    else if((*first)->next==NULL)
    {
        free(*first);
        *first=NULL;
    }
    else
    {
        PNODE temp = *first;
        *first=temp->next;
        free(temp);
    }
}
void DeleteLast(PPNODE first)
{
    if(*first==NULL)
    {
         return;
    }
    else if((*first)->next==NULL)
    {
        free(*first);
        *first=NULL;
    }
    else
    {
        PNODE temp = *first;
        while (temp->next->next!=NULL)
        {
            temp = temp ->next;
        }
        free(temp->next);
        temp->next=NULL;     
    }
}
void DeleteAtpos(PPNODE first , int pos)
{
    int iCount = Count(*first);
    if(pos<1||pos>iCount)
    {
        return;    
    }
    if(pos==1)
    {
        DeleteFirst(first);    
    }
    else if(pos==iCount)
    {
        DeleteLast(first);
    }
    else
    {
        PNODE temp = *first;
        PNODE target = (*first)->next;
        for(int iCnt = 1 ; iCnt <=pos-2 ; iCnt++)
        {
            temp = temp->next;
            target = target->next;
        }
        temp->next=target->next;
        target->next->prev=temp;
        free(target);
    }
}
int main()
{
    PNODE Head = NULL;
    int iRet = 0;
    int iNo = 0;
    int iPos = 0;
    int ch = 0;
    do{
    printf("\n");
    printf("------------MENU------------------\n");
    printf("1.INSERT AT FIRST POSITION\n");
    printf("2.INSERT AT LAST POSITON\n");
    printf("3.INSERT AT ANY POSITION\n");
    printf("4.DELETE AT FIRST POSITION\n");
    printf("5.DELETE AT LAST POSITON\n");
    printf("6.DELETE AT ANY POSITION\n");
    printf("7.DISPLAY \n");
    printf("8.COUNT\n");
    printf("9.EXIT");
    printf("\n");

    printf("PLEASE ENTER YOUR CHOICE \n");
    scanf("%d",&ch);

    if(ch<1||ch>9)
    {
        printf("INVALID INPUT");
    }
    switch (ch)
    {
       case 1:
       printf("ENTER NUMBER YOU WANT TO INSERT:\n");
       scanf("%d",&iNo);
       insertFirst(&Head,iNo);
       break;
       case 2:
       printf("ENTER NUMBER YOU WANT TO INSERT:\n");
       scanf("%d",&iNo);
       insertLast(&Head,iNo);
       break;
       case 3:
       printf("ENTER NUMBER YOU WANT TO INSERT:\n");
       scanf("%d",&iNo);
       printf("ENTER POSITION :\n");
       scanf("%d",&iPos);
       insertAtpos(&Head,iNo,iPos);
       break;
       case 4:
       DeleteFirst(&Head);
       break;
       case 5:
       DeleteLast(&Head);
       break;
       case 6:
       printf("ENTER POSITION TO DELETE :\n");
       scanf("%d",&iPos);
       DeleteAtpos(&Head,iPos);
       break;
       case 7:
       Display(Head);
       break;
       case 8:
       iRet=Count(Head);
       printf("NUMBER OF ELEMENTS IN LINKED LIST : %d",iRet);
       break;
       case 9:
       printf("EXISTING PROGRAM");

    }
    }while (ch!=9);
    return 0;
}
