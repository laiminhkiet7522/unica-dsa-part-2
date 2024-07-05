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
int main()
{
    Stack s;
    initStack(s);
    Node *p1 = initNode(10);
    Node *p2 = initNode(20);
    Node *p3 = initNode(30);

    push(s,p1);
    push(s,p2);
    push(s,p3);

    printStack(s);

    int value;
    pop(s, value);
    cout<<"Pop => "<<value<<endl;
    printStack(s);
    return 0;
}
