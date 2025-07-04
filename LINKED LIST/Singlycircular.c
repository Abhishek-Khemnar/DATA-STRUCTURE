#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node * next;
};
typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;
void Display(PNODE first,PNODE last)
{
    printf("->");
    do
    { 
        printf("| %d | ->",first->data);
        first=first->next;
    }while(first!=last->next);
}
int Count(PNODE first,PNODE last)
{
    int iCount = 0;
    do
    {
        iCount++;
        first=first->next;
    }while(first!=last->next);
    return iCount;
}
void insertFirst(PPNODE first ,PPNODE last, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;

    if(*first==NULL && *last==NULL)
    {
        *first = newn;
        *last = newn;
        newn->next=*first;
    }
    else
    {
      newn->next =*first;
      *first = newn;
      (*last)->next = newn;
    }
}

void insertLast(PPNODE first , PPNODE last , int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    if(*first==NULL&&*last==NULL)
    {
        *first=newn;
        *last=newn;
        newn->next=*first;
    }
    else
    {
       (*last)->next=newn;
       (*last)=newn;
       newn->next=*first;
    }
}
void insertAtpos(PPNODE first , PPNODE last , int no,int pos)
{
    int iCount = Count(*first,*last);
    if(pos<1||pos>iCount+1)
    {
        return;
    }
    else if(pos==1)
    {
        insertFirst(first,last,no);
    }
    else if (pos==iCount+1)
    {
        insertLast(first,last,no);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        PNODE temp = *first;
        for(int i = 1 ; i<=pos-2;i++)
        {
           temp = temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

void Deletefirst(PPNODE first , PPNODE last)
{
    if(*first==NULL && *last==NULL)
    {
        return;
    }
    else 
    {
        PNODE temp = *first;
        *first= temp->next;
        (*last)->next=*first;
        free(temp); 
    }
}
void Deletelast(PPNODE first , PPNODE last)
{
    if(*first==NULL && *last==NULL)
    {
        return;
    }
    else
    {
         PNODE temp  = *first;
         while(temp->next!=*last)
         {
            temp = temp ->next;
         }
         
         free(temp->next);
         *last = temp;
         (*last)->next=*first;
    }
}
void DeleteAtpos(PPNODE first , PPNODE last ,int pos)
{
    int iCount = Count(*first,*last);
    if(pos<1||pos>iCount)
    {
        return;

    }
    else if(pos==1)
    {
        Deletefirst(first,last);
    }
    else if (pos==iCount)
    {
        Deletelast(first,last);
    }
    else
    {
        PNODE temp = *first;
        PNODE target = (*first)->next;
        for(int i = 1 ; i<=pos-2;i++)
        {
           temp = temp->next;
           target=target->next;
        }
        temp->next=target->next;
        free(target);        
    }
}
int main()
{
    PNODE Head =NULL;
    PNODE Tail = NULL;
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
       insertFirst(&Head,&Tail,iNo);
       break;
       case 2:
       printf("ENTER NUMBER YOU WANT TO INSERT:\n");
       scanf("%d",&iNo);
       insertLast(&Head,&Tail,iNo);
       break;
       case 3:
       printf("ENTER NUMBER YOU WANT TO INSERT:\n");
       scanf("%d",&iNo);
       printf("ENTER POSITION :\n");
       scanf("%d",&iPos);
       insertAtpos(&Head,&Tail,iNo,iPos);
       break;
       case 4:
       Deletefirst(&Head,&Tail);
       break;
       case 5:
       Deletelast(&Head,&Tail);
       break;
       case 6:
       printf("ENTER POSITION TO DELETE :\n");
       scanf("%d",&iPos);
       DeleteAtpos(&Head,&Tail,iPos);
       break;
       case 7:
       Display(Head,Tail);
       break;
       case 8:
       iRet=Count(Head,Tail);
       printf("NUMBER OF ELEMENTS IN LINKED LIST : %d",iRet);
       break;
       case 9:
       printf("EXISTING PROGRAM");

    }
    }while (ch!=9);
    return 0;
}
