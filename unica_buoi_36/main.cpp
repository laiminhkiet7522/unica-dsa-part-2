#include <iostream>

using namespace std;

struct Device
{
    int id;
    char name[255];
};
struct Node
{
    Device data;
    Node *pNext;
};
struct Stack
{
    Node *pTop;
};
Node *initNode(Device d)
{
    Node *p = new Node();
    if(p==NULL)
    {
        cout<<"Cap phat bo nho khong thanh cong"<<endl;
        return NULL;
    }
    p->data=d;
    p->pNext=NULL;
    return p;
}
void initStack(Stack &s)
{
    s.pTop=NULL;
}
void push(Stack &s, Node *p)
{
    if(s.pTop==NULL)
    {
        s.pTop=p;
    }
    else
    {
        p->pNext=s.pTop;
        s.pTop=p;
    }
}
void pop(Stack &s, Device &d)
{
    if(s.pTop==NULL)
    {
        return;
    }
    Node *pDel = s.pTop;
    s.pTop=s.pTop->pNext;
    d=pDel->data;
    delete pDel;
}
void printStack(Stack s)
{
    if(s.pTop==NULL)
    {
        cout<<"Stack rong!"<<endl;
        return;
    }
    cout << "Stack:\n";
    for(Node* p = s.pTop; p != NULL; p=p->pNext)
    {
        cout << p->data.id << " ";
        cout<<p->data.name<<"\n";
    }
}
bool isEmptyStack(Stack s)
{
    return s.pTop==NULL;
}
int main()
{
    Stack s;
    initStack(s);

    Device d1 = {1,"May tinh"};
    Node *p1 = initNode(d1);
    Device d2 = {2,"Sach"};
    Node *p2 = initNode(d2);
    Device d3 = {3,"Dien thoai"};
    Node *p3 = initNode(d3);
    push(s,p1);
    push(s,p2);
    push(s,p3);
    printStack(s);

    Device d4 = {};
    Device d5 = {};
    Device d6 = {};
    pop(s,d4);
    pop(s,d5);
    pop(s,d6);
    cout<<"Pop:\n";
    cout<<d4.id<<" ";
    cout<<d4.name<<endl;
    cout<<d5.id<<" ";
    cout<<d5.name<<endl;
    cout<<d6.id<<" ";
    cout<<d6.name<<endl;
    printStack(s);

    return 0;
}
