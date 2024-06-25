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
Node *createNode(int value)
{
    Node *p = new Node();
    if(p==NULL)
    {
        cout<<"Khong the cap phat bo nho"<<endl;
        return NULL;
    }
    p->data=value;
    p->pNext=NULL;
    p->pPrevious=NULL;
    return p;
}
void insertFirst(DoubleList &l, int value)
{
    Node *p = createNode(value);
    if(l.pHead==NULL)
    {
        l.pHead=l.pTail=p;
    }
    else
    {
        p->pNext=l.pHead;
        l.pHead->pPrevious=p;
        l.pHead=p;
    }
}
void insertLast(DoubleList &l, int value)
{
    Node *p = createNode(value);
    if(l.pTail==NULL)
    {
        l.pHead=l.pTail=NULL;
    }
    else
    {
        l.pTail->pNext=p;
        p->pPrevious=l.pTail;
        l.pTail=p;
    }
}
void insertMid(DoubleList &l, int pos, int value)
{
    if(pos<0 || pos >= sizeOfList(l))
    {
        cout<<"Vi tri them khong hop le"<<endl;
        return;
    }
    else if(pos==0)
    {
        insertFirst(l,value);
    }
    else if(pos==sizeOfList(l)-1)
    {
        insertLast(l,value);
    }
    else
    {
        Node *p = createNode(value);
        Node *pIns = l.pHead;
        Node *pPre = NULL;
        int i=0;
        while(pIns!=NULL)
        {
            if(i==pos)
            {
                break;
            }
            pPre=pIns;
            pIns=pIns->pNext;
            i++;
        }
        p->pNext=pIns;
        p->pPrevious=pPre;
        pPre->pNext=p;
        pIns->pPrevious=p;
    }
}
int main()
{
    DoubleList l;
    initList(l);

    insertFirst(l,5);
    insertFirst(l,4);
    insertFirst(l,3);
    insertFirst(l,2);
    insertFirst(l,1);

    insertLast(l,10);
    insertLast(l,20);
    insertLast(l,30);
    insertLast(l,40);
    insertLast(l,50);

    insertMid(l, 0, 99);
    insertMid(l, 10, 88);
    insertMid(l, 5, 77);

    cout<<"Danh sach lien ket doi la:\n";
    printList(l);

    return 0;
}
