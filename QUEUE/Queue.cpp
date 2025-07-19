#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node * next;
};
typedef struct Node NODE;
typedef struct Node * PNODE;

class Queuex
{
    private:
    PNODE first;
    int iCount;
    public:
    Queuex()
    {
        first = NULL;
        iCount = 0;
    }

    void Enqueue(int no)
    {
        PNODE newn =  new NODE;
        newn->data = no;
        newn->next = NULL;
        if(first==NULL)
        {
            first = newn;
        }
        else
        {
            PNODE temp = first;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    }
    int Dequeue()
    {
        int ivalue;
          if(first==NULL)
        {
            cout<<"Queue is empty"<<endl;
            return (int)0;
        }   
        else
        {
            PNODE temp = first;
            ivalue = temp->data;
            first = first->next;
            delete temp;  
            iCount--;
            return ivalue;
        }
    }
    void display()
    {
        if(first==NULL)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        PNODE temp = first;
        while(temp !=NULL)
        {
            cout<<"|"<<temp->data<<"|"<<"-";
            temp  = temp ->next;
        }
    }
    int count()
    {
        return iCount;
    }
};
int main()
{
    Queuex ss;
    int ch = 0;
    int iNo = 0;
    int iRet = 0;
    int iPop = 0;
    do {
    cout<<"\n";
    cout<<"------------Menu---------------\n";
    cout<<"1.ENQUEUE NUMBER\n";
    cout<<"2.DEQUEUE NUMBER\n";
    cout<<"3.SHOW NO OF ELEMENTS\n";
    cout<<"4.DISPLAY\n";
    cout<<"5.EXIT\n";
    cout<<"Enter Your Choice:";
    cin>>ch;
    if(ch<1 || ch>5)
    {
        cout<<"INVALID INPUT";
    }
    switch (ch)
    {
       case 1:
       cout<<"Enter number you want to insert";
       cin>>iNo;
       ss.Enqueue(iNo);
       break;
       case 2 :
       iPop=ss.Dequeue();
       cout<<"Element poped from queue:"<<iPop;
       break;
       case 3 :
       iRet = ss.count();
       cout<<"Number of elements :"<<iRet;
       break;
       case 4:
       ss.display();
       break;
       case 5:
       cout<<"Exisiting program....";
       break;
    }
    }while(ch!=5);
    return 0;
}
