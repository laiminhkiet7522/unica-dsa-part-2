#include <iostream>

using namespace std;

struct Node
{
    double data;
    Node *pNext;
};
Node *initNode(double value)
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
void printQueue(Queue q)
{
    cout<<"Queue Q = Front<\t";
    for(Node *p=q.pFront; p!=NULL; p=p->pNext)
    {
        cout<<p->data<<"\t";
    }
    cout<<">Rear"<<endl;
}
void enQueue(Queue &q, double value)
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
double deQueue(Queue &q)
{
    if(q.pFront==NULL)
    {
        return NULL;
    }
    Node *pDel = q.pFront;
    q.pFront=q.pFront->pNext;
    double value = pDel->data;
    delete pDel;

    return value;
}
int main()
{
    Queue q;
    initQueue(q);
    enQueue(q,1.1);
    enQueue(q,2.5);
    enQueue(q,3.1);
    enQueue(q,4.5);
    enQueue(q,5.1);

    cout<<"ENQUEUE:\n";
    printQueue(q);

    cout<<"\nDEQUEUE:";
    double q1 = deQueue(q);
    double q2 = deQueue(q);
    double q3 = deQueue(q);
    cout<<"\nq1 = "<<q1;
    cout<<"\nq2 = "<<q2;
    cout<<"\nq3 = "<<q3;

    cout<<"\n\nENQUEUE:\n";
    printQueue(q);
    return 0;
}
