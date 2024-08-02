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

void addNode(Tree &tree, Node *p)
{
    if(tree.pRoot==NULL)
    {
        tree.pRoot=p;
        return;
    }
    Node *pGoto=tree.pRoot;
    Node *pLocal=NULL;
    while(pGoto!=NULL)
    {
        pLocal=pGoto;
        if(p->data<pGoto->data)
        {
            pGoto=pGoto->pLeft;
        }
        else if(p->data>pGoto->data)
        {
            pGoto=pGoto->pRight
        }
    }
    if(p->data < pLocal->data)
    {
        pLocal->pLeft=p;
    }
    else if(p->data > pLocal->data)
    {
        pLocal->pRight=p;
    }
}
int main()
{
    return 0;
}
