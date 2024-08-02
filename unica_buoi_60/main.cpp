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
            pGoto=pGoto->pRight;
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

void inOrderLNR(Node *p)
{
    if(p!=NULL)
    {
        inOrderLNR(p->pLeft);
        cout<<p->data<<"\t";
        inOrderLNR(p->pRight);
    }
}
int main()
{
    Tree tree;
    initTree(tree);
    Node *p1 = initNode(10);
    Node *p2 = initNode(20);
    Node *p3 = initNode(5);
    Node *p4 = initNode(8);
    Node *p5 = initNode(30);
    Node *p6 = initNode(15);
    addNode(tree, p1);
    addNode(tree, p2);
    addNode(tree, p3);
    addNode(tree, p4);
    addNode(tree, p5);
    addNode(tree, p6);
    inOrderLNR(p1);
    return 0;
}
