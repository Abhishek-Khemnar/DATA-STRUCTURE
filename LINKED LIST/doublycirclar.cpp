#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node * prev;
    struct Node * next;
};
typedef struct Node NODE;
typedef struct Node* PNODE;

class DoublyCLL
{
    public:
    PNODE first;
    PNODE last;
    int iCount;
    public:
    DoublyCLL()
    {
        first=NULL;
        last =NULL;
        iCount = 0;
    }
    void  Display()
    {
        if(first==NULL &&last==NULL)
        {
            cout<<"Linked list is Empty";
            return;
        }
        PNODE temp = first;
        cout<<"<=>";
        do
        {
           cout <<"|"<<temp->data<<"|"<<"<=>";
           temp=temp->next;
        }while(temp!=last->next);
    }
    void insertFirst(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        if(first==NULL && last==NULL)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn->next=first;
            first=newn;
            newn->next->prev = newn;
        }
        last->next=first;
        first->prev=last;
        iCount++;
    }
    void insertLast(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        if(first==NULL && last==NULL)
        {
            first = newn;
            last=newn;
        }
        else
        {
             last->next=newn;
             newn->prev=last;
             last=newn;
        }
        last->next=first;
        first->prev=last;
        iCount++;
    }
    void insertAtpos(int no , int pos)
    {
        if(pos<1||pos>iCount+1)
        {
            return;
        }
        else if(pos==1)
        {
            insertFirst(no);
        }
        else if(pos==iCount+1)
        {
            insertLast(no);
        }
        else
        {
            PNODE newn = new NODE;
            newn->data=no;
            newn->next=NULL;
            newn->prev=NULL;
            PNODE temp = first;
            for(int i = 1; i<=pos-2;i++)
            {
                temp = temp->next;
            }
            newn->next=temp->next;
            temp->next=newn;
            newn->prev=temp;
            newn->next->prev=newn;
            iCount++;
        }
    }
    void deleteFirst()
    {
        if(first==NULL && last==NULL)
        {
            cout<<"Linklist is empty";
            return;
        }
        else if(first->next==NULL)
        {
            delete first;
            first =  NULL;
            last = NULL;
        }
        else
        {
            PNODE  temp = first;
            first=first->next;
            delete temp; 
             last->next=first;
             first->prev=last;
        }
        iCount--;
    }
    void deleteLast()
    {
        if(first==NULL && last==NULL)
        {
            cout<<"Linklist is empty";
            return;
        }
        else if(first->next==NULL)
        {
            delete first;
            first = NULL;
            last = NULL;
        }
        else
        {
            PNODE temp = first;
            while(temp->next!=last)
            {
                temp = temp->next;
            }
            delete temp->next;
            last=temp;
            last->next=first;
            first->prev=last;
        }
        iCount--;
    }
    void  deleteAtpos(int pos)
    {
        if(first==NULL&&last==NULL)
        {
            cout<<"Linklist is empty";
            return;
        }
        if(pos<1||pos>iCount)
        {
            return;
        }
        else if(pos==1)
        {
            deleteFirst();
        }
        else if (pos==iCount)
        {
            deleteLast();
        }
        else
        {
            PNODE temp = first;
            PNODE target = first->next;
            for(int i = 1 ; i<=pos-2 ; i++)
            {
                temp=temp->next;
                target = target->next;
            }
            temp->next=target->next;
            target->next->prev=temp;
            delete target;
            iCount--;
        }
    }
    int Count()
    {
        return iCount;
    }
};
int main()
{
    DoublyCLL sobj;
    int iRet = 0;
    int iNo = 0;
    int iPos = 0;
    int ch = 0;
    do{
    cout<<"\n";
    cout<<"------------MENU------------------\n";
    cout<<"1.INSERT AT FIRST POSITION\n";
    cout<<"2.INSERT AT LAST POSITON\n";
    cout<<"3.INSERT AT ANY POSITION\n";
    cout<<"4.DELETE AT FIRST POSITION\n";
    cout<<"5.DELETE AT LAST POSITON\n";
    cout<<"6.DELETE AT ANY POSITION\n";
    cout<<"7.DISPLAY \n";
    cout<<"8.COUNT\n";
    cout<<"9.EXIT";
    cout<<"\n";

    cout<<"PLEASE ENTER YOUR CHOICE \n";
    cin>>ch;

    if(ch<1||ch>9)
    {
        cout<<"Invalid Input";
    }
    switch (ch)
    {
       case 1:
       cout<<"ENTER NUMBER YOU WANT TO INSERT:\n";
       cin>>iNo;
       sobj.insertFirst(iNo);
       break;
       case 2:
       cout<<"ENTER NUMBER YOU WANT TO INSERT:\n";
       cin>>iNo;
       sobj.insertLast(iNo);
       break;
       case 3:
       cout<<"ENTER NUMBER YOU WANT TO INSERT:\n";
       cin>>iNo;
       cout<<"ENTER POSITION :\n";
       cin>>iPos;
       sobj.insertAtpos(iNo,iPos);
       break;
       case 4:
       sobj.deleteFirst();
       break;
       case 5:
       sobj.deleteLast();
       break;
       case 6:
       cout<<"ENTER POSITION TO DELETE :\n";
       cin>>iPos;
       sobj.deleteAtpos(iPos);
       break;
       case 7:
       sobj.Display();
       break;
       case 8:
       iRet=sobj.Count();
       cout<<"NUMBER OF ELEMENTS IN LINKED LIST :" <<iRet;
       break;
       case 9:
       printf("EXISTING PROGRAM");
    }
    }while (ch!=9);
    return 0;
}
