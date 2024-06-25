#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *pNext;
    Node *pPrevious;
};
struct DoubleList
{
    Node *pHead;
    Node *pTail;
};
void initList(DoubleList &l)
{
    l.pHead=l.pTail=NULL;
}
void printList(DoubleList l)
{
    Node *p = l.pHead;
    if(p==NULL)
    {
        cout<<"\nDanh sach rong"<<endl;
        return;
    }
    while(p!=NULL)
    {
        cout<<p->data<<"\t";
        p=p->pNext;
    }
}
int sizeOfList(DoubleList l)
{
    Node *p = l.pHead;
    int nSize=0;
    while(p!=NULL)
    {
        nSize++;
        p=p->pNext;
    }
    return nSize;
}
int main()
{
    DoubleList l;
    initList(l);
    return 0;
}
