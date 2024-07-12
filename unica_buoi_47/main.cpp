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
void enQueue(Queue &q, int value)
{
    Node *p = initNode(value);
    if(q.pFront==NULL)
    {
        q.pFront=q.pRear=p;
    }
    else
    {
        q.pRear->pNext=p;
        q.pRear=p;
    }
}
int deQueue(Queue &q, int &value)
{
    if(q.pFront==NULL)
    {
        return NULL;
    }
    Node *pDel = q.pFront;
    q.pFront=q.pFront->pNext;
    value = pDel->data;
    delete pDel;

    return value;
}
void printQueue(Queue q)
{
    cout<<"Queue Q = Front<\t";
    for(Node *p=q.pFront; p!=NULL; p=p->pNext)
    {
        cout<<p->data<<"\t";
    }
    cout<<">Rear"<<endl;
}
int main()
{
    Queue q;
    initQueue(q);
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);

    cout<<"ENQUEUE:\n";
    printQueue(q);

    cout<<"\nDEQUEUE:";
    int q1, q2, q3;
    deQueue(q,q1);
    deQueue(q,q2);
    deQueue(q,q3);
    cout<<"\nq1 = "<<q1;
    cout<<"\nq2 = "<<q2;
    cout<<"\nq3 = "<<q3;

    cout<<"\n\nENQUEUE:\n";
    printQueue(q);

    return 0;
}
