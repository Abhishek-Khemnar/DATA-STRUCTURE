#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
void Display(PNODE first , PNODE last)
{
    printf("<=>");
    do
    {
        printf("|%d|<=>",first->data);
        first=first->next;
    } while (first!=last->next);
}
int Count(PNODE first , PNODE last)
{
    int iCount = 0;
    do
    {
        iCount++;
        first=first->next;
    } while (first!=last->next);
    return iCount;
}
void insertFirst(PPNODE first , PPNODE last , int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if(*first==NULL && *last == NULL)
    {
        *first=newn;
        *last = newn;
    }
    else
    {
        newn->next= *first;
        *first = newn;
        newn->next->prev=newn;
    }

    (*last)->next = *first;
    (*first)->prev=*last;
}

void insertLast(PPNODE first , PPNODE last , int iNo)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;
    
    if(*first==NULL && *last == NULL)
    {
        *first=newn;
        *last = newn;   
    }
    else
    {
        (*last)->next = newn;
        newn->prev=*last;
        *last = newn;
    }
      (*last)->next = *first;
      (*first)->prev=*last;
}

void insertAtpos(PPNODE first , PPNODE last , int iNo , int pos)
{
    int icount = Count(*first,*last);
    if(pos<1||pos>icount+1)
    {
        return;
    }
    if(pos==1)
    {
      insertFirst(first,last,iNo);
    }
    else if(pos==icount+1)
    {
       insertLast(first,last,iNo);
    }
    else
    {
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

     PNODE temp = NULL;
     temp=*first;

     for(int iCnt = 1 ; iCnt<=pos-2 ; iCnt++)
     {
        temp=temp->next;
     }

     newn->next=temp->next;
     newn->next->prev=newn;
     temp->next=newn;
     newn->prev=temp;
     }

}

void DeleteFirst(PPNODE first , PPNODE last)
{
    if(*first==NULL && *last==NULL)
    {
         return ;
    }
    else
    {
        *first=(*first)->next;
        free((*last)->next);
        (*last)->next=*first;
        (*first)->prev=*last;
    }

}
void DeleteLast(PPNODE first , PPNODE last )
{
    if(*first==NULL && *last==NULL)
    {
         return;
    }
    else
    {
        PNODE temp = NULL;
        temp = *first;

        while (temp->next!=*last)
        {
            temp=temp->next;
        }
        free(temp->next);
        *last=temp;
        (*last)->next=*first;
        (*first)->prev=*last;
    }
}

void DeleteAtpos(PPNODE first , PPNODE last, int pos)
{
    int icount = Count(*first,*last);
    if(pos<1||pos>icount+1)
    {
        return;
    }
    if(pos==1)
    {
      DeleteFirst(first , last);
    }
    else if(pos==icount)
    {
       DeleteLast(first,last);
    }
    else
    {
       PNODE temp = *first;
       PNODE target = (*first)->next;
       for(int iCnt = 1; iCnt<=pos-2 ; iCnt++)
       {
         temp = temp ->next;
         target = target ->next;
       }

       temp->next=target->next;
       target->next->prev=temp;
       free(target);
    }
}

int main()
{
    PNODE Head = NULL;
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
       DeleteFirst(&Head,&Tail);
       break;
       case 5:
       DeleteLast(&Head,&Tail);
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
    


    return 0;
}
