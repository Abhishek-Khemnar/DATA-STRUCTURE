#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node * next;
};
typedef struct Node NODE;
typedef struct Node * PNODE;

class stackx
{
    private:
    PNODE first;
    int iCount;
    public:
    stackx()
    {
        first = NULL;
        iCount = 0;
    }

    void Push(int no)
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
            newn->next = first;
            first = newn;
        }
        iCount++;
    }
    int Pop()
    {
        int ivalue;
          if(first==NULL)
        {
            cout<<"stack is empty"<<endl;
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
            cout<<"stack is empty"<<endl;
            return;
        }
        PNODE temp = first;
        while(temp !=NULL)
        {
            cout<<"|"<<temp->data<<"|"<<endl;
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
    stackx ss;
    int ch = 0;
    int iNo = 0;
    int iRet = 0;
    int iPop = 0;
    do {
    cout<<"\n";
    cout<<"------------Menu---------------\n";
    cout<<"1.PUSH NUMBER\n";
    cout<<"2.POP NUMBER\n";
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
       ss.Push(iNo);
       break;
       case 2 :
       iPop=ss.Pop();
       cout<<"Element poped from stack:"<<iPop;
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
