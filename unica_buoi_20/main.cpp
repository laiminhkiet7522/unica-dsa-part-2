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
void removeNode(DoubleList &l, int value)
{
    Node *pDel = l.pHead;
    if(pDel==NULL)
    {
        cout<<"\nDanh sach dang rong"<<endl;
        return;
    }
    Node *pPre = NULL;
    while(pDel!=NULL)
    {
        if(pDel->data==value)
        {
            break;
        }
        pPre=pDel;
        pDel=pDel->pNext;
    }
    if(pDel==NULL)
    {
        cout<<"\nKhong tim thay gia tri de xoa"<<endl;
        return;
    }
    else
    {
        if(pDel==l.pHead)
        {
            l.pHead=l.pHead->pNext;
            pDel->pNext=NULL;
            l.pHead->pPrevious=NULL;
        }
        else if(pDel->pNext==NULL)
        {
            l.pTail=pPre;
            pDel->pPrevious=NULL;
            pPre->pNext=NULL;
        }
        else
        {
            pPre->pNext=pDel->pNext;
            pDel->pNext->pPrevious=pPre;
            pDel->pPrevious=NULL;
            pDel->pNext=NULL;
        }
        delete pDel;
        pDel=NULL;
    }
}
Node *searchNode(DoubleList l, int value)
{
    Node *p = l.pHead;
    while(p!=NULL)
    {
        if(p->data==value)
        {
            break;
        }
        p=p->pNext;
    }
    return p;
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

    removeNode(l, 99);
    removeNode(l, 88);
    removeNode(l, 77);

    cout<<"\n\nDanh sach lien ket doi sau khi xoa cac node la:\n";
    printList(l);

    int x;
    cout<<"\n\nNhap vao gia tri node can tim: ";
    cin>>x;
    Node *pSearch = searchNode(l, x);
    if(pSearch!=NULL)
    {
        cout<<"\nTim thay node co gia tri la "<<x<<" trong danh sach"<<endl;
    }
    else
    {
        cout<<"\nKhong tim thay node co gia tri la "<<x<<" trong danh sach"<<endl;
    }
    return 0;
}
