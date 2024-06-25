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
int main()
{
    DoubleList l;
    initList(l);
    return 0;
}
