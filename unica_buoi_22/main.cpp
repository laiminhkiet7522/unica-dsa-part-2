#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct Node
{
    int data;
    Node *pPrevious;
    Node *pNext;
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
        cout<<"Danh sach lien ket rong"<<endl;
        return;
    }
    while(p!=NULL)
    {
        cout<<p->data;
        p=p->pNext;
    }
}
Node *createNode(int value)
{
    Node *p = new Node();
    if(p==NULL)
    {
        cout<<"Cap phat bo nho khong thanh cong";
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
        l.pHead=l.pTail=p;
    }
    else
    {
        l.pTail->pNext=p;
        p->pPrevious=l.pTail;
        l.pTail=p;
    }
}
DoubleList taoBigInteger(char *str)
{
    DoubleList l;
    initList(l);
    for(int i=0; i<strlen(str); i++)
    {
        char strTemp[1];
        strTemp[0] = str[i];
        int d = atoi(strTemp);
        insertLast(l, d);
    }
    return l;
}
bool isPrime(int n)
{
    bool check=true;
    if(n<2)
    {
        check = false;
    }
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            check=false;
        }
    }
    return check;
}
DoubleList layDayNguyenTo(DoubleList listGoc)
{
    DoubleList l;
    initList(l);
    Node *p = listGoc.pHead;
    while(p!=NULL)
    {
        int d=p->data;
        bool kiemTra = isPrime(d);
        if(kiemTra)
        {
            insertLast(l,d);
        }
        p=p->pNext;
    }
    return l;
}
int main()
{
    DoubleList l;
    l = taoBigInteger("654513164987987651323211464987941");
    cout<<"Big Integer:\n";
    printList(l);

    DoubleList lPrime;
    lPrime = layDayNguyenTo(l);
    cout<<"\n\nBig Integer - Prime:\n";
    printList(lPrime);

    return 0;
}
