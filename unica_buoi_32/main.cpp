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
int main()
{
    Stack s;
    initStack(s);
    Node *p1 = initNode(10);
    Node *p2 = initNode(20);
    Node *p3 = initNode(30);
    return 0;
}
