#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *pNext;
};
Node *initNode(int value)
{
    Node *p = new Node();
    p->data=value;
    p->pNext=NULL;
    return p;
}
struct Stack
{
    Node *pTop;
};
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
void pop(Stack &s, int &value)
{
    if(s.pTop==NULL)
    {
        return;
    }
    Node *pDel = s.pTop;
    s.pTop=s.pTop->pNext;
    value=pDel->data;
    delete pDel;
}
void printStack(Stack s)
{
    cout << "Stack = Top < ";
    for(Node* p = s.pTop; p != NULL; p=p->pNext)
    {
        cout << p->data << " ";
    }
    cout << ">" << endl;
}
Node *popNode(Stack &s)
{
    if(s.pTop==NULL)
    {
        return NULL;
    }
    Node *pDel = s.pTop;
    s.pTop=s.pTop->pNext;
    pDel->pNext=NULL;
    return pDel;
}
Node *popTop(Stack &s)
{
    return s.pTop;
}
int main()
{
    Stack s;
    initStack(s);
    Node *p1 = initNode(10);
    Node *p2 = initNode(20);
    Node *p3 = initNode(30);
    Node *p4 = initNode(40);
    Node *p5 = initNode(50);

    push(s,p1);
    push(s,p2);
    push(s,p3);
    push(s,p4);
    push(s,p5);

    printStack(s);

    Node *t=popTop(s);
    cout<<"\nNode tren cung cua Stack la:\n";
    cout<<t<<endl;
    cout<<t->data<<endl;

    int value;
    pop(s, value);
    cout<<"\nPop => "<<value<<endl;
    printStack(s);

    cout<<endl;
    Node *n = popNode(s);
    cout<<n->data<<endl;
    n = popNode(s);
    cout<<n->data<<endl;
    n = popNode(s);
    cout<<n->data<<endl;
    n = popNode(s);
    cout<<n->data;
    n = popNode(s);

    if(n==NULL)
    {
        cout<<"\nStack da rong"<<endl;
    }

    return 0;
}
