#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

Node *initNode(int value)
{
    Node *p = new Node();
    p->data=value;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}

struct Tree
{
    Node *pRoot;
};

void initTree(Tree &t)
{
    t.pRoot=NULL;
}

int main()
{
    return 0;
}
