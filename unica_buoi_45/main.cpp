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
    if(p==NULL)
    {
        cout<<"Cap phat bo nho khong thanh cong";
        return NULL;
    }
    p->data=value;
    p->pNext=NULL;
    return p;
}
struct Queue
{
    Node *pFront;
    Node *pRear;
};
void initQueue(Queue &q)
{
    q.pFront=q.pRear=NULL;
}
int main()
{
    Queue q;
    initQueue(q);
    return 0;
}
